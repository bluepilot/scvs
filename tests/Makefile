# Secure Coding Validation Suite	Makefile
#
# Copyright (c) 2012 Carnegie Mellon University.
# All Rights Reserved.
#  
# Redistribution and use in source and binary forms, with or without 
# modification, are permitted provided that the following conditions
# are met:
#  
# 1. Redistributions of source code must retain the above copyright 
#    notice, this list of conditions and the following acknowledgments 
#    and disclaimers.
#  
# 2. Redistributions in binary form must reproduce the above copyright 
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the 
#    distribution.
#  
# 3. The names “Carnegie Mellon University,” "CERT” and/or “Software
#    Engineering Institute" shall not be used to endorse or promote 
#    products derived from this software without prior written 
#    permission. For written permission, please contact 
#    permission@sei.cmu.edu.
#  
# 4. Products derived from this software may not be called "CERT" 
#    nor may "CERT" appear in their names without prior written 
#    permission of permission@sei.cmu.edu.
#  
# 5. Redistributions of any form whatsoever must retain the following 
#    acknowledgment:
#  
# "This product includes software developed by CERT with funding and 
#  support from the Department of Defense under Contract No. FA 
#  8721-05-C-0003.  The U.S. Government's rights to use, modify,
#  reproduce, release, perform, display, or disclose this material are
#  restricted by the Rights in Technical Data-Noncommercial Items
#  clauses (DFAR 252-227.7013 and DFAR 252-227.7013 Alternate I contained always
#  in the foregoing identified contract.
#  
#  THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY “AS IS” AND
#  CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER
#  EXPRESS OR IMPLIED, AS TO ANY MATTER, AND ALL SUCH WARRANTIES,
#  INCLUDING WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE, ARE EXPRESSLY DISCLAIMED.  WITHOUT LIMITING THE GENERALITY OF
#  THE FOREGOING, CARNEGIE MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY
#  OF ANY KIND RELATING TO EXCLUSIVITY, INFORMATIONAL CONTENT, ERROR-FREE
#  OPERATION, RESULTS TO BE OBTAINED FROM USE, FREEDOM FROM PATENT,
#  TRADEMARK AND COPYRIGHT INFRINGEMENT AND/OR FREEDOM FROM THEFT OF TRADE
#  SECRETS.”
# 
CONFIGFILES= configuration.* test.log

ifeq ("$(INCLUDE)", "")
 INCLUDE="-I$(SCVS_BASE)/include -I./"
endif

ifeq ("$(CC)", "")
 CC=gcc
endif

ifeq ("$(CFLAGS)", "")
 CFLAGS="-std=c99"
endif

vpath = %.h $(INCLUDE)

all: ptrcomp funcaddr padcomp intptrconv alignconv filecpy funcdecl nullref diverr addrescape signconv accfree swtchdflt fileclose liberr libptr invptr dblfree usrfmt inverrno ioileave strmod accsig libmod intoflow chrsgnext restrict xfree uninitref ptrobj taintstrcpy sizeofptr taintnoproto taintformatio xfilepos libuse chreof resident invfmtstr taintsink boolasgn asyncsig argcomp sigcall syscall

.PHONY: all

