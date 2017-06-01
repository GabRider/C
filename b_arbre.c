#include "b_arbre.h"
#include <stdlib.h>
#include <stdio.h>
Page* new_page(int order)
{
  Page*pg=(Page*)malloc(sizeof(Page));
  Element*tab=(Element*)malloc((order*2+2)*sizeof(Element));
  if (tab||pg) {
    exit(0);
  }
  pg->order=order;
  pg->nb=0;
  pg->tab=tab;
  return pg;
}
Page*insert(Page* b_tree,int clef)
{
  int depth=0;
  Element* tmp = (Element*)malloc(sizeof(Element));
  tmp->clef=clef;
  tmp->pg=NULL;
  return insert_case(b_tree,tmp,depth);
}
Page*insert_case(Page* b_tree,Element*cell,int depth)
{
  Page* current_page= b_tree;
  place(current_page,cell);
return b_tree;
}
int position(Page*pg,int clef)
{
  for (int i = 1; i < pg->nb; i++){
    if (pg->tab[i].clef==clef) {
      return -1;
    }
    if(pg->tab[i].clef>clef)
    {
      return i;
    }
  }
  return pg->nb;
}
int place(Page* pg,Element* cell)
{
  int new_place=position(pg,cell.clef);
  if(new_place<0)
  {
    return 0;
  }
  pg->nb+=1;
  for (int i = pg->nb; i >0; i--) {
    if (i!=1) {
      pg->tab[i]=pg->tab[i-1];
    }
    else
    {
      pg->tab[i]=*cell;
    }
  }
    return 1; 
}
