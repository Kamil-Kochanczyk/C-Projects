/* Kamil Kochańczyk */

#include <stdio.h>
#include <stdlib.h>

unsigned int iteratively(unsigned int n);

unsigned int recursively(unsigned int n);

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		char* error;
		unsigned int n = (unsigned int)strtod(argv[1], &error);

		if (*error != '\0')
		{
			printf("Input has to be a natural number\n");
			return -1;
		}

		unsigned int result_iteratively = iteratively(n);
		unsigned int result_recursively = recursively(n);

		if (result_iteratively < 0 || result_recursively < 0)
		{
			printf("Input has to be a non-negative number\n");
		}
		else
		{
			printf("Fn = F%d = %d (iteratively)\n", n, result_iteratively);
			printf("Fn = F%d = %d (recursively)\n", n, result_recursively);
		}
	}
   	else
	{
		printf("Input has to be a single number\n");
	}	
	
	return 0;
}

unsigned int iteratively(unsigned int n)
{
	if (n >= 0)
	{
		if (n == 0 || n == 1)
		{
			return n;
		}
		else
		{
			unsigned int f0 = 0;
			unsigned int f1 = 1;
			unsigned int fn = 0;
			unsigned int i;
			for (i = 2; i <= n; i++)
			{
				fn = f0 + f1;
				f0 = f1;
				f1 = fn;
			}

			return fn;
		}
	}
	else
	{
		return -1;
	}
}

unsigned int recursively(unsigned int n)
{
	if (n >= 0)
	{
		if (n == 0 || n == 1)
		{
			return n;
		}
		else
		{
			return recursively(n - 1) + recursively(n - 2);
		}
	}
	else
	{
		return -1;
	}
}
