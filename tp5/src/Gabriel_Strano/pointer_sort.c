/*
Title       :   pointer_sort
Author      :   Gabriel Strano
Date        :   06/05/2017
Description :   sort any list of number
*/
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
* check if the first number is bigger than second
* @param  a pointer of int
* @param  b pointer of int
* @return   true if a is bigger
*/
bool bigger_than(int* a,int* b)
{
  if (*a>*b)
  return true;
  else
  return false;
}
/**
* sort the table of pointer
* @param table  table of pointer of int
* @param nb_max size of table
*/
void bullet_sort(int ** table,int nb_max)
{
  int max=nb_max;
  int* tmp= (int*)malloc(sizeof(int));

  for (int i = 0; i < nb_max-1; i++) {
    for (int j = 0; j < max-1; j++) {
      if (bigger_than(table[j],table[j+1])) {
        tmp=table[j];
        table[j]=table[j+1];
        table[j+1]=tmp;
      }
    }
    max--;
  }
}
/**
* check if a table of char is a number
* @param  number table of char
* @return        true if int
*/
bool is_number(char* number)
{
  int cnt=0;
  while(number[cnt] != '\0')
  {
    if (((int)number[cnt]<48 || (int)number[cnt]>57) && ((int)number[cnt]!=45)) {
      return false;
    }
    cnt++;
  }
  return true;
}
/**
* print the table sorted
* @param table table of pointer
* @param max   size of table
*/
void print_table_sort(int** table,int  max)
{
  for (int i = 0; i < max; i++) {
    printf("%d\n",*(int*)table[i] );
  }
}
int main(int argc,char** argv){
  int size=argc-1;
  int *no_sorted= (int*)malloc((size) *sizeof(int));
  int **sorted= (int**)malloc((size) *sizeof(int*));
  if (!no_sorted || !sorted) {
    printf("allocation error\n" );
    exit(0);
  }
  for (int i = 1; i < argc; i++) {
    if (is_number(argv[i])) {
      no_sorted[i-1]= atoi(argv[i]);
      sorted[i-1]= no_sorted+(i-1);
    }
    else
    {
      exit(0);
    }
  }
  bullet_sort(sorted,size);
  print_table_sort(sorted,size );
  free(no_sorted);
  free(sorted);
}
