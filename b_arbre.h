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

#endif
