/*
Title       :   joseph
Author      :   Gabriel Strano
Date        :   06/05/2017
Description :   create the joseph's function
*/
#include "circ_list.h"
bool is_number(char* number)
{
  int cnt=0;
  while(number[cnt] != '\0')
  {
    int nb=(int)number[cnt];
    if ((nb<48 || nb>57) && (nb!=45)) {
      return false;
    }
    cnt++;
  }
  return true;
}
Element* extract(Element* elem, int jump)
{
  Element* tmp= (Element*)malloc(sizeof(Element));
  Element* Last_tmp= (Element*)malloc(sizeof(Element));
  tmp=elem;
  for (int i = 0; i < jump; i++)
  {
    Last_tmp= tmp;
    tmp=tmp->next;
  }
  Last_tmp->next= tmp->next;
  printf("%d\n",*(int*)tmp->content );
  free(tmp);
  return Last_tmp;
}
int main(int argc, char *argv[]) {
  int *p;
  int* max=(int*)malloc(sizeof(int));
  int* jump=(int*)malloc(sizeof(int));
  Element* tmp= (Element*)malloc(sizeof(Element));
  Element * list = list_create();
  if (argc!=3) {
    printf("pas assez d'argument ou trop d'argument\n");
    exit(0);
  }
  if (!is_number(argv[1])&&!is_number(argv[2])) {
    printf("un des parametres n'est pas un nombre\n" );
    exit(0);
  }
  *max= atoi(argv[1]);
  *jump=atoi(argv[2]);

  for (int i = 1; i <= *max; i++) {
    p=(int*)malloc(sizeof(int));
    *p=i;
    list=insert_after(list,p);
  }
  tmp=list;
  for (int i = 0; i < *max; i++) {
    tmp=extract(tmp,*jump);
  }
  exit(0);
}
