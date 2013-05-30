#	tools	make_struct.awk
#
# Copyright and License information can be found in the file
# license.txt or license.html
#
# This awk script is used in the make_testlist.sh script.
# This awk script takes an input string and outputs a string that
# will be included in the testlist.h file.  This file testlist.h is 
# included with an "#include" statement in the report.h include file.
# 
BEGIN {
       printf("// This file, testlist.h should not be edited by hand.");
       printf("  See\n// product documentation.\n");
       printf("//\n");
       printf("#ifndef TEST_LIST_H\n#define TEST_LIST_H\n\nstatic test_information test_list[] = {\n");
      }
{
sub("/"," ");
printf("  {\"%s\",\"%s\",%s,false,0,0},\n", $1, $2, $3);
}
END { 
    printf("  {\"\",\"\",-1,false,0,0},\n};\n#endif\n");
    }
