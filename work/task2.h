#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

struct NODE
{
	int count;
	char word[SIZE];
	struct NODE *left;
	struct NODE *right;
};

char *chomp(char*buf);
struct NODE * makeTree(struct NODE *root, char *word);
int searchTree(struct NODE *root, char* words);
void printTree(struct NODE *root);

