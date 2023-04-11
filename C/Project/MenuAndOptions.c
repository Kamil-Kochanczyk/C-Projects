/* Kamil Kochańczyk */

#define _POSIX_C_SOURCE 199309L

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t get_time();

/* W tej tablicy będą przechowywane wszystkie opcje dostępne w menu. */
Option options[] = 
{
	{ "Reaction Time", ReactionTime, -1, "ms" },
	{ "Number Memory", NumberMemory, -1, "digit(s) remembered" },
	{ "Verbal Memory", VerbalMemory, -1, "level(s)" },
	{ "High Scores", HighScores, -1, "" },
	{ "Exit", Exit, -1, "" }
};

/* To będzie liczba elementów powyższej tablicy, czyli liczba dostępnych opcji. */
int length = sizeof(options) / sizeof(options[0]);

/* Zmienna ta będzie oznaczała numer wybranej przez użytkownika opcji. */
int option_number;

/* Dzięki tej zmiennej program będzie wiedział czy użytkownik chce odświeżyć/uruchomić od początku daną opcję, czy nie. */
char user_choice[MAX];

/* W tej zmiennej będzie stała wartość, z którą będzie porównywana zmienna powyżej. */
char refresh[MAX] = "r\n";

/* Z kolei tutaj będą przechowywane wszystkie słowa z pliku "Words". (każde słowo nie powinno być dłuższe niż "MAX") */
char words[MAXWORDS][MAX];

/* Uruchamianie menu. Przed uruchomieniem menu zapisywane są słowa z pliku "Words" do tablicy "words". */
void start_menu(char* directory)
{
	srand(time(0));
	
	char* auxiliary = "/Words";
	int path_length = strlen(directory) + strlen(auxiliary) + 1;
	char path[path_length];
	FILE* ptr;
	int positions[MAXWORDS];	/* Tutaj będą przechowywane pozycje (względem początku pliku "Words") pierwszych liter poszczególnych słów. */
	int index;
	
	sprintf(path, "%s%s", directory, auxiliary);
	
	ptr = fopen(path, "r");
	
	if (ptr == NULL)
	{
		printf("Error\n");
		printf("Program could not read the file \"Words\"\n");
		fprintf(stderr, "%s\n", strerror(errno));
		
		exit(0);
	}
	else
	{
		positions[0] = ftell(ptr);
		index = 1;
		
		int c;
		while ((c = getc(ptr)) != EOF)
		{
			if (c == '\n')
			{
				positions[index++] = ftell(ptr);
			}
		}
		
		int i;
		for (i = 0; i < MAXWORDS; i++)
		{
			fseek(ptr, positions[i], SEEK_SET);
			fgets(words[i], MAX, ptr);
		}
		
		fclose(ptr);
	}

	while (1)
	{
		show_options();
		choose_option();
		do_option();
	}
}

/* Wyświetlanie dostępnych opcji. */
void show_options()
{
	system("clear");
	
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d. %s\n", i + 1, options[i].name);
	}
	printf("\n");
}

/* Wybieranie opcji i obsługa błędów. */
void choose_option()
{
	int correct_inputs;
	int is_wrong = 1;
	
	do
	{
		printf("Select option number: ");
		correct_inputs = scanf("%d", &option_number);
		clear_buffer();
		
		if (correct_inputs == 1 && option_number >= 1 && option_number <= length)
		{
			is_wrong = 0;
		}
		
		if (is_wrong)
		{
			show_options();
			printf("Please try again\n");
		}
	} while (is_wrong);
}

/* Wykonywanie wybranej opcji tak długo jak chce tego użytkownik. */
void do_option()
{
	do
	{
		system("clear");
		options[option_number - 1].function();
		printf("\n");
		
		printf("Enter \"r\" to refresh/play again\n");
		printf("Enter anything else to go back to menu\n");
		printf("Your choice: ");
		fgets(user_choice, MAX, stdin);
	} while (strcmp(user_choice, refresh) == 0);
}

