// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 3
// Brute Force Implementation string search

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>


#define MAX_LEN 256
#define TRUE 1
#define FALSE 0


void constructShiftTable(char* pattern, int shiftTable[MAX_LEN], int tableSize);
int horspoolsStringMatch(char* pattern, char* text, int shiftTable[MAX_LEN], int tableSize);


int main(int argc, char* argv[]) {
    struct timeval startTime, endTime;      
    FILE *fp = NULL;
    char fileName[MAX_LEN] = "data_5.txt";
    char* text = NULL;

    if(argc > 1) {
        strcpy(fileName, argv[1]);
    }

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Could not open file, please try again.\n");
        return 1;
    }
    

    fseek(fp, 0, SEEK_END);
    int fileLength = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    text = malloc(fileLength + 1);

    fread(text, 1, fileLength, fp);

    fclose(fp);

    char pattern[MAX_LEN] = {0};
    int shiftTable[MAX_LEN] = {0};

    printf("Enter the pattern that you would like to search:\n");
    scanf("%s", pattern);

    constructShiftTable(pattern, shiftTable, MAX_LEN);

    gettimeofday(&startTime, NULL);

    int numOccurences = horspoolsStringMatch(pattern, text, shiftTable, MAX_LEN);    

    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
    printf("Total Occurences: %d\n", numOccurences);

    return 0;
}

// Search for all occurences of a string in a stream of text
int horspoolsStringMatch(char* pattern, char* text, int shiftTable[MAX_LEN], int tableSize) {
    int currentLocation = strlen(pattern) - 1;
    int i = 0;
    int numOccurences = 0;
    int numShifts = 0;
    int patternLength = strlen(pattern);
    int textLength = strlen(text);

    while(currentLocation < textLength) {
        i = 0;
        while(i < patternLength && 
        text[currentLocation - i] == pattern[patternLength - 1 - i ]) {
            i++;
        }
        if(i == patternLength) {
            numOccurences++;
        }
        if(isascii(text[currentLocation])) {
            currentLocation += shiftTable[text[currentLocation]];
        } else {
            currentLocation += shiftTable[0];
        }

        numShifts++;
    }

    printf("Number of Shifts: %d\n", numShifts);

    return numOccurences;
}

// Construct the suffix table for calculating the shift amount 
void constructShiftTable(char* pattern, int shiftTable[MAX_LEN], int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        shiftTable[i] = strlen(pattern);
    }

    for(int i = 0; i < strlen(pattern) - 1; i++) {
        shiftTable[pattern[i]] = strlen(pattern) - 1 - i;
    }
}


