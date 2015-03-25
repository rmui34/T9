// Raymond Mui
// CSE374 Homework 5
// 2.19.15
// This file defines constants for t9.c and extern the functions external use. 
#ifndef T9_H
#define T9_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include"Node.h"

#define LENGTHOFLINE 100

extern Node* buildTrie(Node* head, char letter); // builds the Trie
extern void buildTrieHelper(Node** current, Node** next);//assists in the placement of Trie Nodes
extern void search(Node* current); //traverses the tree to find node location of word
extern void displayTrie(int argc, char** argv); 
extern void killTrie(Node* root); // frees the memory of Trie
extern void killLinks(Link* first); // frees the memory of linklist
#endif //T9_H
