EXES=  clean cleanTerminal circ_list.o joseph.o link launch
CC=gcc -Wall -Wextra -std=c99 -c -g
all: compile
compile: $(EXES)
clean:
	rm -rf *.o
circ_list:.o circ_list
	$(CC) circ_list.c
joseph.o: joseph.c
	$(CC) joseph.c
link:
	gcc -g circ_list.o joseph.o -o joseph -lm
launch:
	./joseph 8 3
cleanTerminal:
	tput reset
