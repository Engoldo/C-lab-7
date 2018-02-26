#include "task3.h"

int main()
{
	FILE *fp = fopen("song.txt", "rt");
	if (fp == NULL)
	{
		puts("404! FIle not found!");
		return 1;
	}

	for (int i = 0; i < ASCII; i++)
	{
		syms[i].ch = i;
		syms[i].freq = 0;
	}

	readFile(fp, syms);
	freqCalc();
	qsort(syms, ASCII, sizeof(struct SYM), compare);
	print(syms);
	fclose(fp);
	return 0;
}