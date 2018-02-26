#include "task3.h"

extern int count = 0;

void print(SYM syms[])
{
	printf("Sorted symbols: \n");
	printf("----------------\n");
	for (int i = 0; i < ASCII; i++)
	{
		if (syms[i].freq > 0)
			printf("Sorted Symbol: %c - %f  \n", syms[i].ch, syms[i].freq);
	}
}

void readFile(FILE *fp, SYM syms[])
{
	int sym;
	int symNum; 
	
	while ((symNum = fgetc(fp)) != EOF) //while (!feof(fp)) - can be also used
	{
		syms[(char)symNum].freq++;
		count++;
	}
}

void freqCalc()
{
	for (int i = 0; i < ASCII; i++)
	{
		syms[i].freq = syms[i].freq / count;
	}
}

int compare(const void *a, const void *b)
{
	//Если не использовать *1000 то разница в вычитании типа float крайне мала и при преобразовании в int система засчитает разницу как 0
	return (int)(1000 * (((struct SYM*)b)->freq - ((struct SYM*)a)->freq));
}