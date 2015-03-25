// Raymond Mui
// CSE 374 Homework 5
// 2.19.2015
// Node.c holds the functions that create new trie Nodes and linklists



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Node.h"



// Creates a new trie Node.
struct Nodes* newNode() {
	struct Nodes* trie = (struct Nodes*)malloc(sizeof(struct Nodes));
	trie->key2 = NULL;
	trie->key3 = NULL;
	trie->key4 = NULL;
	trie->key5 = NULL;
	trie->key6 = NULL;
	trie->key7 = NULL;
	trie->key8 = NULL;
	trie->key9 = NULL;
	trie->firstWord = NULL;
	return trie;
}

// Creates a new linklist.
struct Linker* LinkList(char* word) {
	struct Linker* list = (struct Linker*)malloc(sizeof(struct Linker));
	list->word = (char*)malloc(sizeof(char)*strlen(word));
	strncpy(list->word, word, strlen(word));
	list->next = NULL;
	return list;
}

