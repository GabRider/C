CC = gcc -Wall -Wextra -std=c99 -c
all: joseph pointer_sort matrix_compute
joseph: joseph.c
	$(CC) joseph.c
	$(CC) circ_list.c
	gcc joseph.o circ_list.o -o joseph
matrix_compute: matrix_compute.c
	$(CC) matrix_compute.c
	$(CC) matrix.c
	gcc matrix_compute.o matrix.o -o matrix_compute
pointer_sort: pointer_sort.c
	$(CC) pointer_sort.c
	gcc pointer_sort.o -o pointer_sort
cleanTerminal:
	tput reset
