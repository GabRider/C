/**
 * Author : Gabriel Strano
 * Project : b_arbre
 */
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
/**
* create new page
* @param  order order of tree
* @return
*/
Page* new_page(int order);
/**
* Insert in tree table one value
* @param  b_tree first page
* @param  clef   insert new value
* @return        Current page
*/
Page*insert(Page* b_tree,int clef);
/**
* Insert in tree table one value
* @param  b_tree any page
* @param  cell   element use for insert
* @param  depth  depth recursion
* @return        page
*/
Page*insert_case(Page* b_tree,Element*cell,int depth);
/**
* sort and insert element in page
* @param  pg   current page
* @param  cell insert element
* @return      current page
*/
int place(Page* pg,Element* cell);
/**
* Display tree mode Left Root Right
* @param b_tree tree
*/
void display_GRD(Page * b_tree);
/**
* Display tree mode Root Left Right
* @param b_tree tree
* @param depth  depth of recursion
*/
void display_RGD(Page * b_tree,int depth);
/**
* search value on tree
* @param  b_tree tree
* @param  clef   finded value
* @return        0 for not found and 1 for found
*/
int search(Page *b_tree,int clef);
/**
* free tree
* @param b_tree tree
*/
void free_b_arbre(Page*b_tree);
#endif
