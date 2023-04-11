/* Kamil Kochańczyk */

#ifndef _INCLUDEGUARD_
#define _INCLUDEGUARD_

#define MAX 100
#define MAXWORDS 1000

/*
Ta struktura będzie reprezentowała pojedynczą opcję dostępną w menu.
Każda opcja będzie miała swoją nazwę i będzie coś robiła, gdy się ją wybierze w menu.
Jeżeli opcja będzie grą, to zapamiętywany będzie również najlepszy wynik uzyskany w tej grze przez użytkownika.
Domyślną wartością najlepszego wyniku będzie -1, co będzie oznaczało, że gra nie była jeszcze uruchamiana, albo że opcja nie jest w ogóle grą.
Aby wypisywać najlepsze wyniki warto wiedzieć w jakich jednostkach to robić.
*/
typedef struct
{
	char* name;
	void (*function)();
	int high_score;
	char* high_score_unit;
} Option;

/* W tej tablicy będą przechowywane wszystkie opcje dostępne w menu. */
extern Option options[];

/* To będzie liczba elementów powyższej tablicy, czyli liczba dostępnych opcji. */
extern int length;

/* Zmienna ta będzie oznaczała numer wybranej przez użytkownika opcji. */
extern int option_number;

/* Dzięki tej zmiennej program będzie wiedział czy użytkownik chce odświeżyć/uruchomić od początku daną opcję, czy nie. */
extern char user_choice[];

/* W tej zmiennej będzie stała wartość, z którą będzie porównywana zmienna powyżej. */
extern char refresh[];

/* Tutaj będą przechowywane wszystkie słowa z pliku "Words". (każde słowo nie powinno być dłuższe niż MAX) */
extern char words[][MAX];

/* Metody te będą dbały o poprawne działanie menu. */
void start_menu(char*);
void show_options();
void choose_option();
void do_option();

/* To będą opcje możliwe do zrealizowania w menu. */
void ReactionTime();
void NumberMemory();
void VerbalMemory();
void HighScores();
void Exit();

/* To natomiast będą funkcje pomocnicze. */
void clear_buffer();
long long time_in_milliseconds();
int random_value_in_range(int, int);
char* strdup(const char* c);

#endif

