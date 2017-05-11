#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct m_double {
	unsigned int row,col;
	double** content;
} m_double;
/**
 * set memory and create matrix
 * @param  row number of row
 * @param  col number of col
 * @return     empty matrix
 */
m_double * matrix_alloc(unsigned int row, unsigned int col);
/**
 * sum two matrix
 * @param  m1 first matrix
 * @param  m2 second matrix
 * @return    new matrix
 */
m_double* matrix_add(m_double* m1, m_double* m2);
/**
 * multiplicate two matrix
 * @param  m1 first matrix
 * @param  m2 second matrix
 * @return    new matrix
 */
m_double* matrix_mult(m_double*m1,m_double* m2);
/**
 * free the current matrix
 * @param m current matrix
 */
void matrix_free(m_double*m);
/**
 * transpose a matrix
 * @param  m matrix
 * @return   new matrix
 */
m_double* matrix_transpose(m_double* m);
#endif
