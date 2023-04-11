/* Kamil Kochańczyk */

/*
Generator 1: <0; RAND_MAX) -> rand()
Generator 2: <0; 1) -> srand48(), drand48()
*/

#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(double*, double*);

void bubble_sort(double*, int);

int partition(double*, int, int);

void quick_sort(double*, int, int);

int compare(const void*, const void*);

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
		int i, j;
		int max;
		int asterisks;
		clock_t start;
		clock_t stop;
		double difference;
		double* new_numbers;
		double* new_intervals;
		
		numbers = malloc(how_many_numbers * sizeof(double));
		intervals = calloc(how_many_intervals, sizeof(double));
		
		for (i = 0; i < how_many_numbers; i++)
		{
			numbers[i] = drand48();
			intervals[(int)(numbers[i] * how_many_intervals)]++;
		}
		
		max = intervals[0];
		
		for (i = 0; i < how_many_intervals; i++)
		{
			if (intervals[i] > max)
			{
				max = intervals[i];
			}
		}
		
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
		printf("\n");
		
		start = clock();
		/*bubble_sort(numbers, how_many_numbers);*/
		/*quick_sort(numbers, 0, how_many_numbers - 1);*/
		qsort((void*)numbers, how_many_numbers, sizeof(double), compare);
		stop = clock();
		
		difference = (stop - start) / (double)CLOCKS_PER_SEC;
		
		printf("Time: %lf s\n\n", difference);
		
		new_numbers = malloc((how_many_numbers - 1) * sizeof(double));
		new_intervals = calloc(how_many_intervals, sizeof(double));
		
		for (i = 0; i < how_many_numbers - 1; i++)
		{
			new_numbers[i] = numbers[i + 1] - numbers[i];
			new_intervals[(int)(new_numbers[i] * how_many_intervals)]++;
		}
		
		max = new_intervals[0];
		
		for (i = 0; i < how_many_intervals; i++)
		{
			if (new_intervals[i] > max)
			{
				max = new_intervals[i];
			}
		}
		
		for (i = 0; i < how_many_intervals; i++)
		{
			asterisks = (int)((new_intervals[i] * 78.0 / max) + 0.5);
			
			printf("(%d) ", asterisks);
			
			for (j = 1; j <= asterisks; j++)
			{
				printf("%c", '*');
			}
			printf("\n");
		}
		printf("\n");
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

void swap(double* x, double* y)
{
	double temporary = *x;
	*x = *y;
	*y = temporary;
}

void bubble_sort(double* array, int length)
{
	int swapped;
	int i;
	int auxiliary = 0;
	
	do
	{
		swapped = 0;
		
		for (i = 0; i < length - auxiliary - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array + i, array + i + 1);
				swapped = 1;
			}
		}
		
		auxiliary++;
	} while (swapped);
}

int partition(double* array, int start, int end)
{
	double pivot;
	int pivot_index;
	int i;
	
	pivot = array[end];
	pivot_index = start;
	
	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array + i, array + pivot_index);
			pivot_index++;
		}
	}
	
	swap(array + pivot_index, array + end);
	
	return pivot_index;
}

void quick_sort(double* array, int start, int end)
{
	if (start < end)
	{
		int pivot_index = partition(array, start, end);
		
		quick_sort(array, start, pivot_index - 1);
		quick_sort(array, pivot_index + 1, end);
	}
}

int compare(const void* x, const void* y)
{
	if ((*(double*)x) < (*(double*)y))
	{
		return -1;
	}
	else if ((*(double*)x) > (*(double*)y))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

