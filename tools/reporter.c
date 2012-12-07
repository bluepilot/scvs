//	tools	reporter.c
//
// Copyright and License information can be found in the file
// license.txt or license.html
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>
#include "reporter.h" 

void check_4_diagnostic(char *, test_information *);
void print_results(test_information *, _Bool);
void help(void);
void print_header(void);
int parse_arguments(int, char **);
int init_configuration(void);
_Bool get_config_set(int);
_Bool get_config_value(int, char *);
test_information *find_entry(char *, test_information *);

int main(int argc, char **argv) {
  int i = 0;
  int dirs = 0;
  int match = 0;
  test_information *d = test_list;
  config *configuration;
  FILE *dir_list = 0; 
  char buffer[MAX_LINE];
  char outfile[MAX_LINE];
  static char rule_list[MAX_LINE];
  static char dir_entry[25];

  if(parse_arguments(argc, argv) == 1) {
    if((init_configuration()) > 0 ) {
      if(get_config_set(M_SINGLE)) {	// last test run tested a single rule
        if(get_config_value(M_SINGLE, dir_entry)) {
          sprintf(outfile, "%s/%s.out", dir_entry, dir_entry); 
          dirs++;
          while((d = find_entry(dir_entry, d)) != NULL) { 
            check_4_diagnostic(outfile, d); 
            match++;
            d->processed = true;
            *d++;
          }
        }
      } else if (get_config_value(M_RULE_LIST, rule_list)) {
        if ((dir_list = fopen(rule_list, "r")) != NULL) {	
          while(((fgets(buffer, MAX_LINE, dir_list)) == buffer)) {
            if(buffer[0] != '#') {
              i = 0;
              while(buffer[i] != '\n' && buffer[i] != '\r') {
                dir_entry[i] = buffer[i];
                i++;
              }
              dir_entry[i] = '\0';
              d = test_list;	// set to start of the test information table 
              dirs++;	        // count rules
              while((d = find_entry(dir_entry, d)) != NULL) { 
                match++;
                sprintf(outfile, "%s/%s.out", dir_entry, dir_entry);
                check_4_diagnostic(outfile, d); 
                d->processed = true;
                *d++;
              }
            } else {
              memset(dir_entry, '\0', 25);
              memset(buffer, '\0', MAX_LINE);
            }
          }
          fclose(dir_list);
        } else {
          fprintf(stderr, "Could not open %s, in %s\n", rule_list, __func__);
          exit(EXIT_FAILURE);
        }
      }
      d = test_list;
      print_results(d,verbose);
      printf("\nRules tested:  %.3i\nTest Files:    %.3i\n", dirs, match);
    }
  }
  return(EXIT_SUCCESS);
}

void check_4_diagnostic(char *outfile, test_information *d) {
  FILE *ofile = 0;
  char *big_buffer = malloc(LONG_LINE);
  char *c = NULL;

  if((ofile = fopen(outfile, "r")) != NULL) {
    if(big_buffer != NULL) {
      if(debug) {
        printf("Rule %s, test file %s debug information:\n", 
                d->dir, d->testfile);
      }
      while(((fgets(big_buffer, LONG_LINE, ofile)) == big_buffer) 
              && !feof(ofile)) {
        if((c = strstr(big_buffer, d->testfile)) != NULL) {
          while(*c != (char) delimiter && *c != '\0' && *c != '\n') {
            *c++;
          }
          if(*c == (char) delimiter) {
            *c++;
            int i = atoi(c);
            if(i == d->line) {
              if(debug) {
                printf("\tDiagnostic found for %s at line %i\n", 
                      d->testfile, d->line);
              }
              d->pf++;
            } else {
              if(debug) {
                printf("\tDiagnostic not expected for %s at line %i - %i\n", 
                      d->testfile, i, d->line);
              }
              d->extras++;
            }
          }
        }
      }
      free(big_buffer);
    } else {
      fprintf(stderr, "Could not malloc %i bytes in %s\n", LONG_LINE, __func__);
    }
    fclose(ofile);
  } else {
    fprintf(stderr, "Could not open %s in %s\n", outfile, __func__);
  }  
}

