/*
 * Kevin Nguyen
 * CSE222 - 3603
 * 02/23/2024
 * list.c
 * list.c handles all functions used in the hash program in doing the functions for the linked lists in the hash table such as to add/search/delete word and defintion pairs and to free/print/list the linked list of the hash table
 */
#include "list.h"

//Initializes a node with a word and definition and a pointer to the next node
struct node *init() {
	struct node *temp;
	temp = malloc(sizeof(struct node));
	temp->word = NULL;
	temp->def = NULL;
	temp->next = NULL;
	return temp;
}

//newNode is used to point the current node to the next new node with space for the null terminator
struct node *newNode(char *word, char *def) {
	struct node* temp;
	temp = malloc(sizeof(struct node));
	
	if (temp != NULL) {
		temp->word = malloc(strlen(word) + 1);
		temp->def = malloc(strlen(def) + 1);
		if(temp->word != NULL && temp->def != NULL) {
			strcpy(temp->word, word);
			strcpy(temp->def, def);
			temp->next = NULL;
		}
		else {
			free(temp);
			temp = NULL;
		}
	return temp;
	}
}

//Add word and definition pair to the linked list
void add(struct node *handle, char *word, char *def) {
	struct node *temp; //Create temp node
	temp = handle; //Temp points to sentinel node
	
	struct node *newNodePtr;
	newNodePtr = newNode(word, def); //Create new node pointer to word and its definition
	
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNodePtr;
}

//Search for  a word in a hash table linked list
char *find(struct node *handle, char *word) {
	struct node *temp;
	temp = handle->next;

	while (temp != NULL) {
		if (strcmp(temp->word, word) == 0) {
			return temp->def;
		}
		temp = temp->next;
	}
	return NULL;
}

//Delete goes through a linked list and looks for a matching word from stdin and if found is deleted and returns 1 else it will return 0
int del(struct node *handle, char *word) {
	struct node *temp; //Create temp node
	temp = handle->next; //Temp points to sentinel node
	struct node *prev;
	prev = handle;

	while (temp != NULL) {
		//If the next city name of the list is the same as the user's city name
		if (strcmp(temp->word, word) == 0) {
			prev->next = temp->next;
			free(temp->word);
			free(temp->def);
			free(temp);
			return 1;
		}
		prev = temp;
		temp = temp->next;
	}
	return 0;
}

//Prints the word and its definition in the linked list
void printList(struct node *handle) {
	struct node *temp; //Create temp node
       	temp = handle->next; //Temp points to the node after the sentinel node
	
	while (temp != NULL) {
		printf("Word: \"%s\", Def=\"%s\"\n", temp->word, temp->def);
		temp = temp->next;
	}
}

//Calculates the length of the linked list for the load command
int listLen(struct node *handle) {
	struct node *temp;
	temp = handle->next;
	int i = 1;
	while(temp != NULL) {
		temp = temp->next;
		i++;
		}
	return i;
}

//clean goes through the list from sentinel to end to free allocated memory
void freeList(struct node *handle) {
	struct node *temp = handle->next;
	struct node *prev;

	while (temp != NULL) {
		prev = temp;
		temp = temp->next;
		free(prev->word);
		free(prev->def);
		free(prev);
	}
	free(handle);
}

