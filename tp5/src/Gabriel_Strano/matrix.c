/*
Title       :   matrix
Author      :   Gabriel Strano
Date        :   06/05/2017
Description :   create all function used for matrix
*/
#include "matrix.h"
m_double* matrix_alloc(unsigned int row, unsigned int col)
{
  m_double* matrix= (m_double*) malloc(sizeof(m_double));
  double ** content = (double**)malloc(row*sizeof(double*));
  double * all_numbers= (double*)malloc(row*col*sizeof(double));
  matrix->row=row;
  matrix->col=col;
  for (int i = 0; i < (int)row*(int)col; i++)
   {
      all_numbers[i]=0;
  }
  for (int i = 0; i < (int)row; i++)
  {

    content[i]= all_numbers+(i*col);
  }
  matrix->content= content;
  return matrix;
}
m_double* matrix_add(m_double* m1, m_double* m2)
{
  if (m1!=NULL &&m2!=NULL) {
  if ((int)m1->row!=(int)m2->row&&(int)m1->col!=(int)m2->col)
    return NULL;
}
else
{
  return NULL;
}
  m_double * new_matrix= matrix_alloc(m1->row,m1->col);
  new_matrix->row=m1->row;
  new_matrix->col=m1->col;
  for (int i = 0; i < (int)m1->row; i++) {
    for (int j = 0; j < (int)m1->col; j++) {
      new_matrix->content[i][j]= m1->content[i][j]+m2->content[i][j];
    }
  }
  return new_matrix;

}
m_double* matrix_mult(m_double*m1,m_double* m2)
{
  if(m1==NULL||m2==NULL)
  return NULL;

  if(m1->col != m2->row)
    return NULL;

  m_double *res_matrix = matrix_alloc(m1->row,m2->col);
  for(int i=0;i<(int)res_matrix->row;i++)
  {
    for( int j=0;j<(int)res_matrix->col;j++)
    {
      double res =0;
      for(int k=0;k<(int)m1->col;k++)
        res += m1->content[i][k]*m2->content[k][j];
      res_matrix->content[i][j] = res;
      }
    }
     return res_matrix;
}
m_double* matrix_transpose(m_double* m)
{

	m_double* matrix_tmp = m;
	m_double* new_matrix = matrix_alloc(matrix_tmp->col,matrix_tmp->row);
    for (int i=0; i < (int)matrix_tmp->row ; i++){
		    for (int j=0; j < (int)matrix_tmp->col ; j++){
          new_matrix->content[j][i]=matrix_tmp->content[i][j];
        }
      }

	return new_matrix;
}
void matrix_free(m_double*m)
  {
    if (m!=NULL)
    {
      free(m->content[0]);
      free(m->content);
      free(m);
  }
}