/*
Gra sprawdzająca refleks.
Po jakimś losowym czasie od 3 do 6 sekund na ekranie będzie pojawiała się losowa litera od a do z (w ASCII literom tym odpowiadają liczby od 97 do 122).
Gracz będzie musiał jak najszybciej wcisnąć tę samą literę na klawiaturze i potwierdzić to klawiszem enter.
Mierzony będzie czas (w milisekundach) potrzebny na wykonanie tej czynności.
*/
/*
void ReactionTime()
{
	int waiting_time;
	char random_letter[3];
	char user_answer[MAX];
	char auxiliary[MAX];
	long long start, stop;
	long long score;
	
	waiting_time = random_value_in_range(3, 6);
	random_letter[0] = random_value_in_range(97, 122);
	random_letter[1] = '\n';
	random_letter[2] = '\0';
	
	printf("The following letter will appear in the next screen: ");
	printf("\033[1;33m");
	printf("%s\n", random_letter);
	printf("\033[1;32m");

	printf("Enter this letter when it appears and cofirm by pressing enter\n\n");

	printf("Enter anything to continue: ");
	fgets(auxiliary, MAX, stdin);
	system("clear");
	
	sleep(waiting_time);
	
	printf("%s\n", random_letter);
	
	start = time_in_milliseconds();
	do
	{
		fgets(user_answer, MAX, stdin);
	} while (strcmp(user_answer, random_letter) != 0);
	stop = time_in_milliseconds();
	
	score = stop - start;
	
	printf("\n");
	printf("Your score: %lld %s\n", score, options[0].high_score_unit);
	
	if (options[0].high_score == -1)
	{
		options[0].high_score = score;
	}
	else
	{
		if (score < options[0].high_score)
		{
			options[0].high_score = score;
		}
	}
}
*/

void ReactionTime()
{
	int waiting_time;
	char random_letter[3];
	char user_answer[MAX];
	char auxiliary[MAX];
	uint64_t start;
	uint64_t stop;
	uint64_t score;
	
	waiting_time = random_value_in_range(3, 6);
	random_letter[0] = random_value_in_range(97, 122);
	random_letter[1] = '\n';
	random_letter[2] = '\0';
	
	printf("The following letter will appear in the next screen: ");
	printf("\033[1;33m");
	printf("%s\n", random_letter);
	printf("\033[1;32m");

	printf("Enter this letter when it appears and cofirm by pressing enter\n\n");

	printf("Enter anything to continue: ");
	fgets(auxiliary, MAX, stdin);
	system("clear");
	
	sleep(waiting_time);
	
	printf("%s\n", random_letter);
	
	start = get_time();
	do
	{
		fgets(user_answer, MAX, stdin);
	} while (strcmp(user_answer, random_letter) != 0);
	stop = get_time();
	
	score = stop - start;
	
	printf("\n");
	printf("Your score: ");
	printf("%" PRIu64 " %s\n", score, options[0].high_score_unit);
	
	if (options[0].high_score == -1)
	{
		options[0].high_score = score;
	}
	else
	{
		if (score < options[0].high_score)
		{
			options[0].high_score = score;
		}
	}
}

