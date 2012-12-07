//  include	scvs_include.h
//
// Copyright and License information can be found in the file
// license.txt or license.html
//
// Description: header for the Secure Coding Validation Suite, contains macros
//              and definitions needed for testing.  GET_TAINTED_STRING and
//		GET_TAINTED_INTEGER are defined in TS 17961
//

#ifndef SCVS_INCLUDE_H
#define SCVS_INCLUDE_H

#include <string.h>
#include <limits.h>
#include <errno.h>

#define TESTFILE "scvs_testfile.txt"

#define GET_TAINTED_STRING(buf, buf_size) \
  do {                                    \
    const char *taint = getenv("TAINT");  \
    if(taint == 0) {                      \
      exit(1);                            \
    }                                     \
    size_t taint_size = strlen(taint) + 1;\
    if (taint_size > buf_size) {          \
      exit(1);                            \
    }                                     \
    strncpy(buf, taint, taint_size);      \
  } while (0)

#define GET_TAINTED_INTEGER(type, val)    \
 do {					  \
    const char *taint = getenv("TAINT");  \
    if (taint == 0) {                     \
      exit(1);				  \
    }                                     \
    errno = 0;                            \
    long tmp = strtol(taint, 0, 10);      \
    if ((type)-1 < 0) {                   \
	if (tmp < INT_MIN)                \
		tmp = INT_MIN;            \
	else if (tmp > INT_MAX)           \
		tmp = INT_MAX;            \
    }                                     \
    val = tmp;                            \
  } while (0)

#endif
