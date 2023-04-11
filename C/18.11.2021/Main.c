/* Kamil Kochańczyk */

#include <stdio.h>
#include "FindRoot.h"
#include "Function.h"

int main()
{
	double a, b;
	printf("Enter the boundaries of the closed interval <a; b> (separated by space)\n");
	scanf("%lf %lf", &a, &b);
	printf("\n");
	
	double epsilon;
	printf("Enter the accuracy with which you want to find the root of a given function\n");
	scanf("%lf", &epsilon);
	printf("\n");
	
	int method;
	printf("Choose the method of finding the root\n");
	printf("1 - bisection method\n");
	printf("2 - secant method\n");
	scanf("%d", &method);
	printf("\n");
	
	int iterations;
	double x0;
	double fx0;
	
	iterations = find_root(a, b, epsilon, method, &x0);
	fx0 = function(x0);
	
	if (iterations < 0)
	{
		printf("No root found\n");
	}
	else
	{
		printf("x0 = %lf \n", x0);
		printf("fx0 = %lf \n", fx0);
		printf("Iterations: %d \n", iterations);
	}
	
	return 0;
}
