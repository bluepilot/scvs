/*	Rule: nonnullstr	Test File: nonnullstr_e03.c
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
 * Rule: [ptrcomp]
 * Description: diagnostic is not required because cur_msg will always
 *              be null-terminated when passed to wcslen()
 * Diagnostic: None
 */

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

size_t lessen_memory_usage(wchar_t *, size_t);
wchar_t *cur_msg = NULL;
size_t cur_msg_size = 1024;

int main(void) {
 cur_msg = (wchar_t *)malloc(cur_msg_size);
 if(cur_msg != NULL) {
   if((lessen_memory_usage(cur_msg, (cur_msg_size / 2 + 1))) != 0) {
      if(cur_msg) {
        free(cur_msg);
      } 
    } else {
     return EXIT_FAILURE;
    }
 } else {
   fprintf(stderr, "Could not malloc memmory in %s\n", __func__);
   return EXIT_FAILURE;
 }
 return EXIT_SUCCESS;
}

size_t lessen_memory_usage(wchar_t *ws, size_t temp_size) {
 size_t cur_msg_len = 0;
 wchar_t *temp;

 if (ws != NULL) {
  if(temp_size) {
   temp = realloc(ws, temp_size * sizeof(wchar_t));
   // temp & cur_msg might not be null-terminated
   if (temp == NULL) {
    fprintf(stderr,"could not resize memory in %s\n", __func__);
   } else {
    cur_msg = temp;
    cur_msg[ temp_size - 1] = L'\0'; // cur_msg now properly null-terminated
    cur_msg_size = temp_size;
    cur_msg_len = wcslen(cur_msg); // no diagnostic is required
   }
  }
 }
 return cur_msg_len;
}

