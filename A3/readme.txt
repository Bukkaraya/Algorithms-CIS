Name: Abinav Bukkaraya
ID: 0951030
CIS 3490 Algorithms
Assignment 3

This assignment contains 5 programs P11.c, P12.c, P21.c, P22.c, P23.c

To compile all programs run:

make all 

To clean files:

make clean

Q1.1) Brute Force Implementation to find the number of anagrams in an array given a string.

To run the program:
./P11

By default the program will use data_4.txt. To run the program with a different dataset:
./P11 <your_datafile>.txt

The program will first prompt for the number of elements in the array. For data_4.txt the number of elements in the array is 30000.
After the array size has been provided, the program will prompt for a string to find the anagrams for.

The output for this program is the number of anagrams and the time taken to search.

Q1.2) Optimized Implementation to find the number of anagrams in an array given a string. This program uses a double sorting method, which sorts each string to give a signature and then sorts the signatures.

To run the program:
./P12

By default the program will use data_4.txt. To run the program with a different dataset:
./P12 <your_datafile>.txt

The program will first prompt for the number of elements in the array. For data_4.txt the number of elements in the array is 30000.
After the array size has been provided, the program will prompt for a string to find the anagrams for.

The output for this program is the number of anagrams and the time taken to sort and search separately.

Q2.1) Brute Force Implementation of string search

To run the program:
./P21

By default the program will use data_5.txt. To run the program with a different dataset:
./P21 <your_datafile>.txt

The program will prompt you for a string to search for in the data_5.txt file.

Q2.2) Horsepool's Algorithms for string search

To run the program:
./P22

By default the program will use data_5.txt. To run the program with a different dataset:
./P22 <your_datafile>.txt

The program will prompt you for a string to search for in the data_5.txt file.

Q2.3) Boyer-Moore Algorithm for string search

To run the program:
./P23

By default the program will use data_5.txt. To run the program with a different dataset:
./P23 <your_datafile>.txt

The program will prompt you for a string to search for in the data_5.txt file.

Q2.4) Analysis of string search programs

The programs were analyzed for 10 words of different lengths and are compared based on number of shits and total runtime of each program.

Word 1: Economics

+----------------------------+-------------+-----------+-------------+
|                            | Brute Force | Horsepool | Boyer-Moore |
+----------------------------+-------------+-----------+-------------+
| Number of Occurences       | 236         | 236       | 236         |
+----------------------------+-------------+-----------+-------------+
| Number of Shifts           | 3300437     | 428081    | 427845      |
+----------------------------+-------------+-----------+-------------+
| Runtime (ms)               | 221117.01   | 39979.42  | 33172.37    |
+----------------------------+-------------+-----------+-------------+
| Ratio (no. shifts/runtime) | 14.926      | 10.70     | 12.89       |
+----------------------------+-------------+-----------+-------------+

Word 2: information

+----------------------------+-------------+-----------+-------------+
|                            | Brute Force | Horsepool | Boyer-Moore |
+----------------------------+-------------+-----------+-------------+
| Number of Occurences       | 171         | 171       | 171         |
+----------------------------+-------------+-----------+-------------+
| Number of Shifts           | 3300435     | 391699    | 388677      |
+----------------------------+-------------+-----------+-------------+
| Runtime (ms)               | 275093.09   | 49206.25  | 52721.24    |
+----------------------------+-------------+-----------+-------------+
| Ratio (no. shifts/runtime) | 11.997      | 7.960351  | 7.372304    |
+----------------------------+-------------+-----------+-------------+

Word 3: under