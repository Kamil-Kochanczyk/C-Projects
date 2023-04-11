#include <stdio.h>
#include <string.h>
#include "Auxiliary.h"

void method(char* message)
{
	int length = strlen(message);
	
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%c", *(message + i));
	}
	
	printf("\n");
}
