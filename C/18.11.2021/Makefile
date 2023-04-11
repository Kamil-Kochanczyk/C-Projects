
Program: Main.o FindRoot.o Function.o
	gcc -Wall -ansi Main.o FindRoot.o Function.o -o Program -lm

Main.o: Main.c
	gcc -Wall -ansi -c Main.c -lm

FindRoot.o: FindRoot.c FindRoot.h
	gcc -Wall -ansi -c FindRoot.c -lm

Function.o: Function.c Function.h
	gcc -Wall -ansi -c Function.c -lm

clean:
	rm *.o
