/*	Rule: intptrconv	Test File: intptrconv_ex1.c
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
 * Rule: [intptrconv]
 * Description: null pointer can be converted to an integer; it takes on 
 *              the value 0. Likewise, a 0 integer can be converted to a 
 *              pointer; it becomes the null pointer
 * Diagnostic: None
 * Additional Test Files: None
 * Command-line Options: None
 */

#include <stdlib.h>
#include <stdio.h>

int test_0_roundtrip(void);
int test_null_roundtrip(void);

int main(void) {

  if(test_0_roundtrip() == 1) {
    printf("0 to pointer and back - successfull\n");
  } else  {
    printf("0 to pointer and back - failure\n");
  }

  if(test_null_roundtrip() == 0) {
    printf("null to int and back - successfull\n");
  } else {
    printf("null to int and back - failure\n");
  }

  return EXIT_SUCCESS;
}

int test_0_roundtrip() {
  int i = 0;
  int *iptr = (void *)i;
  if (NULL == iptr) {
    return 1;
  } else {
    return 0;
  }
}

int test_null_roundtrip() {
  int *tptr = NULL;
  int i = (int)tptr;  

  return i;
}
