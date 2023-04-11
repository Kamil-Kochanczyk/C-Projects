/* Kamil Kochańczyk */

#include <stdio.h>
#include <stdlib.h>

int factorial_iteratively(int);

int factorial_recursively(int);

int main(int argc, char* argv[])
{	
	if (argc == 2)
	{
		char* error;
		int n = (int)strtod(argv[1], &error);
		
		if (*error != '\0')
		{
			printf("The input has to be a natural number\n");
			return -1;
		}
		
		int result_iteratively = factorial_iteratively(n);
		int result_recursively = factorial_recursively(n);
		
		if (result_iteratively < 0 || result_recursively < 0)
		{
			printf("The input has to be a positive number\n");
		}
		else
		{
			printf("%d! = %d (iteratively)\n", n, result_iteratively);
			printf("%d! = %d (recursively)\n", n, result_recursively);
		}
	}
	else
	{
		printf("The input has to one number\n");
	}	
	
	return 0;
}

int factorial_iteratively(int n)
{
	if (n >= 0)
	{
		int factorial = 1;
		
		int i;
		for (i = 1; i <= n; i++)
		{
			factorial *= i;
		}
		
		return factorial;
	}
	else
	{
		return -1;
	}
}

int factorial_recursively(int n)
{
	if (n < 0)
	{
		return -1;
	}
	else if (n == 0 || n == 1)
	{
		return 1;
	}
	else
	{
		return n * factorial_recursively(n - 1);
	}
}
