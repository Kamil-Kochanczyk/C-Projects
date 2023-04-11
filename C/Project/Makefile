CC = gcc
CFLAGS = -Wall -ansi
PROJECT = Project
HEADER = Header.h
OFILES = Main.o MenuAndOptions.o

all:
	@echo "make $(PROJECT)"
	@echo ""
	@echo "./$(PROJECT) -h, ./$(PROJECT) --help"
	@echo ""
	@echo "./$(PROJECT) -a"
	@echo ""
	@echo "./$(PROJECT)"
	@echo ""

$(PROJECT): $(OFILES) $(HEADER)
	$(CC) $(CFLAGS) -o $(PROJECT) $(OFILES) $(HEADER) -lm

Main.o: Main.c $(HEADER)
	$(CC) $(CFLAGS) -c Main.c

MenuAndOptions.o: MenuAndOptions.c $(HEADER)
	$(CC) $(CFLAGS) -c MenuAndOptions.c

clean:
	rm *.o
	rm $(PROJECT)

