#include "task2.h"

int main(int argc, char* argv[])
{
	char* buf = 0;
	char words[SIZE];
	struct NODE *root = NULL;
	char ch = 0;
	int i = 0;

	FILE *fp = fopen("keyWords.txt", "rt");

	if (fp == NULL)
	{
		puts("404!");
		return 1;
	}

	while (fgets(words, 256, fp))
	{
		buf = chomp(words);
		root = makeTree(root, buf);
	}
	fclose(fp);

	FILE *fpf = fopen("cFile.c", "rt");

	if (fpf == NULL)
	{
		puts("404!");
		return 1;
	}

	while (ch != EOF)
	{
		ch = fgetc(fpf);
		if (ch == '\t')
			continue;
		words[i] = ch;
		if (words[i] == ' ' || words[i] == '\n' || words[i] == '(' || words[i] == ';' || words[i] == '*')
		{
			words[i] = 0;
			searchTree(root, words);
			i = -1;
		}
		i++;
	}
	printTree(root);
	fclose(fpf);

	return 0;
}