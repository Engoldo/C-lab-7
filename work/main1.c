#include "task1.h"

int main()
{
	FILE *fp = fopen("fips10_4.csv", "rt");;
	int count = 0;
	char buf[512];
	PITEM head, tail, item;

	if (!fp)
	{
		puts("404!");
		return 1;
	}

	while (fgets(buf, 512, fp))
	{
		if (count == 0)
		{
			head = mklist(create(buf));
			tail = head;
		}
		else
		{
			tail = addTail(tail, create(buf));
		}
		count++;
	}
	fclose(fp);

	printf("Total items in file: %d\n", countList(head));
	item = searchByAbr(head, "RU");
	print(item);
	item = searchByName(head, "Dubayy");
	print(item);

	return 0;
}