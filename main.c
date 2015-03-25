//Raymond Mui
//CSE 374 Homework 5
//2.19.2015
// The main function checks for appropiate number of arguments otherwise throws and error
// requesting the appropiate inputs.

#include "t9.h"

int main(int argc, char** argv) {
	if (argc > 1) {
		displayTrie(argc, argv);
	}else {
		fprintf(stderr, "Need Two Arguments\n");
	}
	return 0;
}
