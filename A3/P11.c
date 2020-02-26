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


int bruteForceNumAnagrams(char* anagramString, char* stringArray[], int numStrings);


int main(int argc, char* argv[]) {
    struct timeval startTime, endTime;      
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

    gettimeofday(&startTime, NULL);
    int numAnagrams = bruteForceNumAnagrams(anagramString, stringArray, numStrings);
    gettimeofday(&endTime, NULL);

    float totalRunTime = (endTime.tv_sec - startTime.tv_sec) * 1000000 + 
		(endTime.tv_usec - startTime.tv_usec);

    totalRunTime /= 1000;

    printf("Total Time to Run: %f ms\n", totalRunTime);
    printf("Number of Anagrams: %d\n", numAnagrams);

    return 0;
}


int bruteForceNumAnagrams(char* anagramString, char* stringArray[], int numStrings) {
    printf("Anagram String: %s\n", anagramString);
    int anagramStrLen = strlen(anagramString);
    int numAnagrams = 0;
    int isAnagram = 0;

    for(int i = 0; i < numStrings; i++) {
        isAnagram = TRUE;
        if(anagramStrLen != strlen(stringArray[i])) {
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

    return numAnagrams;
}
