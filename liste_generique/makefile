EXES=  clean cleanTerminal test liste_simple link launch
CC=gcc -Wall -Wextra -std=c99 -c -g
all: compile
compile: $(EXES)
clean:
	rm -rf *.o *.exe
liste_simple: liste_simple.c
	$(CC) liste_simple.c
test: test.c
	$(CC) test.c
link:
	gcc -g liste_simple.o test.o -o list
launch:
	./list
cleanTerminal:
	tput reset
