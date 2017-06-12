#ifndef B_ARBRE
#define B_ARBRE
typedef struct Element
{
  int clef;
  struct Page* pg;

}Element;
typedef struct Page
{
  int order;
  int nb;
  Element*tab;
}Page;
Page* new_page(int order);
Page*insert(Page* b_tree,int clef);
Page*insert_case(Page* b_tree,Element*cell,int depth);
int place(Page* pg,Element* cell);
void display_GRD(Page * b_tree);
void display_RGD(Page * b_tree,int depth);
int search(Page *b_tree,int clef);
#endif
