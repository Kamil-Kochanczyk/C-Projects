/* Kamil Kochańczyk */

#include <stdio.h>
#include "BitOperations.h"

#define MAX 3

union U
{
	char c;
	int i;
	float f;
	double d;
	
	struct
	{
		unsigned int group1 : 8;
		unsigned int group2 : 8;
		unsigned int group3 : 8;
		unsigned int group4 : 8;
		unsigned int group5 : 8;
		unsigned int group6 : 8;
		unsigned int group7 : 8;
		unsigned int group8 : 8;
	} auxiliary;
} values_union;

unsigned int get_group(union U* u, int number)
{
	unsigned int group;
	
	switch (number)
	{
		case 1:
			group = u->auxiliary.group1;
			break;
		case 2:
			group = u->auxiliary.group2;
			break;
		case 3:
			group = u->auxiliary.group3;
			break;
		case 4:
			group = u->auxiliary.group4;
			break;
		case 5:
			group = u->auxiliary.group5;
			break;
		case 6:
			group = u->auxiliary.group6;
			break;
		case 7:
			group = u->auxiliary.group7;
			break;
		case 8:
			group = u->auxiliary.group8;
			break;
		default:
			group = 0;
			break;
	}
	
	return group;
}

void edit_group(union U* u, int number, unsigned int new)
{
	switch (number)
	{
		case 1:
			u->auxiliary.group1 = new;
			break;
		case 2:
			u->auxiliary.group2 = new;
			break;
		case 3:
			u->auxiliary.group3 = new;
			break;
		case 4:
			u->auxiliary.group4 = new;
			break;
		case 5:
			u->auxiliary.group5 = new;
			break;
		case 6:
			u->auxiliary.group6 = new;
			break;
		case 7:
			u->auxiliary.group7 = new;
			break;
		case 8:
			u->auxiliary.group8 = new;
			break;
	}
}

void display(int bytes, int* positions_to_color, union U* union_pointer)
{
	int reset, iterator;
	
	reset = 0;
	for (iterator = bytes; iterator >= 1; iterator--)
	{
		if (iterator == 1)
		{
			reset = 1;
		}
		
		print_char(get_group(union_pointer, iterator), positions_to_color, (bytes * 8) - 1, reset);
	}
}

void manipulate(union U* union_pointer, int* positions, int bits, char type)
{
	int iterator, index, group_number;
	unsigned int original, changed;
	char (*function_pointer)(char, int);
	
	for (iterator = 1; iterator <= 3; iterator++)
	{
		switch (iterator)
		{
			case 1:
				function_pointer = zero_bit;
				printf("zero_bit:\n");
				break;
			case 2:
				function_pointer = flip_bit;
				printf("flip_bit:\n");
				break;
			case 3:
				function_pointer = set_bit;
				printf("set_bit:\n");
				break;
		}
		
		for (index = 0; index < MAX; index++)
		{
			if (positions[index] > bits - 1)
			{
				continue;
			}
			
			group_number = (positions[index] / 8) + 1;
			original = get_group(union_pointer, group_number);
			changed = function_pointer(original, positions[index] % 8);
			edit_group(union_pointer, group_number, changed);
			
			display(bits / 8, positions, union_pointer);
			switch (type)
			{
				case 'i':
					printf("\t%d\t", union_pointer->i);
					break;
				case 'f':
					printf("\t%f\t", union_pointer->f);
					break;
				case 'd':
					printf("\t%lf\t", union_pointer->d);
					break;
			}
			printf("(position %d)\n", positions[index]);
			
			edit_group(union_pointer, group_number, original);
		}
		
		printf("\n");
	}
}

int main()
{
	printf("\033[1;37m");

	int positions[MAX] = { 0, 31, 63 };

	char c;
	int i;
	float f;
	double d;
	
	printf("Enter a character: ");
	scanf("%c", &c);
	printf("\n");
	
	printf("Enter an integer: ");
	scanf("%d", &i);
	printf("\n");
	
	printf("Enter a real number (float): ");
	scanf("%f", &f);
	printf("\n");
	
	printf("Enter a real number (double): ");
	scanf("%lf", &d);
	printf("\n");
	
	int iterator, index;
	char (*function_pointer)(char, int);
	char before_manipulation;
	union U* union_pointer = &values_union;
	
	printf("------------------------------------------------------------\n\n");
	
	values_union.c = c;
	
	printf("Original char:\n");
	print_char(values_union.c, positions, 7, 1);
	printf("\t%-4d\t%c\n\n", values_union.c, values_union.c);
	
	for (iterator = 1; iterator <= 3; iterator++)
	{
		switch (iterator)
		{
			case 1:
				function_pointer = zero_bit;
				printf("zero_bit:\n");
				break;
			case 2:
				function_pointer = flip_bit;
				printf("flip_bit:\n");
				break;
			case 3:
				function_pointer = set_bit;
				printf("set_bit:\n");
				break;
		}
		
		for (index = 0; index < MAX; index++)
		{
			if (positions[index] > 7)
			{
				continue;
			}
			
			before_manipulation = values_union.c;
			values_union.c = function_pointer(before_manipulation, positions[index]);
			
			print_char(values_union.c, positions, 7, 1);
			printf("\t%-4d\t%c\t", values_union.c, values_union.c);
			printf("(position %d)\n", positions[index]);
			
			values_union.c = before_manipulation;
		}
		
		printf("\n");
	}
	
	printf("\n");
	
	printf("------------------------------------------------------------\n\n");
	
	values_union.i = i;
	printf("Original int:\n");
	display(4, positions, union_pointer);
	printf("\t%d\n\n", values_union.i);
	manipulate(union_pointer, positions, 32, 'i');
	printf("\n");
	
	printf("------------------------------------------------------------\n\n");
	
	values_union.f = f;
	printf("Original float:\n");
	display(4, positions, union_pointer);
	printf("\t%f\n\n", values_union.f);
	manipulate(union_pointer, positions, 32, 'f');
	printf("\n");
	
	printf("------------------------------------------------------------\n\n");
	
	values_union.d = d;
	printf("Original double:\n");
	display(8, positions, union_pointer);
	printf("\t%lf\n\n", values_union.d);
	manipulate(union_pointer, positions, 64, 'd');
	printf("\n");
	
	return 0;
}
