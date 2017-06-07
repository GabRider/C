#include "b_arbre.h"
#include <stdlib.h>
#include <stdio.h>
Element*create_Element(int clef,Page*pg)
{
  Element* tmp = (Element*)malloc(sizeof(Element));
  tmp->clef=clef;
  tmp->pg=NULL;
  return tmp;
}
Page* new_page(int order)
{
  Page*pg=(Page*)malloc(sizeof(Page));
  Element*tab=(Element*)malloc((order*2+2)*sizeof(Element));
  if (!tab||!pg) {
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
  Element* tmp = create_Element(clef,NULL);
  return insert_case(b_tree,tmp,depth);
}
Page*insert_case(Page* b_tree,Element*cell,int depth)
{
  Page* current_page= b_tree;
  place(current_page,cell);
return b_tree;
}
void split(Page* pg, Element*cell)
{
  int page_order= pg->order*2+2;
  Page* right= new_page(pg->order);
  Page* left= new_page(pg->order);
  //mettre les petits nombres dans une nouvelle page
  for (int i = page_order-pg->order; i < page_order; i++) {
    Element* tmp = create_Element(pg->tab[i].clef,pg->tab[i].pg);
    place(right, tmp);
    pg->nb-=1;
  }
  //mettre les petits nombres dans une nouvelle page
  for (int i =1; i <= pg->nb; i++) {
    Element* tmp = create_Element(pg->tab[i].clef,pg->tab[i].pg);
    place(left, tmp);
    pg->nb-=1;
  }
  //déplace le nombre du milieu au début de la page
  pg->tab[1]= pg->tab[page_order-pg->order-1];
  pg->tab[0].pg=left;
  pg->tab[1].pg=right;
  cell->clef=pg->tab[1].clef;
  cell->pg= right;

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
  return pg->nb+1;
}
int place(Page* pg,Element* cell)
{
  int new_place=position(pg,cell->clef);
  if(new_place<0)
  {
    return 0;
  }
  pg->nb+=1;
  for (int i = pg->nb; i >=new_place; i--) {
    if (i!=new_place) {
      pg->tab[i]=pg->tab[i-1];
    }
    else
    {
      pg->tab[i]=*cell;
    }
  }
  if (pg->nb==pg->order*2+1)
  {
split(pg,cell);
  }
    return 1;
}
