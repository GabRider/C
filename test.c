#include "liste_simple.h"
int main() {
Element * list = new_list();
if (is_empty(list)) {
  printf("%s\n","vide" );
}
list=insert_head(list,4);
list=insert_head(list,2);
list=insert_tail(list,5);
list=insert_head(list,2);
//freeL(list);
//list=new_list();
if (is_empty(list)) {
  printf("%s\n","vide" );
}
apply(list,print);
apply(list,squartRoot);
printf("--------------\n" );
apply(list,print);
}
