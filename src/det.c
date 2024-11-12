#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
int input(double **matrix, int *n, int *m);
void output(double det);

int input_matrix_size(int *x, int *y);
int **create_two_array_matrix(int n, int m);

void main()
{
    int **matrix;
    int n, m;        
    input_matrix_size(&n, &m);
    matrix = create_two_array_matrix(n, m);
    int error = input(matrix, n, m);

    if(error != 1 && n == m) {        
        output(det(matrix, n, m));
    }
    else printf("n/a");

    free(**matrix);
    free(*matrix);
}

double det(double **matrix, int n, int m) {
    
}

int **create_two_array_matrix(int n, int m) {
  int *data = (int *)malloc(sizeof(int) * n * m);
  int **ptr = (int **)malloc(sizeof(int) * m);
  for (int i = 0; i < m; i++) {
    *(ptr + i) = data + n * i;
  }
  return ptr;
}

int input(int **matrix, int n, int m) {
  int result = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (scanf("%d", &matrix[i][j]) != 1) {
        result = 0;
      }
    }
  }
  if (getchar() != '\n') {
    result = 0;
  }
  return result;
}

int input_matrix_size(int *x, int *y) {
  int result = 1;
  char ch;
  if (scanf("%d %d", x, y) != 2 || *x <= 0 || *y <= 0 ||
      ((ch = getchar()) != '\n')) {
    result = 0;
  }
  return result;
}