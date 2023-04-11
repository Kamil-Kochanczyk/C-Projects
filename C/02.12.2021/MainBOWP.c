/* Kamil Kochańczyk */

#include <stdio.h>
#include "BOWP.h"

int main()
{
	int i;
	float f;
	double d;
	int* pointer;
	
	printf("Enter an integer: ");
	scanf("%d", &i);
	printf("\n");
	
	printf("Enter a float: ");
	scanf("%f", &f);
	printf("\n");
	
	printf("Enter a double: ");
	scanf("%lf", &d);
	printf("\n");
	
	int j;
	int (*function_pointer)(int*, int);
	int manipulated_int;
	float manipulated_float;
	double manipulated_double;
	int* manipulated_pointer;
	
	printf("------------------------------------------------------------\n\n");
	
	pointer = &i;
	manipulated_pointer = &manipulated_int;
	
	printf("Original int:\n");
	print_int(pointer);
	printf("\t%d\n\n", i);

	for (j = 1; j <= 3; j++)
	{
		switch (j)
		{
			case 1:
				function_pointer = zero_bit;
				printf("zero_bit:\n");
				break;
			case 2:
				function_pointer = flip_bit;
				printf("flip-bit:\n");
				break;
			case 3:
				function_pointer = set_bit;
				printf("set_bit:\n");
				break;
		}
		
		*manipulated_pointer = function_pointer(pointer, 31);
		*manipulated_pointer = function_pointer(manipulated_pointer, 0);
		print_int(manipulated_pointer);
		printf("\t%d\n\n", manipulated_int);
	}

	printf("------------------------------------------------------------\n\n");
	
	pointer = &f;
	manipulated_pointer = &manipulated_float;
	
	printf("Original float:\n");
	print_int(pointer);
	printf("\t%f\n\n", f);

	for (j = 1; j <= 3; j++)
	{
		switch (j)
		{
			case 1:
				function_pointer = zero_bit;
				printf("zero_bit:\n");
				break;
			case 2:
				function_pointer = flip_bit;
				printf("flip-bit:\n");
				break;
			case 3:
				function_pointer = set_bit;
				printf("set_bit:\n");
				break;
		}
		
		*manipulated_pointer = function_pointer(pointer, 31);
		*manipulated_pointer = function_pointer(manipulated_pointer, 0);
		print_int(manipulated_pointer);
		printf("\t%.7f\n\n", manipulated_float);
	}
	
	printf("------------------------------------------------------------\n\n");
	
	pointer = &d;
	
	printf("Original double:\n");
	pointer++;
	print_int(pointer);
	pointer--;
	print_int(pointer);
	printf("\t%lf\n\n", d);
	
	for (j = 1; j <= 3; j++)
	{
		switch (j)
		{
			case 1:
				function_pointer = zero_bit;
				printf("zero_bit:\n");
				break;
			case 2:
				function_pointer = flip_bit;
				printf("flip-bit:\n");
				break;
			case 3:
				function_pointer = set_bit;
				printf("set_bit:\n");
				break;
		}
		
		manipulated_double = d;
		manipulated_pointer = &manipulated_double;
		
		/* Accessing, manipulating and printing bits on positions form 32 to 63 */
		pointer++;
		manipulated_pointer++;
		
		*manipulated_pointer = function_pointer(pointer, 31);
		print_int(manipulated_pointer);
		
		/* Accessing, manipulating and printing bits on positions from 0 to 31 */
		pointer--;
		manipulated_pointer--;
		
		*manipulated_pointer = function_pointer(manipulated_pointer, 0);
		print_int(manipulated_pointer);
		
		/* Displaying manipulated value */
		printf("\t%.15lf\n\n", manipulated_double);
	}
	
	return 0;
}
