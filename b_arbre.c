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

Page*insert(Page* b_tree,int clef)
{
  int depth=0;
  Element* cell = create_Element(clef,NULL);
  insert_case(b_tree,cell,depth);
  if (cell->pg!=NULL) {
    Page*left=new_page(b_tree->order);
    //mettre les petits nombres dans une nouvelle page
    for (int i =0; i <= b_tree->nb; i++) {
      left->tab[i].clef=b_tree->tab[i].clef;
      left->tab[i].pg=b_tree->tab[i].pg;
    }
    left->nb=b_tree->nb;
    b_tree->nb=1;
    b_tree->tab[0].pg=left;
    b_tree->tab[1]=*cell;
  }
  return b_tree;
}
Page*insert_case(Page* b_tree,Element*cell,int depth)
{
  int pos = position(b_tree,cell->clef);
  if (b_tree->tab[pos-1].pg!=NULL)
  {
     insert_case(b_tree->tab[pos-1].pg,cell,depth++);
     if (cell->pg!=NULL) {
       place(b_tree,cell);
     }
  }
  else
  {
  place(b_tree,cell);
  }
return b_tree;
}
void split(Page* pg, Element*cell)
{
  int page_order= pg->order*2+2;
  Page* right= new_page(pg->order);
  //mettre les grands nombres dans une nouvelle page
  for (int i = page_order-pg->order; i < page_order; i++) {
    Element* tmp = create_Element(pg->tab[i].clef,pg->tab[i].pg);
    place(right, tmp);
    pg->nb-=1;
  }

  cell->clef=pg->tab[pg->nb].clef;
pg->nb-=1;
  cell->pg= right;

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
  else
  {
    cell->pg=NULL;
  }
    return 1;
}
