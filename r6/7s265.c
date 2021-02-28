#include <stdio.h>
#include <string.h>

int main(void)
{
	char slowo[] = "slowko";

	for (int i = strlen(slowo) - 1; i >= 0; i--)
		printf("%c", slowo[i]);

	printf("\n");

	return 0;
}