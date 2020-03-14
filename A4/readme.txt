Name: Abinav Bukkaraya
ID: 0951030
CIS 3490 Algorithms
Assignment 4

This assignment contains 2 programs P1.c and P2.c

To compile all programs run:

make all 

To clean files:

make clean

Q1) Binary Search Tree with a dynamic programming implementation. The cost table and root table is first determined and the tree is constructed based on the final root table.

To run the program:
./P1

By default the program will use data_7.txt. To run the program with a different dataset:
./P1 <your_datafile>.txt

The program will prompt you to enter a word after the tree has been constructed. Please note that the construction of the tree takes a few seconds. After you enter the word to search the program enters the search path taken and outputs if the word has been found or not. It also prints the cost for each subtree that is program encounters.


Q2) Binary Search Tree with a greedy implementation. The word with the largest probability is placed in the root and the words are split into two halves. 

To run the program:
./P2

By default the program will use data_7.txt. To run the program with a different dataset:
./P2 <your_datafile>.txt

The program will prompt you to enter a word after the tree has been constructed. Please note that the construction of the tree takes a few seconds. After you enter the word to search the program enters the search path taken and outputs if the word has been found or not. It also prints the probability for each each word that is program encounters.

