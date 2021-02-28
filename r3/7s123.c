#include <stdio.h>

int main(void)
{
	float cal = 2.54;
	int wzrost;

	printf("Podaj swoj wzrost w centymetrach: ");
	scanf("%d", &wzrost);

	printf("Twoj wzrost w calach %f.\nTwoj wzrost w centymetrach %d.\n", wzrost / cal, wzrost);

	return 0;
}
