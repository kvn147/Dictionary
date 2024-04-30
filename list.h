/*
 * Kevin Nguyen
 * CSE222 - 3603
 * 02/23/2024
 * list.h
 * Linked List Header File has the struct node definition, struct node declarations, and linked list function prototypes to add/search/delete a word and its definition in a hash, free/print/list a hash table linked list
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
	char *word;
	char *def;
	struct node *next;
};

struct node *init();

struct node *newNode(char *word, char *def);

void add(struct node *handle, char *word, char *def);

char *find(struct node *handle, char *word);

int del(struct node *handle, char *word);

void freeList(struct node *handle);

void printList(struct node *handle);

int listLen(struct node *handle);

