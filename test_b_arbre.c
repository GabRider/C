#include "b_arbre.h"
int main(int argc, char const *argv[]) {
  Page*tree= new_page(2);
  insert(tree,3);
  insert(tree,10);
  insert(tree,20);
  insert(tree,5);
  insert(tree,6);
  insert(tree,100);
  insert(tree,203);
  insert(tree,565);
  insert(tree,-6);
  insert(tree,-10);
  insert(tree,-20);
  insert(tree,-5);
  insert(tree,-66);
  //display_GRD(tree);
  display_RGD(tree,0);
  return 0;
}
