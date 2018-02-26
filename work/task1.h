#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

struct COUNTRY
{
	char unid[3];
	char abr[3];
	char name[256];
};

typedef struct COUNTRY COUNTRY;
typedef COUNTRY * PCOUNTRY;

struct ITEM
{
	PCOUNTRY countries;
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM ITEM;
typedef ITEM * PITEM;

PITEM mklist(PCOUNTRY countries);
PCOUNTRY create(char* line);
PITEM addTail(PITEM tail, PCOUNTRY countries);
char* copySub(char *where, char *to);
int checkLine(char* line);
int countList(PITEM head);
PITEM searchByAbr(PITEM head, char *abr);
PITEM searchByName(PITEM head, char *name);
void print(PITEM item);