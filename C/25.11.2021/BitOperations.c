#include "BitOperations.h"

int print_bit(char c, int position)
{
	position = 7 - position;

	int mask = 1 << position;
	
	return (c & mask) >> position;
}
