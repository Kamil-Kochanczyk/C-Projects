/* Kamil Kochańczyk */

/*
Pomysł na menu zawdzięczam temu filmikowi (programując menu wzorowałem się na tym właśnie filmiku): https://www.youtube.com/watch?v=hMJSa2T-PAo

Pomysł na gry zawdzięczam tej stronie: https://humanbenchmark.com/

Jak zmienić kolor tekstu: https://www.theurbanpenguin.com/4184-2/
*/

#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char* argv[])
{
	char* duplicate;
	char* directory;
	
	duplicate = strdup(argv[0]);
	directory = dirname(duplicate);

	if (argc == 2)
	{
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
		{
			printf("Usage: ./Project [OPTION]\n\n");
			
			printf("-h, --help\t\t\tdisplay this help and exit\n");
			printf("-a        \t\t\tdisplay advanced help and exit\n\n");
			
			printf("This program displays a menu with different options available for a user.\n");
			printf("User can choose an option by entering a number corresponding to that option.\n\n");
			
			exit(0);
		}
		else if (strcmp(argv[1], "-a") == 0)
		{
			printf("Usage: ./Project [OPTION]\n\n");
			
			printf("-h, --help\t\t\tdisplay basic help and exit\n");
			printf("-a        \t\t\tdisplay this help and exit\n\n");
			
			printf("This program displays a menu with different options available for a user.\n");
			printf("User can choose an option by entering a number corresponding to that option.\n\n");
			
			printf("Options available are listed below.\n\n");

			printf("1. Reaction Time - game that tests user's reflexes.\n");
			printf("User has to wait several seconds and then a random letter will appear on screen.\n");
			printf("User's task is to press the same letter on a keyboard as fast as possible.\n\n");

			printf("2. Number Memory - game that tests user's number memory.\n");
			printf("User has to memorize a number displayed on screen.\n");
			printf("After some time the number will disappear and user's task is to enter the memorized number again.\n");
			printf("The game will end if user enters incorrect number.\n");
			printf("The game will get progressively harder as numbers with more and more digits will be displayed.\n\n");

			printf("3. Verbal Memory - game that tests user's verbal memory.\n");
			printf("User has to decide if a word that is displayed on screen is a new word or if it has already appeared during the game.\n");
			printf("User has 3 lives in total.\n");
			printf("Everytime user makes a mistake, 1 life is lost.\n\n");

			printf("4. High Scores - option that displays user's best results of each game.\n");
			printf("If high scores are not available appropriate messages will be printed.\n\n");

			printf("5. Exit - option that quits the program.\n\n");

			printf("User has to cofirm each input by pressing enter.\n\n");
			
			printf("Sources that helped to create this program:\n");
			printf("https://www.youtube.com/watch?v=hMJSa2T-PAo (menu)\n");
			printf("https://humanbenchmark.com/ (brain games)\n");
			printf("https://www.theurbanpenguin.com/4184-2/ (changing text color)\n");
			printf("https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/ (clearing buffer)\n");
			printf("https://stackoverflow.com/questions/10192903/time-in-milliseconds-in-c (getting timestamp in milliseconds)\n");
			printf("https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c (measuring time)\n");
			printf("https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand (getting random numbers from specific range)\n");
			printf("https://stackoverflow.com/questions/14770609/strdup-not-working (strdup)\n\n");
			
			exit(0);
		}
	}
	
	printf("\033[1;32m");	/* Zielony */
	start_menu(directory);
	printf("\033[0m");	/* Reset koloru */
	
	return 0;
}

