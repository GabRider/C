#include "liste_simple.h"
Element*  new_list()
{
  return NULL;
}
Element*  allocation()
{
  return (Element*)malloc(sizeof(Element));
}
bool is_empty(Element *list)
{
  if (list!= NULL)
  return false;
  else
  return true;
}
Element* insert_head(Element *list, int data)
{
  Element *tmp=  allocation();
  (*tmp).content =data;
  if (!is_empty(list) ) {
    (*tmp).next = list;
    list = tmp;
  }
  else
  {
    (*tmp).content =data;
    (*tmp).next=NULL;
  }
  return tmp;
}
Element* insert_tail(Element *list, int data)
{
  Element *tmp=  allocation();
  Element *currentElement=list;
  (*tmp).content=data;
  (*tmp).next=NULL;
  if (is_empty(list)) {
    return tmp;
  }
  while (!is_empty((*currentElement).next))
  {
    currentElement= (*currentElement).next;
  }
  (*currentElement).next= tmp;
    return list;
}
Element* search(Element *list, int data)
{
  Element *currentElement=list;
  while (currentElement!=NULL)
  {
    if ((*currentElement).content==data) {
      return currentElement;
    }

  }
  return NULL;
}
Element* removes(Element *list, int data)
{
  Element * tmp=NULL;
  Element *LastElement=NULL;
  Element *currentElement=list;

  while (currentElement!=NULL)
  {
    //printf("%d\n",(*currentElement).content );
    if ((*currentElement).content==data) {
      tmp =currentElement;
      if (!is_empty(LastElement)) {

        (*LastElement).next = (*currentElement).next;
      }
      else
      {
        list=(*currentElement).next;
      }
      break;
    }
    LastElement= currentElement;
    currentElement= (*currentElement).next;
  }
  (*tmp).next=NULL;
  return tmp;
}
unsigned int count(Element *list)
{
    Element *currentElement=list;
  unsigned int* nb;
  while (currentElement!=NULL)
  {
    nb++;
  }
  return *nb;

}
void freeL(Element *list)
{
  Element *LastElement=NULL;
  Element *currentElement=list;
  while (!is_empty(currentElement))
  {
    if (is_empty((*currentElement).next))
     {
      if ((*list).next == NULL) {
        free(currentElement);
        currentElement=NULL;
      }
      else
      {
        (*LastElement).next=NULL;
        free(currentElement);
        currentElement=list;

        LastElement= NULL;
      }
    }
    else
    {
      LastElement=currentElement;
      currentElement= (*currentElement).next;
    } 
  }
}
void print(Element *list)
{
  Element *currentElement=list;
  while (currentElement!=NULL)
  {
    printf("%d\n",(*currentElement).content );
    currentElement=(*currentElement).next;
  }
}
void apply(Element *list, int (*oper)(int n))
{
  Element *currentElement=list;
  while (currentElement!= NULL) {

  }
}