/*
Gra sprawdzająca pamięć liczbową.
Na ekranie będą się pojawiały liczby o coraz większej liczbie cyfr.
Im więcej cyfr będzie miała dana liczba, tym dłużej będzie widoczna na ekranie (liczba n-cyfrowa będzie widoczna na ekranie n + 2 sekundy, n = 1, 2, 3, ...).
Użytkownik będzie musiał zapamiętać każdą liczbę zanim zniknie z ekranu.
Gdy liczba zniknie z ekranu zadaniem użytkownika będzie wpisanie tej samej liczby i potwierdzenie wszystkiego klawiszem enter.

Przeczytałem, że RAND_MAX ma zagwarantowaną wartość 32767. Pomyślałem więc, że losowe liczby 1-, 2-, 3- i 4-cyfrowe można generować zwyczajnie za pomocą funkcji rand(). Z kolei liczby o większej liczbie cyfr będą generowane troszkę inaczej. Na pewno są lepsze sposoby, ale na przykład, aby otrzymać liczbę 8-cyfrową można na początku wziąć jakąś losową liczbę 4-cyfrową, przemnożyć ją przez odpowiednią potęgę 10, czyli 10^4, a potem wypełniać nowe pozycje jakie się pojawią na końcu liczby jakimiś losowymi cyframi od 0 do 9 (chociaż na początku, po wymnożeniu, te nowe pozycje będą wypełnione samymi zerami).

Przykład:
1. 9876 (liczba 4-cyfrowa)
2. 98760000 (mnożenie przez odpowiednią potęgę 10, czyli 10^4)
3. 98760001 (wypełnianie nowych pozycji losowymi cyframi od 0 do 9)
4. 98760031
5. 98760531
6. 98767531 (liczba 8-cyfrowa)
*/
void NumberMemory()
{
	int digits = 0;
	int min;
	int max;
	long long random_number;
	char correct_number[MAX];
	char user_answer[MAX];
	char auxiliary[MAX];
	int mistake;
	int i;
	
	do
	{
		digits++;
		
		if (digits <= 4)
		{
			min = pow(10, digits - 1);
			max = pow(10, digits) - 1;
			random_number = (long long)(random_value_in_range(min, max));
		}
		else
		{
			min = pow(10, 3);
			max = pow(10, 4) - 1;
			random_number = (long long)(random_value_in_range(min, max)) * pow(10, digits - 4);
			
			for (i = 0; i < digits - 4; i++)
			{
				random_number += (rand() % 10) * pow(10, i);
			}
		}
		
		sprintf(correct_number, "%lld\n", random_number);
		
		for (i = digits + 2; i >= 1; i--)
		{
			printf("Memorize the number: ");
			printf("\033[1;33m");
			printf("%s\n", correct_number);
			printf("\033[1;32m");
			
			printf("Time: %d\n", i);
			sleep(1);
			system("clear");
		}
		
		mistake = 0;
		
		printf("Enter memorized number: ");
		fgets(user_answer, MAX, stdin);
		printf("\n");
		
		if (strcmp(user_answer, correct_number) != 0)
		{
			mistake = 1;
			
			printf("You entered wrong number\n");
			printf("Correct number is ");
			printf("\033[1;33m");
			printf("%s", correct_number);
			printf("\033[1;32m");
		}
		else
		{
			printf("You entered correct number\n\n");
			printf("Enter anything to continue: ");
			fgets(auxiliary, MAX, stdin);
			system("clear");
		}
	} while (mistake == 0);
	
	digits--;
	
	printf("Your score: %d %s\n", digits, options[1].high_score_unit);
	
	if (digits > options[1].high_score)
	{
		options[1].high_score = digits;
	}
}

