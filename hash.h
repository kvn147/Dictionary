/*
 * Kevin Nguyen
 * CSE222 - 3603
 * 02/23/2023
 * hash.h
 * The hash header file defines the hash size 100, creates an alias for the double pointer struct node, and the function prototypes for the hash functions
 */

#include "list.h"

#define HASHSIZE 100

typedef struct node* HASHENTRY;
HASHENTRY *initHash();

int hash(char *word);

void addHash(HASHENTRY *hashTable, char *word, char *def);

char *findHash(HASHENTRY *hashTable, char *word);

int deleteHash(HASHENTRY *hashTable, char *word);

void freeHash(HASHENTRY *hashTable);

void printHash(HASHENTRY *hashTable);

void printLoad(HASHENTRY *hashTable);

