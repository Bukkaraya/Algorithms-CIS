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

The average ratio for the brute force algorithm: 9.261
The average ratio for the Horsepool algorithm: 5.3612

The Horsepool algorithm has a lower average ratio of number of shifts to the run time of the program. The number of shifts for the brute force algorithm remains roughly the same for each word as we shift by one each iteration. The run time for the bruteforce is much larger for the different words compared to the Horsepool implementation. The Horsepool algorithm shifts by a precalculated amount each time which reduces the number of shifts made in total. By shifting less the run time of the algorithm also goes down. This leads to a lower ratio compared to the brute force implementation. When the number of letters in the word are large the Horsepool performs much better than the brute force and for smaller letters the Horsepool is only marginally better than the brute force implmentation.

The Boyer Moore algorithm is similar to the Horsepool algorithm and has roughly the same results. The results for different words are presented below.

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
+----------------------------+-------------+------------+-------------+
|                            | Brute Force | Horsepool  | Boyer-Moore |
+----------------------------+-------------+------------+-------------+
| Number of Occurences       | 1271        | 1271       | 1271        |
+----------------------------+-------------+------------+-------------+
| Number of Shifts           | 3300441     | 745308     | 744037      |
+----------------------------+-------------+------------+-------------+
| Runtime (ms)               | 468852.21   | 197673.89  | 210978.68   |
+----------------------------+-------------+------------+-------------+
| Ratio (no. shifts/runtime) | 7.039405872 | 3.77039173 | 3.526598043 |
+----------------------------+-------------+------------+-------------+

Word 4: asdfgh
+----------------------------+-------------+------------+-------------+
|                            | Brute Force | Horsepool  | Boyer-Moore |
+----------------------------+-------------+------------+-------------+
| Number of Occurences       | 0           | 0          | 0           |
+----------------------------+-------------+------------+-------------+
| Number of Shifts           | 3300440     | 587590     | 587590      |
+----------------------------+-------------+------------+-------------+
| Runtime (ms)               | 341418.5    | 125161.67  | 124879.09   |
+----------------------------+-------------+------------+-------------+
| Ratio (no. shifts/runtime) | 9.666845821 | 4.69464813 | 4.705271315 |
+----------------------------+-------------+------------+-------------+

Word 5: Statistics
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 88          | 88          | 88          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300436     | 396692      | 390679      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 288946.65   | 61834.86    | 68407.8     |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 11.42230235 | 6.415345648 | 5.711030029 |
+----------------------------+-------------+-------------+-------------+

Word 6: substitution
+----------------------------+-------------+-------------+-------------+
| a                          | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 2           | 2           | 2           |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300434     | 334882      | 334880      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 319014.93   | 69426.39    | 80810.62    |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 10.34570388 | 4.823554847 | 4.144009785 |
+----------------------------+-------------+-------------+-------------+

Word 7: detailedinformation
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 1           | 1           | 1           |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300427     | 273608      | 263672      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 332323.9    | 74425.45    | 82887.6     |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 9.931356126 | 3.676269341 | 3.181078955 |
+----------------------------+-------------+-------------+-------------+

Word 8: help
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 28          | 28          | 28          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300442     | 895319      | 895290      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 475551.37   | 276841.18   | 277885.93   |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 6.94024286  | 3.234052824 | 3.221789603 |
+----------------------------+-------------+-------------+-------------+

Word 9: students
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 4201        | 4201        | 4201        |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300438     | 505986      | 500284      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 559961.5    | 97394.75    | 114115.66   |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 5.894044501 | 5.195208161 | 4.384008295 |
+----------------------------+-------------+-------------+-------------+

Word 10: Chapter
+----------------------------+-------------+-------------+-------------+
|                            | Brute Force | Horsepool   | Boyer-Moore |
+----------------------------+-------------+-------------+-------------+
| Number of Occurences       | 23          | 23          | 23          |
+----------------------------+-------------+-------------+-------------+
| Number of Shifts           | 3300439     | 566014      | 565991      |
+----------------------------+-------------+-------------+-------------+
| Runtime (ms)               | 741245.12   | 178694.5    | 204398.59   |
+----------------------------+-------------+-------------+-------------+
| Ratio (no. shifts/runtime) | 4.452560848 | 3.167495362 | 2.769055305 |
+----------------------------+-------------+-------------+-------------+