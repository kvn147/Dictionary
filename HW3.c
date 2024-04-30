/*
 * Kevin Nguyen
 * CSE222 - 3603
 * 02/23/2024
 * HW3.c
 * The Main Program takes command line argument for the dictionary file. It splits the first line as the word and second as its definition and so on. While the user does not CTRL^D, the program will look to recognize and call functions to the hash program such as to delete or load.
 */

#include "hash.h"

//Takes an argument from the command line
void main(int argc, char* argv[]) {

	//Declares the Hash Table to be used in the main program
	HASHENTRY *hashTable = initHash();

	int size = 0;
	int num;
	char temp[1024];
	char buffer[1024];
	char bufferWord[1024];
	char bufferDef[1024];
	char *word, *definition;
	
	//Checks if there was an argument
	if (argc == 2) {
		FILE *fp;
        	fp=fopen(argv[1], "r");
		if (fp == NULL) {
			printf("Can't open dictionary <%s> - goodbye\n", argv[1]);
			return;
		}
		//Splits the Dictionary file by word and definition lines
		while(NULL != fgets(bufferWord,sizeof(bufferWord),fp)) {
			bufferWord[strlen(bufferWord)-1] = '\0';
			size++;
			word = strtok(bufferWord, "\0");
			fgets(bufferDef,sizeof(bufferDef),fp);
			bufferDef[strlen(bufferDef)-1] = '\0';		
			definition = strtok(bufferDef, "\0");
			
			//Adds the word and definition to a Hash Table
			addHash(hashTable, bufferWord, bufferDef);
			}
	
		fclose(fp);
		}
		printf("> ");
		//While Loop until User inputs CTRL+D
		while (fgets(temp,120,stdin) != NULL) {
			//Initialize Matching State for if user input is invalid and print error message
			int matching = 0;
                	sscanf(temp, "%d", &num);
			//Replace the '\n' to null terminator at the end of the temp string
			temp[strlen(temp)-1]='\0';
				//If user input is begins with *
                    		if (temp[0] == '*') {
					char *star = strtok(temp, " ");
					//If stdin was *delete then call deleteHash to find a match for the stdin wordIn in the Hash Table or print an error if there is no wordIn, otherwise take it as a word that couldn't be matched
					if(strcmp(star, "*delete") == 0) {
						char *wordIn = strtok(NULL, "|");
						if(wordIn != NULL && deleteHash(hashTable, wordIn) == 1) {
							printf("Deleted <%s>\n", wordIn);
							matching = 1;
						}
						else {
							if (wordIn != NULL) {
							printf("ERROR: Can't delete word <%s>\n", wordIn);
							matching = 1;
							}
							else {
							matching = 0;
							}
						}
					}
					//If stdin was * then print all Hash Tables and their word and definition pairs by calling printHash
					else if(strcmp(star, "*") == 0) {
						char *wordIn = strtok(NULL, "|");
						if(wordIn == NULL) {
							printHash(hashTable);
							matching = 1;
						}
					}
					//If stdin was *load then print all Hash Tables and their length by calling printLoad
					else if(strcmp(star, "*load") == 0) {
						char *wordIn = strtok(NULL, "|");
						if(wordIn == NULL) {
							printLoad(hashTable);
							matching = 1;
						}
					}
                        	}
				//Else if user input is ?
				else if (temp[0] == '?') {
					//Print Help Message
        				printf("Command summary:\n * - print all words in the hashtable \n *load - print length of each linked list \n *delete word - delete word from hashtable \n word - print definition of the word \n ? - print this help message \n ^D - exit \n");
					matching = 1;
				}
				//Else if user input is ENTER key set matching state to 0 to print error message
				else if (strlen(temp) <= 1) {
					matching = 0;
				}
				
				//Else check if user input matches a word in a Hash Table by calling findHash
				else {
					if (findHash(hashTable, temp) != NULL) {
						printf("%s\n", findHash(hashTable, temp));
						matching = 1;
					}
					else {
						matching = 0;
					}
				}
		
			//If matching state is 0 then print error message
			if (matching == 0) {
				printf("No Matching Word \"%s\"\n", temp);
			}
			//Formatting for stdin
			printf("> ");
			
		}
		//Once user exits program print goodbye
		printf("Goodbye!\n");
		//Free Hash Tables
		freeHash(hashTable);	
}

