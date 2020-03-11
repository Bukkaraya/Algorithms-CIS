// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 4
// Optimal Binary Search Tree with Greedy Implementation

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>


#define MAX_LEN 256
#define TRUE 1
#define FALSE 0
#define MAX_ARRAY_SIZE 50000


typedef struct WordProbability {
    char* text;
    float probability;
} WordProbability;

typedef struct treeNode {
    WordProbability word;
    float cost;
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;


typedef struct Tree {
    TreeNode* root;
} Tree;


int stringCompare(const void* str1, const void* str2);


int main(int argc, char* argv[]) {
    FILE *fp = NULL;
    char fileName[MAX_LEN] = "data_7.txt";
    int numStrings = 0;

    if(argc > 1) {
        strcpy(fileName, argv[1]);
    }

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Could not open file, please try again.\n");
        return 1;
    }

    char* words[MAX_ARRAY_SIZE];
    char line[MAX_LEN] = {0};
    int numWords = 0;

    while(fscanf(fp, "%s", line) == 1) {
        words[numWords] = malloc(sizeof(char) * strlen(line) + 1);
        strcpy(words[numWords], line);

        numWords++;
    }

    qsort((void *) words, numWords, sizeof(char *), stringCompare);
    
    int numSortedWords = 0;
    WordProbability sortedWords[numWords];
    int wordOccurences = 0;

    for(int i = 0; i < numWords; i++) {
        WordProbability newWord;
        newWord.text = words[i];
        wordOccurences = 1;

        while(i < numWords - 1 && strcmp(words[i], words[i + 1]) == 0) {
            i++;
            wordOccurences++;
        }

        newWord.probability = (float) wordOccurences / numWords;
        sortedWords[numSortedWords] = newWord;

        numSortedWords++;
    }

    for(int i = 0; i < numSortedWords; i++) {
        printf("%s (%f)\n", sortedWords[i].text, sortedWords[i].probability);
    }

    printf("Number of Unique Words: %d\n", numSortedWords);
    
}


// String compare function for sorting
int stringCompare(const void* str1, const void* str2) {
    const char *a = *(const char **)str1;
    const char *b = *(const char **)str2;

    return strcmp(a, b);
}