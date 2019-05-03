dynamicArray.c and dynArray.h implement a dynamic array with interfaces for both a stack and a bag. 
stackapp.c uses the dymanic array as a stack to test if a user entered expression has balanced parenthesis, braces, and brackets (,{,[ or not. For example, expressions with balanced parenthesis are (x+y), (x+(y+z)) and with unbalance are (x+y, (x+(y+z). 

Usage:
add these files to your directory and run:
$ make all
$ prog [expression]

where [expression] is some expression to be evaluated. 

To clean up when done, run:
$ make clean 

