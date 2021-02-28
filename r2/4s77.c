#include <stdio.h>

void funkcja1(void);
void funkcja2(void);

int main(void)
{
	funkcja1();
	funkcja1();
	funkcja2();

	return 0;
}

void funkcja1(void)
{
	printf("Panie Janie!\n");
}

void funkcja2(void)
{
	printf("Rano wstan!\n");
}
