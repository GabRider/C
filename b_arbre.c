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
int position(Page *pg, int clef)
{
  int id_begin=1;
  int id_end=pg->nb;
  int id_middle=0;
  while(id_begin<=id_end)
  {
    //middle between min and max
    id_middle = (id_begin+id_end)/2;
    if(pg->tab[id_middle].clef==clef)
    {
      return -1;
    }
    if(pg->tab[id_middle].clef>clef)
    {
      //middle is bigger than clef so remove 1
      id_end=id_middle-1;
    }
    else{
      //middle is < so +1
      id_begin=id_middle+1;
    }
  }
  return id_begin;
}
Page*insert(Page* b_tree,int clef)
{
  int depth=0;
  Element* cell = create_Element(clef,NULL);
  insert_case(b_tree,cell,depth);
  if (cell->pg!=NULL) {
    Page*left=new_page(b_tree->order);
    //insert on new page tiny number
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
  //move bigger number on new page
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
  //sort table
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
int search(Page *b_tree,int clef)
{
  int pos= position(b_tree,clef);
  if (pos<0) {
    return 1;
  }
  if (b_tree->tab[pos-1].pg!=NULL) {
    return search(b_tree->tab[pos-1].pg,clef);
  }
  return 0;
}
void display_GRD(Page * b_tree)
{
  for (int i = 0; i <= b_tree->nb; i++)
  {
    if (b_tree->tab[i].pg !=NULL)
    {
      if (i!=0)
      {
        printf("%d\n",b_tree->tab[i].clef );
      }
      display_GRD(b_tree->tab[i].pg);
    }
    else
    {
      if (i!=0)
      {
        printf("%d\n",b_tree->tab[i].clef );
      }
    }
  }
}

void display_RGD(Page * b_tree,int depth)
{
  int indent=5;
  int new_depth= depth+1;
  printf("%*c", indent*depth,' ' );
  for (int i = 1; i <= b_tree->nb; i++)
  {
    printf("%d ",b_tree->tab[i].clef);
  }
  printf("\n");
  for (int i = 0; i <= b_tree->nb; i++)
  {
    if (b_tree->tab[i].pg !=NULL)
    {
      display_RGD(b_tree->tab[i].pg,new_depth);
    }
  }
}
void free_b_arbre(Page*b_tree)
{
  for (int i = 0; i <= b_tree->nb; i++)
  {
    if (b_tree->tab[i].pg !=NULL)
    {
      free_b_arbre(b_tree->tab[i].pg);
    }
  }
  free(b_tree->tab);
  free(b_tree);

}
