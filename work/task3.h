#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ASCII 256

typedef struct SYM SYM;
struct SYM
{
	unsigned char ch;
	float freq;
};

SYM syms[ASCII];

void readFile(FILE *fp, SYM syms[]);
int compare(const void *a, const void *b);
void print(SYM syms[]);
void freqCalc();
