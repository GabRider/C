EXES=  clean cleanTerminal circ_list.o joseph.o matrix.o matrix_compute.o pointer_sort.o link launch
CC=gcc -Wall -Wextra -std=c99 -c -g
all: compile
compile: $(EXES)
clean:
	rm -rf *.o
circ_list:circ_list
	$(CC) circ_list.c
joseph.o: joseph.c
	$(CC) joseph.c
matrix_compute.o: matrix_compute.c
	$(CC) matrix_compute.c
matrix.o: matrix.c
	$(CC) matrix.c
pointer_sort.o: pointer_sort.c
	$(CC) pointer_sort.c
link:
	gcc -g circ_list.o joseph.o -o joseph -lm
	gcc -g matrix.o matrix_compute.o -o matrix_compute
	gcc -g pointer_sort.o -o pointer_sort
launch:
	./pointer_sort 8 5 1 2 4 6 8 98 443 235 65 3
cleanTerminal:
	tput reset
