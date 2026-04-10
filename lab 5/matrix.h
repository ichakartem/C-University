#ifndef MATRIX_H
#define MATRIX_H

double **matrix_add(double **A, double **B, int n);
double **matrix_sub(double **A, double **B, int n);
double **matrix_mul(double **A, double **B, int n);
void free_matrix(double **M, int n);

#endif
