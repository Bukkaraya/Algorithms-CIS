// Author: Abinav Bukkaraya
// ID: 0951030
// Optimized Implementation of counting number of inversions in array

#include <stdio.h>
#include <sys/time.h>
#include <string.h>


long mergeSort(long array[], int size) {
    int middlePoint = size / 2;

    int leftArraySize = middlePoint;
    int rightArraySize = size - middlePoint;

    long leftArray[leftArraySize];
    long rightArray[rightArraySize];

    for(int i = 0; i < leftArraySize; i++) {
        leftArray[i] = array[i];
    }

    for(int i = middlePoint; i < size; i++) {
        rightArray[i - middlePoint] = array[i];
    }

    long rightInversions = 0;
    long leftInversions = 0;

    if(size > 1) {
        leftInversions = mergeSort(leftArray, leftArraySize);
        rightInversions = mergeSort(rightArray,rightArraySize);
    }

    long numInversions = rightInversions + leftInversions;

    int leftArrayPointer = 0;
    int rightArrayPointer = 0;
    int i = 0;

    while (leftArrayPointer < leftArraySize 
    && rightArrayPointer < rightArraySize) {
        if(leftArray[leftArrayPointer] > rightArray[rightArrayPointer]) {
            array[i] = rightArray[rightArrayPointer];
            rightArrayPointer++;
            numInversions += (leftArraySize - leftArrayPointer);
        } else {
            array[i] = leftArray[leftArrayPointer];
            leftArrayPointer++;
        }

        i++;
    }
    
    while(leftArrayPointer < leftArraySize) {
        array[i] = leftArray[leftArrayPointer];
        leftArrayPointer++;
        i++;
    }

    while(rightArrayPointer < rightArraySize) {
        array[i] = rightArray[rightArrayPointer];
        rightArrayPointer++;
        i++;
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
    long numInversions = mergeSort(array, arraySize);
    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);

    printf("Number of Inversions: %ld\n", numInversions);

    return 0;
}