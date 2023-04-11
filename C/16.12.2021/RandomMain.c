/* Kamil Kochańczyk */

/*
Generator 1: <0; RAND_MAX) -> rand()
Generator 2: <0; 1) -> srand48(), drand48()
*/

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand48(time(0));

	int how_many_numbers;
	int how_many_intervals;
	
	printf("How many numbers? ");
	scanf("%d", &how_many_numbers);
	printf("How many intervals? ");
	scanf("%d", &how_many_intervals);
	printf("\n");
	
	if (how_many_numbers > 0 && how_many_intervals > 0)
	{
		double* numbers;
		double* intervals;
		
		numbers = malloc(how_many_numbers * sizeof(double));
		intervals = calloc(how_many_intervals, sizeof(double));
		
		int i, j;
		
		for (i = 0; i < how_many_numbers; i++)
		{
			numbers[i] = drand48();
			intervals[(int)(numbers[i] * how_many_intervals)]++;
		}
		
		int max;
		
		max = intervals[0];
		for (i = 0; i < how_many_intervals; i++)
		{
			if (intervals[i] > max)
			{
				max = intervals[i];
			}
		}
		
		int asterisks;
		
		for (i = 0; i < how_many_intervals; i++)
		{
			asterisks = (int)((intervals[i] * 78.0 / max) + 0.5);
			
			printf("(%d) ", asterisks);
			
			for (j = 1; j <= asterisks; j++)
			{
				printf("%c", '*');
			}
			
			printf("\n");
		}
	}
	else
	{
		if (how_many_numbers <= 0)
		{
			printf("how_many_numbers > 0\n");
		}
		
		if (how_many_intervals <= 0)
		{
			printf("how_many_intervals > 0\n");
		}
	}
	
	return 0;
}
