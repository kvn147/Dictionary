/*
 * Kevin Nguyen
 * CSE222 - 3603
 * 02/23/2023
 * hash.c
 * The hash program initializes the hash tables, does the hashing of the word, adds the word and its definition to the linked list of the hash table it gets from hashing, finds the matching hash for a word, deletes from a hash table, frees the hash table, and prints each hash table and its linked list of word and definition pairs 
 */

#include "hash.h"

//Hash function hashes the word to have an associated hash value with it
int hash(char *word) {
	int sum = 0;
	for (int i = 0; word[i] != '\0'; i++) {
		sum += word[i];
	}
	return sum%HASHSIZE;
}

//Initializes Hash Table 0-99 and returns it
HASHENTRY *initHash(){
	HASHENTRY *hashTable = malloc(HASHSIZE * sizeof(HASHENTRY));
	for(int i = 0; i < HASHSIZE; i++) {
		hashTable[i] = init();
	}
	return hashTable;
}

//Takes the Hash Table, word and definition pair and calls it to be added in the Hash Table's linked list
void addHash(HASHENTRY *hashTable, char *word, char *def) {
	add(hashTable[hash(word)], word, def);
}


//Looks for the matching Hash Table for the Hash Value of the word and returns otherwise returns NULL
char *findHash(HASHENTRY *hashTable, char *word) {
	for(int i = 0; i < HASHSIZE; i++) {
		if(hashTable[hash(word)] == hashTable[i]) {
			return find(hashTable[hash(word)], word);
		}
	}
	return NULL;
}

//Takes the Hash Table and word and calls the words to be deleted from the Hash Table's linked list
int deleteHash(HASHENTRY *hashTable, char *word) {
	return del(hashTable[hash(word)], word);
}

//Frees the Hash Table and its word and definition pairs by calling it to have each node freed and then free the Hash Table itself
void freeHash(HASHENTRY *hashTable) {
	for(int i = 0; i < HASHSIZE; i++) {
		freeList(hashTable[i]);
	}
	free(hashTable);
}

//Prints the Entry which is the Hash Table and calls it to print its word and definition pairs
void printHash(HASHENTRY *hashTable) {
	for(int i = 0; i < HASHSIZE; i++) {
		printf("***********\n");
		printf(" Entry %d \n", i);
		printf("***********\n");
		printList(hashTable[i]);
	}
}

//Prints the Entry which is the Hash Table and its length which is how many word and definition pairs it has
void printLoad(HASHENTRY *hashTable) {
	for(int i = 0; i < HASHSIZE; i++) {
		printf("Entry %d: length= %d\n", i, listLen(hashTable[i]));
	}
}