/*
Gra sprawdzająca pamięć werbalną.
Na każdym poziomie będzie się pojawiało na ekranie jedno losowe słowo spośród wszystkich dostępnych słów z pliku "Words".
Użytkownik będzie musiał stwierdzić, czy dane słowo jest nowe i pojawia się po raz pierwszy, czy jednak już je wcześniej widział.
Każda pomyłka będzie oznaczała utratę 1 życia, wszystkich żyć będzie 3.
Gra się zakończy, gdy użytkownik straci wszystkie życia.

Słowa z pliku "Words" będą dostępne w tablicy "words" i będą reprezentowane przez indeksy tej tablicy.
Indeksy słów, które się pojawiły co najmniej raz będą zapisywane w tablicy "seen".

Na każdym poziomie będzie się wykonywał jeden z przypadków.

Przypadek 1 - program będzie się starał wygenerować indeks jakiegoś nowego słowa i wziąć odpowiadające mu słowo z tablicy "words". Może się jednak zdarzyć, że dany indeks już wcześniej został wygenerowany i wtedy nie będzie to wcale indeks nowego słowa. Dlatego trzeba będzie zweryfikować, czy wygenerowany indeks znajduje się w tablicy "seen", czy nie.
Przypadek 2 - program będzie generował indeks jakiegoś słowa, które już się wcześniej pojawiało. Będzie to robił, wybierając losowy indeks z tablicy "seen" i odpowiadające mu słowo z tablicy "words".
*/
void VerbalMemory()
{
	int level = 0;
	int lives = 3;
	int last_index = 0;
	int random_index;
	int seen[MAXWORDS];
	int new_or_seen;
	int found;
	char correct_answer[3];
	char user_answer[MAX];
	char auxiliary[MAX];
	
	random_index = random_value_in_range(0, MAXWORDS - 1);
	seen[last_index++] = random_index;
	
	printf("Level: %d\n", level);
	printf("Lives: %d\n\n", lives);
	
	printf("\033[1;33m");
	printf("%s\n", words[random_index]);
	printf("\033[1;32m");
	printf("Enter anything to continue: ");
	fgets(auxiliary, MAX, stdin);
	system("clear");
	
	do
	{
		level++;
		
		printf("If it's a new word, enter \"n\"\n");
		printf("If you've already seen a word, enter \"s\"\n\n");
		
		printf("Level: %d\n", level);
		printf("Lives: %d\n\n", lives);
		
		new_or_seen = random_value_in_range(1, 2);
		
		printf("\033[1;33m");
		if (new_or_seen == 1)	/* Przypadek 1 - na danym poziomie program spróbuje pokazać nowe słowo, jednak może mu się to nie udać. */
		{
			random_index = random_value_in_range(0, MAXWORDS - 1);
			found = 0;
			
			int i;
			for (i = 0; i < last_index; i++)
			{
				if (seen[i] == random_index)
				{
					found = 1;
					break;
				}
			}
				
			if (found == 0)
			{
				seen[last_index++] = random_index;
				correct_answer[0] = 'n';
			}
			else if (found == 1)
			{
				correct_answer[0] = 's';
			}
			
			printf("%s\n", words[random_index]);
		}
		else if (new_or_seen == 2)	/* Przypadek 2 - na danym poziomie pokazane zostanie na pewno już wcześniej widziane słowo. */
		{
			random_index = random_value_in_range(0, last_index - 1);
			correct_answer[0] = 's';
			
			printf("%s\n", words[seen[random_index]]);
		}
		printf("\033[1;32m");
		
		correct_answer[1] = '\n';
		correct_answer[2] = '\0';
		
		printf("Your answer: ");
		fgets(user_answer, MAX, stdin);
		
		if (strcmp(user_answer, correct_answer) != 0)
		{
			level--;
			lives--;
		}
		
		system("clear");
	} while (lives > 0);
	
	printf("Your score: %d %s\n", level, options[2].high_score_unit);
	
	if (level > options[2].high_score)
	{
		options[2].high_score = level;
	}
}

/* Wyświetlenie najlepszych wyników poszczególnych gier. */
void HighScores()
{
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%d. %s: ", i + 1, options[i].name);
		
		if (options[i].high_score != -1)
		{
			printf("%d %s", options[i].high_score, options[i].high_score_unit);
		}
		else
		{
			printf("High Score unavailable");
		}
		printf("\n");
	}
	printf("\n");
}

/* Wyjście z programu. */
void Exit()
{
	exit(0);
}

/* https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ */
void clear_buffer()
{
	while ((getchar()) != '\n');
}

/* https://stackoverflow.com/questions/10192903/time-in-milliseconds-in-c */
long long time_in_milliseconds()
{
	struct timeval tv;
	
	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

/* https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c */
uint64_t get_time()
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
    {
    	return (uint64_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    }
    else
    {
        return 0;
    }
}

/* https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand */
int random_value_in_range(int min, int max)
{
	return rand() % (max + 1 - min) + min;
}

/* https://stackoverflow.com/questions/14770609/strdup-not-working */
char* strdup(const char* c)
{
	char* duplicate = malloc(strlen(c) + 1);
	
	if (duplicate != NULL)
	{
		strcpy(duplicate, c);
	}
	
	return duplicate;
}

