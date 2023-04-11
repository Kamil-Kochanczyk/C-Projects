/* Kamil Kochańczyk */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student
{
	char name[30];
	char surname[30];
	char grades[30][6];
	int number_of_grades;
};

int compare(const void* x, const void* y);

void normalize(char* str);

int is_float_grade(char* grade, float* pointer);

float convert(char* grade);

int main(int argc, char* argv[])
{
	struct Student group[30];
	int number_of_students, i, j, k, l, m, found, to_average, number_of_wrong_grades;
	char name[30], surname[30], grade[6];
	FILE* ptr;
	float sum_of_one, sum_of_all, converted_grade, average_of_one;
	char wrong_grades[30][6];

	if (argc < 2)
	{
		fprintf(stderr, "Error - program needs filenames as arguments\n");
		return 1;
	}
	
	for (i = 1; i < argc; i++)
	{
		ptr = fopen(argv[i], "r");

		if (ptr == NULL)
		{
			fprintf(stderr, "Error - program couldn't read file %s\n\n\n\n\n", argv[i]);
			continue;
		}

		number_of_students = 0;

		while (fscanf(ptr, "%s %s %s", name, surname, grade) == 3)
		{
			normalize(name);
			normalize(surname);
			
			found = 0;
			
			for (j = 0; j < number_of_students; j++)
			{
				if ((strcmp(name, group[j].name) == 0) && (strcmp(surname, group[j].surname) == 0))
				{
					found++;
					break;
				}
			}

			if (found)
			{
				strcpy(group[j].grades[group[j].number_of_grades], grade);
				group[j].number_of_grades++;
			}
			else
			{
				strcpy(group[number_of_students].name, name);
				strcpy(group[number_of_students].surname, surname);
				
				strcpy(group[number_of_students].grades[0], grade);
				group[number_of_students].number_of_grades = 1;
				
				number_of_students++;
			}
		}

		qsort((void*)group, number_of_students, sizeof(struct Student), compare);

		printf("Students and grades from file %s:\n", argv[i]);
		printf("----------------------------------------------------------------------------------------------------\n");

		sum_of_all = 0;
		
		for (k = 0; k < number_of_students; k++)
		{
			printf("%s %s:", group[k].surname, group[k].name);

			sum_of_one = 0;
			to_average = group[k].number_of_grades;
			number_of_wrong_grades = 0;
			
			for (l = 0; l < group[k].number_of_grades; l++)
			{
				printf(" %s ", group[k].grades[l]);

				converted_grade = convert(group[k].grades[l]);

				if (converted_grade < 0)
				{
					to_average--;
					strcpy(wrong_grades[number_of_wrong_grades], group[k].grades[l]);
					number_of_wrong_grades++;
				}
				else
				{
					sum_of_one += converted_grade;
				}
			}

			average_of_one = (to_average != 0) ? (sum_of_one / to_average) : 0;
			
			printf(": %.2f\n", average_of_one);
			
			if (number_of_wrong_grades != 0)
			{
				fprintf(stderr, "Incorrect grades:");
				
				for (m = 0; m < number_of_wrong_grades; m++)
				{
					fprintf(stderr, " %s ", wrong_grades[m]);
				}
				
				printf("\n");
			}
			
			printf("\n");
			
			sum_of_all += average_of_one;
		}
		
		if (number_of_students != 0)
		{
			printf("Average of all students: %.2f\n", sum_of_all / (float)number_of_students);
		}
		
		printf("----------------------------------------------------------------------------------------------------\n\n\n\n\n");
	}

	return 0;
}

int compare(const void* x, const void* y)
{
	struct Student s1;
	struct Student s2;
	int result;

	s1 = *((struct Student*)x);
	s2 = *((struct Student*)y);
	result = strcmp(s1.surname, s2.surname);

	if (result)
	{
		return result;
	}
	else
	{
		return strcmp(s1.name, s2.name);
	}
}

void normalize(char* str)
{
	str[0] = toupper(str[0]);
	
	int i;
	for (i = 1; i < strlen(str); i++)
	{
		str[i] = tolower(str[i]);
	}
}

int is_float_grade(char* grade, float* pointer)
{
	float number;
	char* error;
	int ret;
	
	number = (float)strtod(grade, &error);
	ret = 1;
	*pointer = number;
	
	if (*error != '\0')
	{
		ret = 0;
	}
	
	return ret;
}

float convert(char* grade)
{
	int length = strlen(grade);
	float result;
	float ret;
	char new_grade[6];
	
	if (grade[0] == '+')
	{
		if (is_float_grade(grade, &result))
		{
			if (result == 2 || result == 3 || result == 4 || result == 5)
			{
				ret = result + 0.25;
			}
			else
			{
				ret = -1;
			}
		}
	}
	else if (grade[0] == '-')
	{
		if (is_float_grade(grade, &result))
		{
			if (result == -2 || result == -3 || result == -4 || result == -5)
			{
				ret = (result * (-1)) - 0.25;
			}
			else
			{
				ret = -1;
			}
		}
	}
	else if (grade[length - 1] == '+' || grade[length - 1] == '-')
	{
		int i, j;
		
		j = 0;
		
		for (i = 0; i < 6; i++)
		{
			if (grade[i] == '+' || grade[i] == '-')
			{
				continue;
			}
			
			new_grade[j] = grade[i];
			j++;
		}

		if (is_float_grade(new_grade, &result) && (result == 2 || result == 3 || result == 4 || result == 5))
		{
			ret = (grade[length - 1] == '+') ? (result + 0.25) : (result - 0.25);
		}
		else
		{
			ret = -1;
		}
	}
	else
	{
		ret = -1;
		
		if (is_float_grade(grade, &result))
		{
			if (result == 0 || (result >= 2 && result <= 5))
			{
				ret = result;
			}
		}
	}
	
	return ret;
}

