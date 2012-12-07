/*	Rule: usrfmt	Test File: usrfmt_e04.c
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
 * Rule: [usrfmt]
 * Description: diagnostic is not required because the argument fmt is 
 *              constrained to be one of the elements of the formats array, 
 *              which is not controlled by the user
 * Diagnostic: None
 * Additional Test Files: None
 * Command-line Options: None
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int error_condition;
enum int_tag { I_char, I_shrt, I_int, I_long, I_llong };
static const char *const formats[] = { "%hhi\n", "%hi\n", "%i\n", "%li\n", "%lli\n" };

static int fmtintv(enum int_tag, const char *, va_list);
int format_integer(enum int_tag, ...);

int main(void) {
  error_condition = 0;
  enum int_tag it;
  for (it = I_char; it <= I_llong; it++) {
    if(format_integer(I_int, it) == -1) {
      error_condition++;
    }
  }
  if(error_condition != 0) {
    return EXIT_FAILURE;
  } else {
    return EXIT_SUCCESS;
  }
}

static int fmtintv(enum int_tag tag, const char *fmt, va_list va) {
  return vfprintf(stdout, fmt, va);
}
 
int format_integer(enum int_tag tag, ...) {
  va_list va;
  int n;
  if (tag < I_char || I_llong < tag)
    return -1;
  va_start(va, tag);
  n = fmtintv(tag, formats[tag], va);
  va_end(va);
  return n;
}

