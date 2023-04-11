/* Kamil Kochańczyk */

#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, Delta;
	
	/*
	a = 1;
	b = 2;
	c = 1;
	*/
	
	/*
	a = 1;
	b = 2;
	c = 0;
	*/
	
	a = 1;
	b = 0;
	c = 1;
	
	Delta = (b * b) - (4 * a * c);
	
	if (Delta > 0)
	{
		double x1, x2;
		x1 = ((-b) - sqrt(Delta)) / (2 * a);
		x2 = ((-b) + sqrt(Delta)) / (2 * a);
		
		printf("x1 = %.2f \n", x1);
		printf("x2 = %.2f \n", x2);
	}
	else if (Delta == 0)
	{
		double x0;
		x0 = (-b) / (2 * a);
		
		printf("x0 = %.2f \n", x0);
	}
	else
	{
		double real_part, imaginary_part;
		real_part = (-b) / (2 * a);
		imaginary_part = sqrt(-Delta) / (2 * a);
		
		printf("x1 = %.2f - %.2fi \n", real_part, imaginary_part);
		printf("x2 = %.2f + %.2fi \n", real_part, imaginary_part);
	}

	return 0;
}
