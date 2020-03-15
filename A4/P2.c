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
    struct treeNode* left;
    struct treeNode* right;
} TreeNode;


typedef struct Tree {
    TreeNode* root;
} Tree;


int stringCompare(const void* str1, const void* str2);
void printTreeNode(TreeNode* node);
Tree* constructDictionary(WordProbability words[], int numWords);
TreeNode* createTree(WordProbability words[], int start, int end);
int searchDictionary(Tree* dictionary, char* key);
int searchTree(TreeNode* root, char* key) ;
void destroyTree(TreeNode* root);


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


    Tree* dictionary = constructDictionary(sortedWords, numSortedWords);

    char key[MAX_LEN];
    printf("Enter a key:\n");
    scanf("%s", key);

    int keyFound = searchDictionary(dictionary, key);

    if(!keyFound) {
        printf("Not Found.\n");
    }

    // Free Memory Allocated
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }

    destroyTree(dictionary->root);
    free(dictionary);

    fclose(fp);

    return 0;
}


void destroyTree(TreeNode* root) {
    if(root == NULL) {
        return;
    }

    destroyTree(root->left);
    destroyTree(root->right);
    free(root);

    return;
}


int searchDictionary(Tree* dictionary, char* key) {
    int keyFound = FALSE;
    keyFound = searchTree(dictionary->root, key);

    return keyFound;
}

int searchTree(TreeNode* root, char* key) {
    int isFound = FALSE;

    if(root == NULL) {
        return isFound;
    }

    if(isFound) {
        return isFound;
    }

    int comparisionResult = strcmp(key, root->word.text);
    printf("Compared with %s (%.4f), ", root->word.text, root->word.probability);

    if(comparisionResult > 0) {
        printf("go right subtree.\n");
        isFound = searchTree(root->right, key);
    } else if(comparisionResult < 0) {
        printf("go left subtree.\n");
        isFound = searchTree(root->left, key);
    } else {
        printf("found.\n");
        isFound = TRUE;
        return isFound;
    }

    return isFound;
}


Tree* constructDictionary(WordProbability words[], int numWords) {
    Tree* greedyTree = malloc(sizeof(Tree));
    greedyTree->root = NULL;

    greedyTree->root = createTree(words, 0, numWords);

    return greedyTree;
}

TreeNode* createTree(WordProbability words[], int start, int end) {
    if(start > end || start == end) {
        return NULL;
    }

    WordProbability wordWithMaxProb = words[start];
    int maxProbIndex = start;

    for(int i = start + 1; i < end; i++) {
        if(words[i].probability > wordWithMaxProb.probability) {
            wordWithMaxProb = words[i];
            maxProbIndex = i;
        }
    }

    TreeNode* root = malloc(sizeof(TreeNode));
    root->word = wordWithMaxProb;

    root->left = createTree(words, start, maxProbIndex);
    root->right = createTree(words, maxProbIndex + 1, end);

    return root;
}



void printTreeNode(TreeNode* node) {
    printf("TreeNode<Word: %s, Probability: %f>\n", node->word.text, node->word.probability);
}

// String compare function for sorting
int stringCompare(const void* str1, const void* str2) {
    const char *a = *(const char **)str1;
    const char *b = *(const char **)str2;

    return strcmp(a, b);
}