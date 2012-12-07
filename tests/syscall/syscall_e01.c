/*	Rule: syscall	Test File: syscall_e01.c
 *
 * Copyright (c) 2012 Carnegie Mellon University.
 * All Rights Reserved.
 *  
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions
 * are met:
 *  
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following acknowledgments 
 *    and disclaimers.
 *  
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the 
 *    distribution.
 *  
 * 3. The names “Carnegie Mellon University,” "CERT” and/or “Software
 *    Engineering Institute" shall not be used to endorse or promote 
 *    products derived from this software without prior written 
 *    permission. For written permission, please contact 
 *    permission@sei.cmu.edu.
 *  
 * 4. Products derived from this software may not be called "CERT" 
 *    nor may "CERT" appear in their names without prior written 
 *    permission of permission@sei.cmu.edu.
 *  
 * 5. Redistributions of any form whatsoever must retain the following 
 *    acknowledgment:
 *  
 * "This product includes software developed by CERT with funding and 
 *  support from the Department of Defense under Contract No. FA 
 *  8721-05-C-0003.  The U.S. Government's rights to use, modify,
 *  reproduce, release, perform, display, or disclose this material are
 *  restricted by the Rights in Technical Data-Noncommercial Items
 *  clauses (DFAR 252-227.7013 and DFAR 252-227.7013 Alternate I contained
 *  in the foregoing identified contract.
 *  
 *  THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY “AS IS” AND
 *  CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
 *  EXPRESS OR IMPLIED, AS TO ANY MATTER, AND ALL SUCH WARRANTIES,
 *  INCLUDING WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE, ARE EXPRESSLY DISCLAIMED.  WITHOUT LIMITING THE GENERALITY OF
 *  THE FOREGOING, CARNEGIE MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY
 *  OF ANY KIND RELATING TO EXCLUSIVITY, INFORMATIONAL CONTENT, ERROR-FREE
 *  OPERATION, RESULTS TO BE OBTAINED FROM USE, FREEDOM FROM PATENT,
 *  TRADEMARK AND COPYRIGHT INFRINGEMENT AND/OR FREEDOM FROM THEFT OF TRADE
 *  SECRETS.”
 * 
 *
 * Rule: [syscall]
 * Description: diagnostic is required because a string consisting of any_cmd 
 *              and the tainted value stored in input is copied into cmdbuf 
 *              and then passed as an argument to the Standard Libary 
 *              function system()to execute
 * Diagnostic: required on line 104
 * Additional Test Files: None
 * Command-line Options: None
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE 80

int exe_cmd(char *);

int main(void) {
  int ret = 1;
  char *s = (char *)malloc(MAX_LINE);
  if(s != NULL) {
    printf("Enter parameters: ");
    if ((fgets(s, (MAX_LINE -1), stdin)) == s) {
      if (exe_cmd(s) == 1) {
        free(s);
      } else {
        fprintf(stderr, "Could not execute %s, in %s\n", s, __func__);
        ret = 0;
      }
    } else {
      fprintf(stderr, "Entry error in %s\n", __func__);
      ret = 0;
    }
  } else {
    fprintf(stderr, "Could not malloc memory in %s\n", __func__);
    ret = 0;
  }

  return (ret == 1 ? EXIT_SUCCESS : EXIT_FAILURE);
}

int exe_cmd(char *input) {
  char cmdbuf[512];
  int len_wanted = snprintf(cmdbuf, sizeof(cmdbuf), "ls '%s'", input);
  int ret = 1;
  
  if (len_wanted >= sizeof(cmdbuf)) {
    perror("Input too long");
    ret = -1;
  } else if (len_wanted < 0) {
    perror("Encoding error");
    ret = -2;
  } else if (system(cmdbuf) == -1) { // diagnostic required
    perror("Error executing input");
    ret = -3;
  }

  return ret;
}

