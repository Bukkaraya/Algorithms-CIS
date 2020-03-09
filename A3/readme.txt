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

The programs were analyzed for 10 words of different lengths and are compared based on number of shifts and total runtime of each program. 

The average ratio for the brute force algorithm: 292,968 shifts / ms
The average ratio for the Horsepool algorithm: 111,889.4 shifts / ms

The Horsepool algorithm has a lower average ratio of number of shifts per milliseconds. The number of shifts for the brute force algorithm remains roughly the same for each word as we shift by one character each iteration. The run time for the bruteforce is much larger for the different words compared to the Horsepool implementation. The Horsepool algorithm shifts by a precalculated amount each time which reduces the number of shifts made in total. By shifting less the run time of the algorithm also goes down. This leads to a lower ratio compared to the brute force implementation. When the number of letters in the word are large the Horsepool performs much better than the brute force and for smaller letters the Horsepool is only marginally better than the brute force implmentation. Overall Horsepool's Algorithm performs much better than the brute force implementation.

The Boyer Moore algorithm is similar to the Horsepool algorithm and has roughly the same results. The results for different words are presented below.

Word 1: Economics
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 236         | 236         | 236         |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300437     | 428081      | 427845      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 9.499       | 3.66        | 4.47        |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 347450.9948 | 116962.0219 | 95714.7651  |
+----------------------------+-------------+-------------+-------------+

Word 2: information
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 171         | 171         | 171         |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300435     | 391699      | 388677      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 13.14       | 4.18        | 4.8         |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 251174.6575 | 93707.89474 | 80974.375   |
+----------------------------+-------------+-------------+-------------+

Word 3: under
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 1271        | 1271        | 1271        |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300441     | 745308      | 744037      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 11.28       | 6.247       | 8.315       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 292592.2872 | 119306.5471 | 89481.29886 |
+----------------------------+-------------+-------------+-------------+

Word 4: asdfgh
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 0           | 0           | 0           |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300440     | 587590      | 587590      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 13.15       | 4.494       | 5.621       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 250984.0304 | 130749.8887 | 104534.7803 |
+----------------------------+-------------+-------------+-------------+

Word 5: Statistics
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 88          | 88          | 88          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300436     | 396692      | 390679      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 9.69        | 3.36        | 4.287       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 340602.2704 | 118063.0952 | 91131.09401 |
+----------------------------+-------------+-------------+-------------+

Word 6: substitution
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 2           | 2           | 2           |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300434     | 334882      | 334880      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 12.07       | 3.26        | 3.964       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 273441.0936 | 102724.5399 | 84480.32291 |
+----------------------------+-------------+-------------+-------------+

Word 7: detailedinformation
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 1           | 1           | 1           |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300427     | 273608      | 263672      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 11.372      | 2.85        | 3.333       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 290223.9712 | 96002.80702 | 79109.51095 |
+----------------------------+-------------+-------------+-------------+

Word 8: help
+----------------------------+-------------+-------------+-------------+
| a                          | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 28          | 28          | 28          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300442     | 895319      | 895290      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 11.341      | 7.5         | 8.486       |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 291018.6051 | 119375.8667 | 105502.0033 |
+----------------------------+-------------+-------------+-------------+

Word 9: students
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 4021        | 4021        | 4021        |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300438     | 505986      | 500284      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 12.36       | 4.58        | 5.84        |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 267025.7282 | 110477.2926 | 85665.06849 |
+----------------------------+-------------+-------------+-------------+

Word 10: Chapter
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 23          | 23          | 23          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300439     | 566014      | 565991      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 10.15       | 5.075       | 6.06        |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 325166.4039 | 111529.8522 | 93397.85479 |
+----------------------------+-------------+-------------+-------------+