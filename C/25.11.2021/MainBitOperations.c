#include <stdio.h>
#include "BitOperations.h"

int main()
{
	char c;
	printf("Enter a sigle character: ");
	scanf("%c", &c);
	printf("\n");
	
	printf("Bits of \'%c\': ", c);
	
	int bit;
	int i;
	for (i = 0; i < 8; i++)
	{
		bit = print_bit(c, i);
		printf("%d ", bit);
	}
	printf("\n\n");

	return 0;
}
