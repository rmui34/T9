// Raymond Mui
// CSE374 Homework 5
// t9.c

/* This file contains all the necessary functions to replicate T9 texting. 
 * Takes in a given dictionary to create the trie word structure. When user 
 * is prompted for input values, the search function traverses the trie and finds 
 * the appropiate output. This is then printed and displayed in the linux terminal.
 *
 */

#include "t9.h"

//takes in user arguments and manages other T9 functions to display the appropiate
//output
void displayTrie(int argc, char** argv) {
	FILE* dict = fopen(argv[1], "r");
	char word[LENGTHOFLINE];
	Node* root = newNode(); // pointer to main root
	Node* temp;
	Link* current;
	while (fgets(word, LENGTHOFLINE, dict) != NULL) {
		word[strlen(word)-1] = '\0'; // removes new line char
		temp = root;
		for (int i = 0; i < strlen(word); i++) {
			temp = buildTrie(temp, word[i]);			
		}
		Link* wordStorage = LinkList(word);

		if (temp->firstWord == NULL) {
			temp->firstWord = wordStorage;
		} else {
			current = temp->firstWord;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = wordStorage;
		}
	}
	fclose(dict);	
	search(root);
	killTrie(root);
}

// Frees heap memory allocation of link list
void killLinks(Link* first) {
	if(first->next != NULL){
		killLinks(first->next);
	}
	free(first->word);
	free(first);
}

// Frees heap memory allocation of trie structure
void killTrie (Node* root) {
	if(root != NULL) {
		killTrie(root->key2);
		killTrie(root->key3);
		killTrie(root->key4);
		killTrie(root->key5);
		killTrie(root->key6);
		killTrie(root->key7);
		killTrie(root->key8);
	}
	killLinks(root->firstWord);
	free(root);

}

//creates tree structure
Node* buildTrie(Node* head, char letter) {
	switch(letter)	{
		// Checks for key2
		case 'a':
		case 'b':
		case 'c':
			buildTrieHelper(&head, &(head->key2));
			return head;
		// Checks for key3
		case 'd':
		case 'e':
		case 'f':
			buildTrieHelper(&head, &(head->key3));
			return head;
		// Checks for key 4
		case 'g':
		case 'h':
		case 'i':
			buildTrieHelper(&head, &(head->key4));
			return head;
		// Checks for key 5
		case 'j':
		case 'k':
		case 'l':
			buildTrieHelper(&head, &(head->key5));
			return head;
		// Checks for key 6
		case 'm':
		case 'n':
		case 'o':
			buildTrieHelper(&head, &(head->key6));
			return head;
		// Checks for key 7
		case 'p':
		case 'q':
		case 'r':
		case 's':
			buildTrieHelper(&head, &(head->key7));
			return head;
		// Checks for key 8	
		case 't':
		case 'u':
		case 'v':
			buildTrieHelper(&head, &(head->key8));
			return head;
		// Checks for key 9
		default:
			buildTrieHelper(&head, &(head->key9));
			return head;
	}
}

// Helps to build the Trie structure by moving the references
void buildTrieHelper(Node** current, Node** next) {
	if (*next == NULL) {
		*next = newNode();
		*current = *next;
	} else {
		*current = *next;
	}
}

// Takes given user input and traverses the tree to find matches of the word and prints it out.
void search(Node* root) {
	char userInput[LENGTHOFLINE];
	Node* current = root;
	printf("To Quit: Type \"exit\" and hit enter.\n");
	printf("Enter Key Sequence (enter \"#\" for the next word):\n");
	printf(">");
	Link* holdList;
	int boolean = 0;
	int count = 0;
	while(fgets(userInput, LENGTHOFLINE, stdin)) {

		current = root;
		if(strstr(userInput,"exit") != NULL) {
			exit(1);
		}
		if(userInput[0] == '#') {
			if (holdList != NULL && holdList->next != NULL) {
				holdList = holdList->next;
				printf("%s\n", holdList->word);
				boolean = 1;
			
			} else if (strstr(userInput,"#") && boolean == 1 ) {	
					printf("No more T9onyms\n");
			}
		} else {
			for (int i = 0; i < strlen(userInput)-1; i++) {
				if (current != NULL) {
						switch(userInput[i]) {
							case '#':
								if (i == 0) {
									holdList = current->firstWord;
								}
								count++;
								break;
							case '2':
								current = current->key2;
								break;
							case '3':
								current = current->key3;
								break;
							case '4':
								current = current->key4;
								break;
							case '5':
								current = current->key5;
								break;
							case '6':
								current = current->key6;
								break;
							case '7':
								current = current->key7;
								break;
							case '8':
								current = current->key8;
								break;
							case '9':
								current = current->key9;
								break;
							default:
								fprintf(stderr, "ERROR!: Please enter a \"#\" or a key value.\n");
								break;
						}
				 }
			}
			if (count == 0 ) {
				if (current != NULL && current->firstWord != NULL) {
						holdList = current->firstWord;
						printf("%s\n", holdList->word);
				} else {
						printf("Word is not found in the dictionary.\n");
				}
			} else {
				while (count > 0 && holdList != NULL && holdList->next != NULL) {
					holdList = holdList->next;
					count--;
				}
				if (count == 0) {
					printf("%s\n", holdList->word);
				} else {
					printf("Word is not found in the dictionary\n");
				}
			}
		}
		
	}
}
