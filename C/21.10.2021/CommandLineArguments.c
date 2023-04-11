/* Kamil Kochańczyk */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
	int i, j, k;

	printf("argc = %d \n", argc);
	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s \n", i, argv[i]);
	}
	printf("\n");
	
	int valid = 1;
	
	for (j = 1; j < argc; j++)
	{
		int length = strlen(argv[j]);
		
		for (k = 0; k < length; k++)
		{
			if (isdigit(argv[j][k]) || argv[j][k] == '.')
			{
				continue;
			}
			else if (argv[j][k] == '-')
			{
				if (k != 0)
				{
					valid = 0;
					break;
				}
			}
			else
			{
				valid = 0;
				break;
			}
		}
		
		if (!valid)
		{
			break;
		}
	}

	if (valid && argc == 4)
	{
		double a, b, c, Delta;
		char* pointer;
		
		/*
		a = atof(argv[1]);
		b = atof(argv[2]);
		c = atof(argv[3]);
		*/
		
		a = strtod(argv[1], &pointer);
		b = strtod(argv[2], &pointer);
		c = strtod(argv[3], &pointer);
		
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
	}
	else
	{
		printf("Wrong input\n");
		
		if (!valid)
		{
			printf("Input should be real numbers\n");
		}
		
		if (argc != 4)
		{
			printf("There should be three real numbers\n");
		}
	}
	
	return 0;
}
