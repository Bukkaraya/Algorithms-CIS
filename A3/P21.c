// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 3
// Brute Force Implementation string search

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>


#define MAX_LEN 256
#define TRUE 1
#define FALSE 0


int bruteForceStringSearch(char* pattern, char* text);


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

    printf("Enter the pattern that you would like to search:\n");
    scanf("%s", pattern);

    gettimeofday(&startTime, NULL);

    int numOccurences = bruteForceStringSearch(pattern, text);    

    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
    printf("Total Occurences: %d\n", numOccurences);

    return 0;
}


int bruteForceStringSearch(char* pattern, char* text) {
    int numShifts = 0;
    int numOccurences = 0;

    for(int i = 0; i < strlen(text) - strlen(pattern); i++) {
        int j = 0;
        while(j < strlen(pattern) && text[i + j] == pattern[j]) {
            j++;
        }
        if(j == strlen(pattern)) {
            numOccurences++;
        }
        numShifts++;
    }

    printf("Number of Shifts: %d\n", numShifts);
    
    return numOccurences;
}