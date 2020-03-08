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


void constructBadSymbolTable(char* pattern, int shiftTable[MAX_LEN], int tableSize);
void constructGoodSuffixTable(char* pattern, int shiftTable[], int tableSize);
int boyerMooreStringSearch(char* pattern, char* text, int badSymbolTable[MAX_LEN], int goodSuffixTable[], int suffixTableLen);


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
    int badSymbolTable[MAX_LEN] = {0};

    printf("Enter the pattern that you would like to search:\n");
    scanf("%s", pattern);

    int goodSuffixTable[strlen(pattern)];

    for (int i = 0; i < strlen(pattern); i++) {
        goodSuffixTable[i] = 0;
    }

    constructBadSymbolTable(pattern, badSymbolTable, MAX_LEN);
    constructGoodSuffixTable(pattern, goodSuffixTable, strlen(pattern));

    gettimeofday(&startTime, NULL);

    int numOccurences = boyerMooreStringSearch(pattern, text, badSymbolTable, goodSuffixTable, strlen(pattern));   

    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
    printf("Total Occurences: %d\n", numOccurences);

    return 0;
}


int boyerMooreStringSearch(char* pattern, char* text, int badSymbolTable[MAX_LEN], int goodSuffixTable[], int suffixTableLen) {
    int currentLocation = strlen(pattern);
    int i = 0;
    int numOccurences = 0;
    int numShifts = 0;

    while(currentLocation < strlen(text)) {
        i = 0;
        while(i < strlen(pattern) && 
        text[currentLocation - i - 1] == pattern[strlen(pattern) - 1 - i]) {
            i++;
        }

        if(i == strlen(pattern)) {
            numOccurences++;
            currentLocation += strlen(pattern);
            continue;
        }

        int badSymbolShift = 0;
        int goodSymbolShift = 0;

        // Get Bad Symbol Shift Length
        int symbolLocation = currentLocation - 1 - i;

        if(isascii(text[symbolLocation])) {
            badSymbolShift = badSymbolTable[text[symbolLocation]] - i;
        } else {
            badSymbolShift = badSymbolTable[0];
        }

        // Get Good Suffix Shift
        if(i == 0) {
            goodSymbolShift = 1;
        } else {
            goodSymbolShift = goodSuffixTable[strlen(pattern) - i];
        }

        // Calculate shift length which is the maximum of good suffix shift
        // and bad symbol shift.
        int shiftLength = badSymbolShift;
        
        if(goodSymbolShift > badSymbolShift) {
            shiftLength = goodSymbolShift;
        }

        currentLocation += shiftLength;
        numShifts++;
    }

    printf("Number of Shifts: %d\n", numShifts);

    return numOccurences;
}


void constructGoodSuffixTable(char* pattern, int shiftTable[], int tableSize) {
    char suffix[strlen(pattern)];
    int i = strlen(pattern);
    int j = strlen(pattern) + 1;

    int borders[i];
    borders[i] = j;

    while(i > 0) {
        while(j <= strlen(pattern) && pattern[i - 1] != pattern[j - 1]) {
            if(shiftTable[j] == 0) {
                shiftTable[j] = j - i;
            }
            j = borders[j];
        }
        i--;
        j--;
        borders[i] = j;
    }

    i = 0;
    j = 0;

    j = borders[0];

    for(i = 0; i <= strlen(pattern); i++) {
        if(shiftTable[i] == 0) {
            shiftTable[i] = j;
        }
        if(i == j) {
            j = borders[j];
        }
    }
}


void constructBadSymbolTable(char* pattern, int shiftTable[MAX_LEN], int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        shiftTable[i] = strlen(pattern);
    }

    for(int i = 0; i < strlen(pattern) - 1; i++) {
        shiftTable[pattern[i]] = strlen(pattern) - 1 - i;
    }
}


