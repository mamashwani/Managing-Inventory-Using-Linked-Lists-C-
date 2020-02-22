# Managing-Inventory-Using-Linked-Lists-C-
Sorting a book inventory in alphabetical order from a list that contains the book_id, the book_title, and the book_author and deleting duplicates, adding items to the list, or deleting items from the list based on a command file 

# Assumptions:
- The input file is a text file; no need to handle binary files.
- The input will always be in order of book_id, book_title, and book_author and will always only take up one line
- the book_id will always be 5 digits long.
- An input file can contain empty lines that should be ignored.
- Characters are case sensitive.

# Notes
- The 9 "input2x.txt" files are the 9 input files that were used to test this code
- The 9 "output2x.txt" files are the files outputted by the program.
- The 9 "ans2x.txt" files are files containing the correct output that should occur from each corresponding input file, and are available
for comparison to the outputs files to ensure correct output. 
- The 9 "command2x.txt" files contain the command the code must parse through and execute.
- This code was tested on the University of Houston's Linux server and passed all the test cases.
- The "ArgumentManager.h" file parses arguments to sequentially open the 9 input files to automatically test the code on the server.
- The "test.sh" file is a SHELL script for automatically testing the input files on the Linux server.
- The "compile.sh" file is  SHELL script for automatically compiling the code on the Linux server before running the tests.

# Resources:

https://www.geeksforgeeks.org/data-structures/linked-list/
