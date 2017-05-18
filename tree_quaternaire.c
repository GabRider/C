/*
Title       :   matrix_compute
Author      :   Gabriel Strano
Date        :   06/05/2017
Description :   give 1 or 2 matrice file for operation
*/
#include "matrix.h"
#include "string.h"
#include "tree_quaternaire.h"
#define LENGTH 256
/**
* print current matrice
* @param m matrice
*/
void print_m(m_int *m){
  printf("%d %d\n",(int)m->row,(int)m->col );
  for(int i=0;i<(int)m->row;i++){
    for(int j=0;j<(int)m->col;j++){
      printf(" %d ", m->content[i][j]);
    }
    printf("\n");
  }
}
/**
* read information and create matrix
* @param  filename name of data's file
* @return          new matrix
*/
m_int* read_file(char file[])
{
    FILE *doc = NULL;
    doc = fopen(file, "r");

    if (!doc)
    {
        fprintf(stderr,"file not found: %s\n", file);
        return NULL;
    }
    // init dimention
    char line[LENGTH];
	char sep[] = " ";
    fgets(line,LENGTH,doc); fgets(line,LENGTH,doc);
    if (line[0] == '#')
        fgets(line,LENGTH,doc);
    char *token;
    token = strtok(line, sep);
    int row = atoi(token);
    token = strtok(NULL, sep);
    int col = atoi(token);

    m_int* matrix = matrix_alloc(row, col);

    fgets(line,LENGTH,doc);
    int cnt_row = 0;

	while (cnt_row < row)
    {
        int cnt_col = 0;
        while (cnt_col < col)
        {
            fscanf(doc, "%d", &(matrix -> content[cnt_row][cnt_col]));
            cnt_col++;
        }
        cnt_row++;
	}
    fclose(doc);
    return matrix;
}
