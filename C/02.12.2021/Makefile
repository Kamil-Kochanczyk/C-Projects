CC = gcc
CFLAGS = -Wall -ansi

all:
	@echo "make BitFun, ./BitFun"
	@echo ""
	@echo "make BFWP, ./BFWP"
	@echo ""

BitFun: MainBitOperations.o BitOperations.o BitOperations.h
	$(CC) $(CFLAGS) -o BitFun MainBitOperations.o BitOperations.o BitOperations.h -lm

MainBitOperations.o: MainBitOperations.c BitOperations.h
	$(CC) $(CFLAGS) -c MainBitOperations.c -lm

BitOperations.o: BitOperations.c BitOperations.h
	$(CC) $(CFLAGS) -c BitOperations.c -lm
	
BFWP: MainBOWP.o BOWP.o BOWP.h
	$(CC) $(CFLAGS) -o BFWP MainBOWP.o BOWP.o BOWP.h -lm

MainBOWP.o: MainBOWP.c BOWP.h
	$(CC) $(CFLAGS) -c MainBOWP.c -lm

BOWP.o: BOWP.c BOWP.h
	$(CC) $(CFLAGS) -c BOWP.c -lm

clean:
	rm *.o

