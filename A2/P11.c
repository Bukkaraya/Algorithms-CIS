// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 2
// Brute Force Implementation of counting number of inversions in array

#include <stdio.h>
#include <sys/time.h>
#include <string.h>

long bruteCountInversions(long array[], int size) {
    long numInversions = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                numInversions++;
            }
        }
    }

    return numInversions;
}


int main(int argc, char *argv[]) {
    struct timeval startTime, endTime;
    FILE *fp = NULL;
    int arraySize = 0;
    long number = 0;

    char fileName[256] = "data1.txt";

    if (argc > 1) {
        strcpy(fileName, argv[1]);
    }

    printf("Using file: %s\n", fileName);

    printf("Please enter the size of the array:\n");
    scanf("%d", &arraySize);

    long array[arraySize];

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Could not open file, please try again.\n");
        return 0;
    }

    int i = 0;

    while(fscanf(fp, "%ld", &number) > 0) {
        array[i] = number;
        i++;
    }

    gettimeofday(&startTime, NULL);
    long numInversions = bruteCountInversions(array, arraySize);
    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);

    printf("Number of Inversions: %ld\n", numInversions);

    return 0;
}