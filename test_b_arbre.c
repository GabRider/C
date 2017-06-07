#include "b_arbre.h"
int main(int argc, char const *argv[]) {
  Page*tree= new_page(2);
  insert(tree,3);
  insert(tree,10);
  insert(tree,20);
  insert(tree,5);
  insert(tree,6);
  return 0;
}