void print_results(test_information *d, _Bool verbose) {
  int total_extras = 0;
  int passed = 0;
  int passedwith = 0;
  int failed = 0;
  int failedwith = 0;
  int nonreq = 0;
  int nonreqwith = 0;
  int rulespassed = 0;
  int rulesfailed = 0;
  size_t dir_size = 0;
  char *current_rule = (char *)0;
  _Bool rule_status = true;

  if(d->processed == true) {
    current_rule = d->dir;
  }

  while(d->line != -1) {
    if (d->processed == true) {
      if (d->pf > 0 && d->line > 0) {
        if(verbose) {
          printf("\t%s %s", d->testfile, "PASSED");
          if(d->extras > 0) {
            printf(", with %i extra diagnostics.\n", d->extras);
          } else {
            printf(".\n");
          }
        }
        passed++;
          if(d->extras != 0) {
            total_extras += d->extras;
            passedwith++;
          }
        } else if (d->line == 0) {
          if(verbose) {
            printf("\t%s %s no diagnostic require",d->testfile, "PASSED");
            if(d->extras > 0) {
              printf(", got %i diagnostics.\n", d->extras);
            } else {
              printf(".\n");
            }
          }
          nonreq++;
          passed++;
          if(d->extras != 0) {
            total_extras += d->extras;
            nonreqwith++;
          }
        } else if (d->pf == false && d->line > 0) {
           if(verbose) {
             printf("\t%s FAILED", d->testfile);
             if(d->extras > 0) {
               printf(", with %i extra diagnostics.\n", d->extras);
             } else {
               printf(".\n");
             }
           }
           failed++;
           rule_status = false;
           if(d->extras) {
             total_extras += d->extras;
             failedwith++;
           }
        }
      }
      d++;
      if(current_rule) {
        dir_size = strlen(current_rule);
        if(((strncmp(d->dir, current_rule, dir_size)) != 0) || 
             d->line == -1) {
          if(rule_status == false) {
            rulesfailed++;
            if(verbose) {
              printf("Rule: %s ***  FAILED ***\n", current_rule);
            }
          } else {
            if(verbose) {
              printf("Rule: %s - PASSED\n", current_rule);
            }
            rulespassed++;
          }
          if(d->processed == true) {
            current_rule = d->dir;
          } else {
            current_rule = (char *)0;
          }
          rule_status = true;
        }
     } else {
       if(d->processed == true) {
         current_rule = d->dir;
       }
     }
  }
  printf("\n");
  print_header();
  printf("\n");
  printf("Totals:\n");
  printf("\trules passed: %.3i\n", rulespassed);
  printf("\trules failed: %.3i\n\n", rulesfailed);
  printf("\ttests passed: %.3i\n", passed);
  printf("\ttests failed: %.3i\n\n", failed);
  if(passedwith) {
    printf("\ttests passed with extra messages: %i\n", passedwith);
  }
  if(nonreq) {
    printf("\ttests passed with no diagnostic needed and no diagnostic: %i\n", 
            nonreq);
  }
  if(nonreqwith) {
    printf("\ttests passed with no diagnostic needed with a diagnostic: %i\n\n",
            nonreqwith);
  }
  if(failedwith) {
    printf("\ttests failed with diagnostic: %i\n\n", failedwith);
  }
  if(total_extras) {
    printf("\textra diagnostics: %i\n", total_extras);
  }
}

int parse_arguments(int ac, char **av) {
  int n = 0;
  char *p = 0;
  int return_value = 1;

  --ac;  // set up the argument count

  while(++n <= ac) {
    p = av[n];
    if (*p == '-') {
      switch(*++p) {
        case 'v':
          verbose = true;
          break;
        case 'd':	// print extra information
          debug = true;
          verbose = true;
          break;
        case 's':	// single rule
          single_rule = true;
	  break;
        case 'h':	// help
          help();
          break;
        default:
          {
          char local_buffer[MAX_LINE];
          fprintf(stderr, "\t-%c - not valid parameter\n", *p);
          return_value = -1;
          }
      }
    }
  }
  return return_value;
}

void help(void) {
}

int init_configuration(void) {
  int ret = 0;
  int i = 0;
  int j = 0;
  FILE *fp = fopen(configuration_file, "r");
  char *buffer = (char *) malloc(MAX_LINE);
  char *p;
  size_t st;

  if(fp != NULL) {
    if(buffer != NULL) {
       while(((fgets(buffer, MAX_LINE, fp)) == buffer) &&
              !feof(fp)) {
          if(buffer[0] != '#') {	// process lines  
            for (i = 0; configuration[i].key != -1; i++) {
               st = strlen(configuration[i].keyword);
               if((strncmp(buffer, configuration[i].keyword, st)) == 0) {
                   if((p = strstr(buffer, "=")) != NULL) {
                     *p++;
                     for (j = 0; 
                        (*p != '\n' && *p != '\0' && j < MAX_LINE); 
                        *p++, j++) {
                       configuration[i].value[j] = *p;
                     }
                     configuration[i].value[j] = '\0';
                     configuration[i].set = true;
                     ret++;
                 }
              }
            }
          }
       }
       free(buffer);
    } else {
      fprintf(stderr, "Could not malloc %d bytes in %s\n", MAX_LINE, __func__);
    }
    fclose(fp);
  } else {
    fprintf(stderr, "Could not open configuration file %s, in %s\n","configuration_file", __func__);
  }
  return ret;
}

_Bool get_config_set(int key) {
  int i = 0;
  _Bool ret = false;

  for(i = 0; configuration[i].key != -1; i++) {
    if(configuration[i].key == key) {
      ret = configuration[i].set;
    }
  }
  return ret;
}

_Bool get_config_value(int key, char *value) {
  int i = 0;
  _Bool ret = false;
   
  for (i = 0; configuration[i].key != -1; i++) {
    if(configuration[i].key == key) {
      size_t value_len = strlen(configuration[i].value) + 1; 
      if((strncpy(value, configuration[i].value, value_len)) == value) {
        ret = true;
      }
    }
  }
  return ret;
}

test_information *find_entry(char dir[], test_information *d) {
  test_information *ret = NULL;
  _Bool found = false;

  while(d->line != -1 && found == false) {
    if(dir[0] != '\0') {
      if(strncmp(dir, d->dir, strlen(dir)) == 0) {
        if(d->processed != true) {
          ret = d;
	  found = true;
        }
      }
    }
    *d++;
  }
  return ret;
}

void print_header(void) {
  int i = 0;

  for(i = 0; configuration[i].key != -1; i++) {
    switch(configuration[i].key) {
      case M_DATE:	printf("Date: %s\n", configuration[i].value);
	break;
      case M_TESTER:	printf("Tester: %s\n", configuration[i].value);
	break;
      case M_TEST_DIRECTORY:	printf("Test home directory: %s\n",
                                        configuration[i].value);
        break;
      case M_TEST_SCRIPT:	printf("Test script: %s\n",
                                        configuration[i].value);
        break;
      case M_SINGLE: if(configuration[i].set == true) {
                  printf("Single rule tested: %s\n", configuration[i].value);
                } 
        break;
      case M_RULE_LIST: if(configuration[i].set == true) {
                  printf("Rule list file: %s\n", configuration[i].value);
                }
	break;
      case M_VERSION:	printf("Test Suite Version: %s\n", configuration[i].value);
        break;
      default:
	break;
    }
  }
}
