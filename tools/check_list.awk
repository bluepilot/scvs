#	tools	check_list.awk
#
# Copyright and License information can be found in the file
# license.txt or license.html
#
# An awk script that is called by make_test_list.sh
# This awk script reads a test file, locates the required 
# diagnostic line number in the documentation, if None then 
# line number is zero (0).  The script then checks for the 
# actual line number to make sure that they match, if there 
# is no match the script issues a diagnostic.  The script 
# make_test_list.sh checks for this diagnostic.
#
BEGIN{sep = "";}
{ 
 if (($2 == "Diagnostic:") && ($NF == "None")) {
     n = 0;
     printf("%s %d\n", FILENAME, n);
 } else {
   if (($2 == "Diagnostic:") && ($NF != "None"))  { 
     if($7 == "and" || $7 == "or") {
       k = $6;
       if($7 == "and") {
         sep = "&";
       } else {
         sep = "|"
       }
     }
     s = $NF;
     n = 1;
   } 
   if($NF == "required" && n) {
     t = NR;
     if(k) {
       if(t == k) {
           printf("%s %d\n", FILENAME, k); 
           k = 0;
       } else {
           printf("First in set does not match in %s\n", FILENAME);
       }
     } else {
       if(s == t) { 
         if(sep == "") {
	   printf("%s %d\n", FILENAME, s); 
         } else {
           printf("%s %d\n", FILENAME, s);
           sep = "";
         }
       } else {
         printf("\t+++ numbers DON'T match in %s\t +++, off by %d\n", FILENAME, t-s);
       }
    }
   }
 }
} 
