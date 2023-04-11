CFLAGS = -Wall -ansi
BO = BitOperations

AuxiliaryProgram: MainAuxiliary.o Auxiliary.o
	gcc $(CFLAGS) MainAuxiliary.o Auxiliary.o -o AuxiliaryProgram -lm

MainAuxiliary.o: MainAuxiliary.c Auxiliary.h
	gcc $(CFLAGS) -c MainAuxiliary.c -lm

Auxiliary.o: Auxiliary.c Auxiliary.h
	gcc $(CFLAGS) -c Auxiliary.c -lm

MakefileProgram: Main$(BO).o $(BO).o
	gcc $(CFLAGS) Main$(BO).o $(BO).o -o MakefileProgram -lm
	./MakefileProgram

Main$(BO).o: Main$(BO).c $(BO).h
	gcc $(CFLAGS) -c Main$(BO).c -lm

$(BO).o: $(BO).c $(BO).h
	gcc $(CFLAGS) -c $(BO).c -lm

clean:
	rm *.o

