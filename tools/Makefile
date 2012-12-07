#	tools	Makefile
#
# Copyright and License information can be found in the file
# license.txt or license.html
#
VERSION=Secure Code Validate Suite, Version 0.0B, October 2012
TFILES=../tests/default_cmd ../tests/cov_cmds ../tests/gcc_cmds ../tests/kw_cmds ../tests/test_driver.sh ../tests/reporter ./reporter

clean:
	@rm -f $(TFILES)

install: reporter copy

reporter: reporter.c 
	$(CC) $(CFLAGS) -I ../include $^ -o $@

copy:
	@cp reporter ../tests
	@cp test_driver.sh ../tests
	@cp default_cmds ../tests
	@cp cov_cmds ../tests
	@cp gcc_cmds ../tests
	@cp kw_cmds ../tests

testlist:
	@cp make_struct.awk ../tests
	@cp check_list.awk ../tests
	@cp make_testlist.sh ../tests
	(cd ../tests; $(MAKE) testlist)
	@rm -f ../tests/make_struct.awk
	@rm -f ../tests/check_list.awk
	@rm -f ../tests/make_testlist.sh 
