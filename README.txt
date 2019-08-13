Matthew Fales
==============Code environment=======================
Linux version 4.15.0-43-generic (buildd@lgw01-amd64-001) 
(gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3)) #46-Ubuntu SMP Thu Dec 6 14:45:28 UTC 2018



===============What the program does==================
This program takes 1 argument which is supposed to be parentheses ()[]{}
with no spaces between.  This program will tell you if these are legal 
and valid ways of order of operations.
Examples:
{}{}({})
{{{{}}}}
(((())))
{(})
All these option should be put into th test files
=================How is it different=======================
It is the same format as the first version of this but this now split up into easier to 
maintained methods.
==================Output Example========================
If you test like ./ts v1 the out will go to terminal
----------------------------------------------------
If you test with the invoker out will go to the file created called newfile
This will also use perl and python scripts to check what the out is and gives
you information back on time and valid and invalid cases.

==================Files included=====================
Makefile   # come the c file executable
ts.cc      # the main program
in1        # invalid cases
v1         # valid cases
mix        # mix of invalid and valid cases
randomtest # this is created by the bash script called tc1 this creats random cases
invoker    # this will test the script against the cases this also uses a perl and python script to give you information about the tests
=================How make test file============================================
1. 


=================How to run============================================
1. open terminal  type make  # this is for the make file
2. type: ./ts v1  # you can put in1 or v1 or mix or randomtest or your own.
3. if any problems happen use make clean 
4. then type make again repeat step 2
=================How to run with bash script=========================
1. open terminal in the folder the at contains everything ./invoker
2. type ./invoker
3. you will see choices pop up in the window
4. pick which ever suits your case the best
5. The test get put into a file called newfile

















