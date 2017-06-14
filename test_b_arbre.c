#include "b_arbre.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool is_number(char* number)
{
  int cnt=0;
  while(number[cnt] != '\0')
  {
    int nb=(int)number[cnt];
    if ((nb<48 || nb>57) && (nb!=45)) {
      return false;
    }
    cnt++;
  }
  return true;
}
int main(int argc, char const *argv[]) {
  FILE *stderr;
  stderr = fopen("errors.dat","ab+");
  fprintf(stderr,"--------------------------\n" );
  Page*tree;
  if (is_number((char*)argv[1])) {
    tree= new_page(atoi(argv[1]));
  }
  else
  {
    fprintf(stderr,"la création de l'arbre a échoué veuillez recommencer\n" );
    exit(0);
  }
  for (int i = 2; i < argc; i++) {
    if (is_number((char*)argv[i]))
    {
      if (search(tree,atoi(argv[i]))) {
        fprintf(stderr,"le numéro : %s est déjà dans l'arbre\n",argv[i] );
      }
      else
      {
        insert(tree,atoi(argv[i]));
      }
    }
    if (strcmp(argv[i],"display")==0) {
      if (strcmp(argv[i+1],"RGD")==0) {
        display_RGD(tree,0);
        break;
      }

      if(strcmp(argv[i+1],"GRD")==0){
        display_GRD(tree);
        break;
      }
      fprintf(stderr,"%s\n","un argument doit être manquant ou mal orthographié" );
    }
    if (strcmp(argv[i],"search")==0)
    {
      if (is_number((char*)argv[i+1]))
      {
        printf("%d\n",search(tree,atoi(argv[i+1])));
        break;
      }
      else
      {
        printf("%s\n","un argument doit être manquant ou mal orthographié" );
        //write_error(("erreur.txt",("un argument doit être manquant ou mal orthographié");
      }
    }
  }
  free_b_arbre(tree);
  fclose(stderr);
  return 0;
}
