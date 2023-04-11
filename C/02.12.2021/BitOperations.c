/* Kamil Kochańczyk */

#include <stdio.h>
#include <math.h>
#include "BitOperations.h"

#define MAX 3

int print_bit(char c, int position)
{
	if (position > 7)
	{
		return -1;
	}
	else
	{
		int mask = 1 << position;
		return (c & mask) >> position;
	}
}

void print_char(char c, int* positions_to_color, int start, int reset)
{
	static int calls = 1;
	static int current_position = -1;
	static int already_colored = 0;
	
	if (calls == 1)
	{
		current_position = start;
	}
	
	int i, j, found;
	for (i = 7; i >= 0; i--)
	{
		found = 0;
		
		for (j = 0; j < MAX; j++)
		{
			if (current_position == positions_to_color[j])
			{
				found = 1;
				break;
			}
		}
		
		if (found)
		{
			switch (already_colored)
			{
				case 0:
					printf("\033[1;31m");
					break;
				case 1:
					printf("\033[1;32m");
					break;
				case 2:
					printf("\033[1;33m");
					break;
				case 3:
					printf("\033[1;34m");
					break;
				case 4:
					printf("\033[1;35m");
					break;
				default:
					printf("\033[1;36m");
					break;
			}
			
			already_colored++;
		}
		
		printf("%d", print_bit(c, i));
		printf("\033[1;37m");
		
		current_position--;
	}
	
	if (reset)
	{
		calls = 1;
		already_colored = 0;
	}
	else
	{
		calls++;
	}
}

char zero_bit(char c, int position)
{
	int mask = ~(1 << position);
	return c & mask;
}

char flip_bit(char c, int position)
{
	int mask = 1 << position;
	return c ^ mask;
}

char set_bit(char c, int position)
{
	int mask = 1 << position;
	return c | mask;
}
