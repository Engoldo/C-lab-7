#include "task2.h"

char* chomp(char*buf)
{
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = '\0';
	return buf;
}

struct NODE * makeTree(struct NODE *root, char *add)
{
	if (root == NULL)
	{
		root = (struct NODE*)malloc(sizeof(struct NODE));
		strcpy(root->word, add);
		root->count = 0;
		root->left = root->right = NULL;
	}
	else if (strcmp(root->word, add)>0)
		root->left = makeTree(root->left, add);
	else if (strcmp(root->word, add)<0)
		root->right = makeTree(root->right, add);
	return root;
}

int searchTree(struct NODE *root, char* word)
{
	if (root == NULL)
	{
		return 1;
	}
	if (strcmp(root->word, word)>0)
	{
		return searchTree(root->left, word);
	}
	else if (strcmp(root->word, word)<0)
	{
		return searchTree(root->right, word);
	}
	else if (strcmp(root->word, word) == 0)
	{
		root->count++;
		return 0;
	}
	return 1;
}

void printTree(struct NODE *root)
{
	if (root != NULL)
	{
		printTree(root->left);
		printf("%s - %d\n", root->word, root->count);
		printTree(root->right);
	}
}
