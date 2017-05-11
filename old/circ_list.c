#include "circ_list.h"
Element*  allocation()
{
  return (Element*)malloc(sizeof(Element));
}
Element* list_create()
{
  return NULL;
}

bool list_empty(Element *head)
{
  if (head!= NULL)
    return false;
  else
    return true;
}

Element* list_move(Element* head)
{
  return head->next;
}

Element* insert_after(Element *head, void* data)
{
  Element *tmp=  allocation();
    tmp->content=data;
    if (!list_empty(head) ) {
      tmp->next = head->next;
      head->next=tmp;
    }
    else
    {
      tmp->next=tmp;
    }
    return tmp;
}

Element* insert_before(Element *head, void* data)
{
  Element* tmp;
  void* old_content_head;
    if (!list_empty(head) ) {
      old_content_head= head->content;
      head->content=data;
      tmp=insert_after(head,old_content_head);
    }
    else
    {
    tmp =insert_after(head,data);
    }
    return tmp;
}

int compare_int(void* a, void* b)
{
  
  if (*(int*)a==*(int*)b)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

Element* list_search(Element *head, void* data, int (*compare)(void*,void*))
{
  Element* tmp =head;
  if (list_empty(tmp)) {
    return NULL;
  }
  while (1)
  {
    if(compare(tmp->content,data))
    {
      break;
    }
    tmp= tmp->next;
    if (tmp==head) {
      return NULL;
    }
  }
  return tmp;
}

Element* list_remove(Element *head, void* data, int (*compare)(void*,void*))
{
  Element* tmp =head;
  Element* removed;
  if (list_empty(head)||  list_search(head,&data,compare)==NULL) {
    return NULL;
  }
  while (1)
  {
    if (&(tmp->next)==&head && compare(tmp->content,&data))
     {
      head->content= head->next->content;
      removed= head->next;
      head->next=removed->next;
      break;
    }
    if(compare(tmp->next->content,&data))
    {
      removed= tmp->next;
      tmp->next= removed->next;
      break;
    }
    tmp= tmp->next;
  }
  return removed;
}

unsigned int list_count(Element *head)
{
  Element* tmp=head->next;
  unsigned int cnt =1;
  if (list_empty(head)) {
    return 0;
  }
  while (tmp!= head) {
    cnt++;
    tmp=tmp->next;
  }
  return cnt;
}
  void case_free(Element*head)
  {
    free(list_remove(head,head->content,compare_int));
  }
void list_free(Element *head, void (*data_free)(void*))
{
  while (head!=NULL) {
    data_free(head);
  }
}
