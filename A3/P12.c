// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 3
// Brute Force Implementation of anagrams of a string

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>


#define MAX_LEN 256
#define TRUE 1
#define FALSE 0


int stringCompare(const void* str1, const void* str2);
int characterCompare(const void* c1, const void* c2);
int optimizedNumAnagrams(char* anagramString, char* stringArray[], int numStrings);
void printAnagrams(char* anagramString, char* stringArray[], int numStrings);


int main(int argc, char* argv[]) {
    FILE *fp = NULL;
    char fileName[MAX_LEN] = "data_4.txt";
    int numStrings = 0;

    if(argc > 1) {
        strcpy(fileName, argv[1]);
    }

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Could not open file, please try again.\n");
        return 1;
    }

    // Prompt for array size
    printf("Enter the size of the array:\n");
    scanf("%d", &numStrings);
    
    char* stringArray[numStrings];
    char str[MAX_LEN];
    int i = 0;

    // Get all string from file
    while (fscanf(fp, "%s", str) > 0) {
        stringArray[i] = malloc(sizeof(strlen(str)) + 1);
        strcpy(stringArray[i], str);
        i++;
    }

    char anagramString[MAX_LEN];
    printf("Enter the string you want to find anagrams for:\n");
    scanf("%s", anagramString);
    // Print anagrams before, because optimized version modifies the array.
    printAnagrams(anagramString, stringArray, numStrings);
    int numAnagrams = optimizedNumAnagrams(anagramString, stringArray, numStrings);
    printf("Number of Anagrams: %d\n", numAnagrams);

    return 0;
}


// Get the number of anagrams of a string
int optimizedNumAnagrams(char* anagramString, char* stringArray[], int numStrings) {
    int numAnagrams = 0;
    struct timeval startTime, endTime;

    gettimeofday(&startTime, NULL);

    // Sort each individual string
    for(int i = 0; i < numStrings; i++) {
        if(strcmp(anagramString, stringArray[i]) == 0) {
            stringArray[i][0] = '\0';
            continue;
        }
        qsort((void*) stringArray[i], strlen(stringArray[i]), sizeof(char), characterCompare);
    }

    // Sort the input string for comparision
    qsort((void*) anagramString, strlen(anagramString), sizeof(char), characterCompare);

    // Sort Array of Strings
    qsort((void *) stringArray, numStrings, sizeof(char *), stringCompare);

    gettimeofday(&endTime, NULL);
    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);
    totalRunTime /= 1000;

    printf("Total Sorting Time: %f ms\n", totalRunTime);

    // Search for number of anagrams in the array by comparisions
    gettimeofday(&startTime, NULL);

    for(int i = 0; i < numStrings; i++) {
        if(strlen(anagramString) != strlen(stringArray[i])) {
            continue;
        }
        if(strcmp(anagramString, stringArray[i]) == 0){
            numAnagrams++;
        }
    }

    gettimeofday(&endTime, NULL);


    totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);
    totalRunTime /= 1000;

    printf("Total Search Time: %f ms\n", totalRunTime);

    return numAnagrams;
}


// String compare function for sorting
int stringCompare(const void* str1, const void* str2) {
    const char *a = *(const char **)str1;
    const char *b = *(const char **)str2;

    return strcmp(a, b);
}

// Character comparision function for sorting
int characterCompare(const void* c1, const void* c2) {
    return *(char *)c1 - *(char *)c2;
}


void printAnagrams(char* anagramString, char* stringArray[], int numStrings) {
    int anagramStrLen = strlen(anagramString);
    int numAnagrams = 0;
    int isAnagram = 0;

    printf("------- Found Anagrams -------\n");

    // Get all anagrams in the array and print them
    for(int i = 0; i < numStrings; i++) {
        isAnagram = TRUE;
        if(anagramStrLen != strlen(stringArray[i]) || 
            strcmp(anagramString, stringArray[i]) == 0) {
            continue;
        }

        int anagramMap[MAX_LEN];

        for(int k = 0; k < MAX_LEN; k++) {
            anagramMap[k] = 0;
        }

        for(int j = 0; j < anagramStrLen; j++) {
            anagramMap[anagramString[j]]++;
        }

        for(int j = 0; j < anagramStrLen; j++) {
            if(--anagramMap[stringArray[i][j]] < 0) {
                isAnagram = FALSE;
                break;
            }
        }

        if(isAnagram) {
            printf("%s\n", stringArray[i]);
            numAnagrams++;
        }
    }

    if(numAnagrams == 0) {
        printf("No anagrams found.\n");
    }

    printf("----------------------------\n");
}
