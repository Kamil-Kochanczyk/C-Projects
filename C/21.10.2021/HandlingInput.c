/* Kamil Kochańczyk */

#include <stdio.h>
#include <math.h>

int main()
{
	int successfull_inputs = 0;
	double a, b, c, Delta;
	
	printf("Enter coefficients of quadratic equation ax^2 + bx + c = 0\n");
	
	do
	{
		printf("a = ");
		successfull_inputs = scanf("%lf", &a);
		getchar();
		
		if (successfull_inputs != 1)
		{
			printf("Wrong input\n");
		}
	} while (successfull_inputs != 1);
	
	do
	{
		printf("b = ");
		successfull_inputs = scanf("%lf", &b);
		getchar();
		
		if (successfull_inputs != 1)
		{
			printf("Wrong input\n");
		}
	} while (successfull_inputs != 1);
	
	do
	{
		printf("c = ");
		successfull_inputs = scanf("%lf", &c);
		getchar();
		
		if (successfull_inputs != 1)
		{
			printf("Wrong input\n");
		}
	} while (successfull_inputs != 1);
	
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
