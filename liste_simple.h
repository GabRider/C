
#ifndef LISTE_SIMPLE_H_INCLUDED
#define LISTE_SIMPLE_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct Element {
	int content;
	struct Element *next;
} Element;
Element* new_list();

bool is_empty(Element *list);
Element* insert_head(Element *list, int data);
Element* insert_tail(Element *list, int data);
Element* search(Element *list, int data);
Element* removes(Element *list, int data);
unsigned int count(Element *list);
void freeL(Element *list);
int print(int n);
int squartRoot(int n);
void apply(Element *list, int (*oper)(int n));
#endif
