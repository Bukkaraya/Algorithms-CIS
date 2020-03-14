// Author: Abinav Bukkaraya
// ID: 0951030
// Assignment 4
// Optimal Binary Search Tree with Dynamic Programming

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
void printTable(float** table, int tableSize);
void findOptimalTree(float** costTable, float** rootTable, int tableSize);
Tree* constructOptimalTree(float** costTable, float** rootTable, int tableSize, WordProbability* words, int numWords);
TreeNode* constructTree(float** costTable, float** rootTable, WordProbability* words, int start, int end);
void printTreeNode(TreeNode* node);
int searchDictionary(Tree* dictionary, char* key);
int searchTree(TreeNode* root, char* key);
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

    int tableSize = numSortedWords + 1;

    float** costTable = malloc(tableSize * sizeof(float *));
    float** rootTable = malloc(tableSize * sizeof(float *));

    for(int i = 0; i < tableSize; i++) {
        costTable[i] = malloc(tableSize * sizeof(float));
        for(int j = 0; j < tableSize; j++) {
            costTable[i][j] = 0;            
        }
    } 

    for(int i = 0; i < tableSize; i++) {
        rootTable[i] = malloc(tableSize * sizeof(float));
        for(int j = 0; j < tableSize; j++) {
            rootTable[i][j] = 0;            
        }
    } 

    for(int i = 0; i < tableSize - 1; i++) {
        costTable[i][i + 1] = sortedWords[i].probability;
    }

    for(int i = 0; i < tableSize - 1; i++) {
        rootTable[i][i + 1] = i + 1;
    }

    findOptimalTree(costTable, rootTable, tableSize);

    Tree* dictionary = constructOptimalTree(costTable, rootTable, tableSize, sortedWords, numSortedWords);

    char key[MAX_LEN];
    printf("Enter a key:\n");
    scanf("%s", key);

    int keyFound = searchDictionary(dictionary, key);

    if(!keyFound) {
        printf("Not Found.\n");
    }


    // Free Used Memory
    for(int i = 0; i < numWords; i++) {
        free(words[i]);
    }

    for(int i = 0; i < tableSize; i++) {
        free(costTable[i]);
        free(rootTable[i]);
    }

    free(costTable);
    free(rootTable);

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
    printf("Compared with %s (%f), ", root->word.text, root->cost);

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


Tree* constructOptimalTree(float** costTable, float** rootTable, int tableSize, WordProbability* words, int numWords) {
    Tree* optimalTree = malloc(sizeof(Tree));
    optimalTree->root = NULL;
    int insertTable[numWords];

    for(int i = 0; i < numWords; i++) {
        insertTable[i] = FALSE;
    }

    optimalTree->root = constructTree(costTable, rootTable, words, 0, tableSize - 1);

    return optimalTree;
}

TreeNode* constructTree(float** costTable, float** rootTable, WordProbability* words, int start, int end) {
    int optimalWordIndex = 0;
    float treeCost = 0;

    optimalWordIndex = rootTable[start][end];

    if(optimalWordIndex == 0) {
        return NULL;
    }

    treeCost = costTable[start][end];


    TreeNode* root = malloc(sizeof(TreeNode));
    root->left = NULL;
    root->right = NULL;

    root->word = words[optimalWordIndex - 1];
    root->cost = treeCost;

    root->left = constructTree(costTable, rootTable, words, start, optimalWordIndex - 1);
    root->right = constructTree(costTable, rootTable, words, optimalWordIndex, end);

    return root;
}


void printTreeNode(TreeNode* node) {
    printf("TreeNode<Word: %s, Cost: %f>\n", node->word.text, node->cost);
}


void findOptimalTree(float** costTable, float** rootTable, int tableSize) {
    float minimumCost = 100000;
    float currentCost = 0;
    int offset = 0;
    int j = 0;
    int sum = 0;
    int minimumRoot = 0;

    for(int d = 0; d < tableSize; d++) {
        for(int i = 1; i < tableSize - d; i++) {
            j = i + d;
            minimumCost = 1000;

            // printf("<%d, %d>\n", i, j);

            if(i == j) {
                continue;
            }

            for(int k = i; k <= j; k++) {
                currentCost = 0;
                // printf("k = %d <%d %d>, <%d, %d>\n", k, i, k - 1, k + 1, j);

                if(k - 1 < i) {
                    currentCost += 0;
                } else {
                    currentCost += costTable[i - 1][k - 1];
                }

                if(k + 1 > j) {
                    currentCost += 0;
                } else {
                    currentCost += costTable[k + 1 - 1][j];
                }

                if(currentCost < minimumCost) {
                    minimumCost = currentCost;
                    minimumRoot = k;
                }
            }

            // printf("Minimum Cost: %f\n", minimumCost);

            for(int s = i - 1; s < j; s++) {
                minimumCost += costTable[s][s + 1];
            }

            // printf("C[%d, %d]: %f\n", i, j, minimumCost);

            costTable[i - 1][j] = minimumCost;
            rootTable[i - 1][j] = minimumRoot;
        }
    }
}


void printTable(float** table, int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        for(int j = 0; j < tableSize; j++) {
            printf("%f | ", table[i][j]);
        }
        printf("\n");
    }
}

// String compare function for sorting
int stringCompare(const void* str1, const void* str2) {
    const char *a = *(const char **)str1;
    const char *b = *(const char **)str2;

    return strcmp(a, b);
}