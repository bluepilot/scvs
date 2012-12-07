/*	Rule: dblfree	Test File: dblfree_e02.c
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
 * Rule: [dblfree]
 * Description: diagnostic is required because realloc may free c_str1 
 *              when it returns NULL, resulting in c_str1 being freed twice
 * Diagnostic: required on line 88
 * Additional Test Files: None
 * Command-line Options: None
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *w_realloc(char *, size_t);

int error_condition = 0;

int main(void) {
  char *reallocedstring; 
  char *teststring = "This is a test";
  char *s1;
  char *s = (char *)malloc(sizeof(teststring));

  if(s != NULL) {
     if ((s1 = w_realloc(s, sizeof(teststring))) && !error_condition) {
        free(s1);
        s1 = NULL;
     }
  }
  
  return EXIT_SUCCESS;
}

char *w_realloc(char *c_str1, size_t size) {
  char *c_str2 = (char *)realloc(c_str1, size);
  if (c_str2 == NULL) {
    error_condition = 1;
    free(c_str1);  // diagnostic required
  } else {
    if((memset(c_str2, 'w', size)) != c_str2) {
       fprintf(stderr,"memset error in %s\n", __func__);
       error_condition = 2;
    }
  }
  return c_str2;
}

