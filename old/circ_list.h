#ifndef CIRC_LIST_H_INCLUDED
#define CIRC_LIST_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct Element {
	void* content;
	struct Element *next;
} Element;
Element* list_create();
/**
 * verify if the list is empty
 * @param  head list of Element
 * @return      true:empty, false:not empty
 */
bool list_empty(Element *head);
/**
 * get next Element in the list
 * @param  head list of Element
 * @return      new list head
 */

Element* list_move(Element* head);
/**
 * compare to void data (int)
 * @param  a number 1
 * @param  number 2
 * @return   true or false
 */
int compare_int(void* a, void* b);
/**
 * free pointer
 * @param head list of Element
 */
void case_free(Element*head);
/**
 * insert new Element after head list
 * @param  head list of Element
 * @param  data pointer of any type of data
 * @return      new Element
 */
Element* insert_after(Element *head, void* data);
/**
 * insert new Element before head list head list
 * @param  head list of Element
 * @param  data pointer of any type of data
 * @return      new Element
 */
Element* insert_before(Element *head, void* data);
/**
 * search value in list
 * @param  head    list of Element
 * @param  data    pointer of any type of data
 * @param  compare function choose
 * @return         Element found or NULL
 */
Element* list_search(Element *head, void* data, int (*compare)(void*,void*));
/**
 * remove Element on a list
 * @param  head    list of Element
 * @param  data    pointer of any type of data
 * @param  compare function choose
 * @return         Element remove
 */
Element* list_remove(Element *head, void* data, int (*compare)(void*,void*));
/**
 * Count number of Element in list
 * @param  head list of Element
 * @return      number of Element in list
 */
unsigned int list_count(Element *head);
/**
 * Delete list
 * @param head      list of Element
 * @param data_free function choose
 */
void list_free(Element *head, void (*data_free)(void*));
#endif
