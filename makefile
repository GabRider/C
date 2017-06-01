CC = gcc -Wall -Wextra -std=c99 -c -g

all: cleanTerminal b_arbre

b_arbre: b_arbre.c
$(CC) b_arbre.c
$(CC) test_b_arbre.c
gcc b_arbre.o test_b_arbre.o -o b_arbre
