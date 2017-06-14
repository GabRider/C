CC = gcc -Wall -Wextra -std=c99 -c -g

all: cleanTerminal b_arbre.o test_b_arbre.o link

b_arbre.o: b_arbre.c
	$(CC) b_arbre.c
test_b_arbre.o: test_b_arbre.c
	$(CC) test_b_arbre.c
link: test_b_arbre.o 	b_arbre.o
	gcc b_arbre.o test_b_arbre.o -o test_b_arbre
cleanTerminal:

	tput reset
