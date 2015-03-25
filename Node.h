//Raymond Mui
//CSE 374
//2.19.15
//Node Header file.

// This file sets up the Node Trie structure. Each node has 8 pointers to more nodes and a 
// link list of words to store the dictionary

#ifndef NODE_H
#define NODE_H

struct Nodes* newNode(); 
struct Linker* LinkList(char* word); 

struct Nodes {
	struct Nodes* key2;
	struct Nodes* key3;
	struct Nodes* key4;
	struct Nodes* key5;
	struct Nodes* key6;
	struct Nodes* key7;
	struct Nodes* key8;
	struct Nodes* key9;
	struct Linker* firstWord;
};

struct Linker {
	char* word;
	struct Linker* next;
};


typedef struct Nodes  Node;
typedef struct Linker Link;


 
#endif
