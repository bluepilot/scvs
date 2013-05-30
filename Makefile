# Secure Coding Validation Suite	Makefile
#
# Copyright and License information can be found in the file
# license.txt or license.html
#
VERSION= Secure Code Validate Suite, Version 0.1B, May 2013

all: version install

version: always
	@echo
	@echo $(VERSION)
	@echo

install: always
	echo $(VERSION)
	(cd tools; $(MAKE) install)

testlist:
	(cd tools; $(MAKE) testlist)

clean: clear

clear:
	(cd tools; $(MAKE) clean)
	(cd tests; $(MAKE) clean)

clobber: clear
	(cd tests; $(MAKE) clobber)

always:
