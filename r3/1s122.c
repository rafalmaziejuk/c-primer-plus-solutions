#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	int przepelnienie_int;
	int MAX_INT = INT_MAX;

	float przepelnienie_float, niedomiar_float;
	float MIN_FLOAT = FLT_MIN;
	float MAX_FLOAT = FLT_MAX;

	przepelnienie_int = INT_MAX + 1;
	przepelnienie_float = FLT_MAX * 2.;
	niedomiar_float = FLT_MIN / 2.;

	// print results
	printf("Max int: %d\tMax int + 1: %d\n", MAX_INT, przepelnienie_int);
	printf("Max float: %f\tMax float * 2: %f\n", FLT_MAX, przepelnienie_float);
	printf("Min float: %f\tMin float / 2: %f\n", FLT_MIN, niedomiar_float);

	return 0;
}
