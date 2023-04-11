/* Kamil Kochańczyk */

#include <stdio.h>
#include <stdlib.h>
#include "BOWP.h"

int print_bit(int* i, int position)
{
	if (position > 31)
	{
		return -1;
	}
	else
	{
		int mask = 1 << position;
		return abs((*i & mask) >> position);
	}
}

void print_int(int* i)
{	
	int j;
	for (j = 31; j >= 0; j--)
	{
		printf("%d", print_bit(i, j));
	}
}

int zero_bit(int* i, int position)
{
	int mask = ~(1 << position);
	return *i & mask;
}

int flip_bit(int* i, int position)
{
	int mask = 1 << position;
	return *i ^ mask;
}

int set_bit(int* i, int position)
{
	int mask = 1 << position;
	return *i | mask;
}
