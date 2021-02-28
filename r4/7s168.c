#include <stdio.h>
#include <float.h>

int main(void)
{
	double dbl = 1.0 / 3.0;
	float  flt = 1.0 / 3.0;

	printf("%.4f %.4f\n", dbl, flt);
	printf("%.12f %.12f\n", dbl, flt);
	printf("%.16f %.16f\n", dbl, flt);
	printf("%d %d\n", DBL_DIG, FLT_DIG);

	return 0;
}
