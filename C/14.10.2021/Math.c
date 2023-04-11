/* Kamil Kochańczyk */

#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	float f;
	double d;
	i = 10;
	f = 5;
	d = 0;
	printf("f + d = %f + %lf = %f \n", f, d, f + d);
	printf("\n");
	
	double w;
	w = 1 / 3;
	printf("%f \n", w);
	w = 1. / 3;
	printf("%f \n", w);
	printf("\n");
	
	printf("sin(f) = sin(%f) = %f \n", f, sin(f));
	printf("cos(d) = cos(%f) = %f \n", d, cos(d));
	printf("e^i = e^%d = %f \n", i, exp(i));
	printf("sqrt(-1) = %f \n", sqrt(-1));
	printf("asin(f / d) = asin(%f / %f) = %f \n", f, d, asin(f / d));
	printf("pi = acos(-1) = %f \n", acos(-1));
	
	return 0;
}