ptrcomp: always
	(cd ./ptrcomp; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

accfree: always
	(cd ./accfree; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

accsig: always
	(cd ./accsig; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

boolasgn: always
	(cd ./boolasgn; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

asyncsig: always
	(cd ./asyncsig; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

argcomp: always
	(cd ./argcomp; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

sigcall: always
	(cd ./sigcall; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

syscall: always
	(cd ./syscall; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

padcomp: always
	(cd ./padcomp; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

intptrconv: always
	(cd ./intptrconv; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

alignconv: always
	(cd ./alignconv; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

filecpy: always
	(cd ./filecpy; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

funcdecl: always
	(cd ./funcdecl; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

nullref: always
	(cd ./nullref; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

addrescape: always
	(cd ./addrescape; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

signconv: always
	(cd ./signconv; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)
 
swtchdflt: always
	(cd ./swtchdflt; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

fileclose: always
	(cd ./fileclose; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

liberr: always
	(cd ./liberr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

libptr: always
	(cd ./libptr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

invptr: always
	(cd ./invptr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

dblfree: always
	(cd ./dblfree; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

usrfmt: always
	(cd ./usrfmt; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

inverrno: always
	(cd ./inverrno; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

diverr: always
	(cd ./diverr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

ioileave: always
	(cd ./ioileave; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

strmod: always
	(cd ./strmod; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

libmod: always
	(cd ./libmod; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

intoflow: always
	(cd ./intoflow; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

nonnullstr: always
	(cd ./nonnullstr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

chrsgnext: always
	(cd ./chrsgnext; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

restrict: always
	(cd ./restrict; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

xfree: always
	(cd ./xfree; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

uninitref: always
	(cd ./uninitref; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

ptrobj: always
	(cd ./ptrobj; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

taintstrcpy: always
	(cd ./taintstrcpy; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

sizeofptr: always
	(cd ./sizeofptr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

taintnoproto: always
	(cd ./taintnoproto; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

taintformatio: always
	(cd ./taintformatio; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

xfilepos: always
	(cd ./xfilepos; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

libuse: always
	(cd ./libuse; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

chreof: always
	(cd ./chreof; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

resident: always
	(echo Making resident;\
	cd ./resident; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

invfmtstr: always
	(cd ./invfmtstr; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)

taintsink: always
	(cd ./taintsink; $(MAKE) $(MFLAGS) \
	CC="$(CC)" \
	CFLAGS="$(CFLAGS)" \
	INCLUDE="$(INCLUDE)" all)


clobber: clean
	(cd ./ptrcomp; $(MAKE) $(MFLAGS) clean)
	(cd ./accfree; $(MAKE) $(MFLAGS) clean)
	(cd ./accsig; $(MAKE) $(MFLAGS) clean)
	(cd ./boolasgn; $(MAKE) $(MFLAGS) clean)
	(cd ./asyncsig; $(MAKE) $(MFLAGS) clean)
	(cd ./argcomp; $(MAKE) $(MFLAGS) clean)
	(cd ./sigcall; $(MAKE) $(MFLAGS) clean)
	(cd ./syscall; $(MAKE) $(MFLAGS) clean)
	(cd ./padcomp; $(MAKE) $(MFLAGS) clean)
	(cd ./intptrconv; $(MAKE) $(MFLAGS) clean)
	(cd ./alignconv; $(MAKE) $(MFLAGS) clean)
	(cd ./filecpy; $(MAKE) $(MFLAGS) clean)
	(cd ./funcdecl; $(MAKE) $(MFLAGS) clean)
	(cd ./nullref; $(MAKE) $(MFLAGS) clean)
	(cd ./addrescape; $(MAKE) $(MFLAGS) clean)
	(cd ./signconv; $(MAKE) $(MFLAGS) clean)
	(cd ./swtchdflt; $(MAKE) $(MFLAGS) clean)
	(cd ./fileclose; $(MAKE) $(MFLAGS) clean)
	(cd ./liberr; $(MAKE) $(MFLAGS) clean)
	(cd ./libptr; $(MAKE) $(MFLAGS) clean)
	(cd ./invptr; $(MAKE) $(MFLAGS) clean)
	(cd ./dblfree; $(MAKE) $(MFLAGS) clean)
	(cd ./usrfmt; $(MAKE) $(MFLAGS) clean)
	(cd ./inverrno; $(MAKE) $(MFLAGS) clean)
	(cd ./diverr; $(MAKE) $(MFLAGS) clean)
	(cd ./ioileave; $(MAKE) $(MFLAGS) clean)
	(cd ./strmod; $(MAKE) $(MFLAGS) clean)
	(cd ./libmod; $(MAKE) $(MFLAGS) clean)
	(cd ./intoflow; $(MAKE) $(MFLAGS) clean)
	(cd ./nonnullstr; $(MAKE) $(MFLAGS) clean)
	(cd ./chrsgnext; $(MAKE) $(MFLAGS) clean)
	(cd ./restrict; $(MAKE) $(MFLAGS) clean)
	(cd ./xfree; $(MAKE) $(MFLAGS) clean)
	(cd ./uninitref; $(MAKE) $(MFLAGS) clean)
	(cd ./ptrobj; $(MAKE) $(MFLAGS) clean)
	(cd ./taintstrcpy; $(MAKE) $(MFLAGS) clean)
	(cd ./sizeofptr; $(MAKE) $(MFLAGS) clean)
	(cd ./taintnoproto; $(MAKE) $(MFLAGS) clean)
	(cd ./taintformatio; $(MAKE) $(MFLAGS) clean)
	(cd ./xfilepos; $(MAKE) $(MFLAGS) clean)
	(cd ./libuse; $(MAKE) $(MFLAGS) clean)
	(cd ./chreof; $(MAKE) $(MFLAGS) clean)
	(cd ./resident; $(MAKE) $(MFLAGS) clean)
	(cd ./invfmtstr; $(MAKE) $(MFLAGS) clean)
	(cd ./taintsink; $(MAKE) $(MFLAGS) clean)

clean:
	@rm -f $(CONFIGFILES)

testlist:
	@./make_testlist.sh

always:
