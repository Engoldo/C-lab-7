#include "task1.h"

PITEM mklist(PCOUNTRY countries)
{
	PITEM item = (PITEM)malloc(sizeof(ITEM));
	item->countries = countries;
	item->prev = NULL;
	item->next = NULL;
	return item;
}

PCOUNTRY create(char *line)
{
	int i = 0;
	PCOUNTRY region = (PCOUNTRY)malloc(sizeof(COUNTRY));
	while (*line && *line != ',')
	{
		region->abr[i] = *line;
		i++;
		line++;
	}
	region->abr[i] = '\0';
	line++;
	i = 0;
	while (*line && *line != ',')
	{
		region->unid[i] = *line;
		i++;
		line++;
	}
	region->unid[i] = '\0';
	i = 0;
	line += 2;

	while (*line)
	{
		region->name[i] = *line;
		i++;
		line++;
	}
	region->name[i - 2] = '\0';

	return region;
}

PITEM addTail(PITEM tail, PCOUNTRY countries)
{
	PITEM item = mklist(countries);
	if (tail != NULL)
	{
		tail->next = item;
		item->prev = tail;
	}
	return item;
}

void setStruct(PCOUNTRY country, char *line)
{
	char tmp[4];
	char *p = line;

	p = copySub(p, tmp); //id
	p = copySub(p + 1, country -> abr);
	p = copySub(p + 1, country -> name);
}

char* copySub(char *from, char *to)
{
	while (*from != ','  &&
		*from != '\n' &&
		*from != '\0')
		*to++ = *from++;
	*to = '\0';
	return from;
}

int checkLine(char*line)
{
	char tmp[256];
	char *p = line;

	p = copySub(p, tmp); // id
	if (strlen(tmp) != 3)
		return 0;
	if (atoi(tmp) == 0)
		return 0;
	p = copySub(p + 1, tmp); // AA
	if (strlen(tmp) != 2)
		return 0;
	
	return 1;
}

int countList(PITEM head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head -> next;
	}
	return count;
}

PITEM searchByAbr(PITEM head, char *abr)
{
	while (head)
	{
		if (strcmp(head -> countries -> abr, abr) == 0)
			return head;
		head = head -> next;
	}
	return NULL;
}

PITEM searchByName(PITEM head, char *name)
{
	while (head)
	{
		if (strcmp(head -> countries -> name, name) == 0)
			return head;
		head = head -> next;
	}
	return NULL;
}

void print(PITEM item)
{
	if (item != NULL)
	{
		puts(item -> countries -> abr);
		puts(item -> countries -> unid);
		puts(item -> countries -> name);
	}
}