#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m, int **result_matrix);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void swap(int *a, int *b);
void quick_sort(int *a, int left, int right);

int input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);
int input_matrix_size(int *x, int *y);

int **create_two_array_matrix(int n, int m);
void reverse_array(int *temp, int n);
int **create_single_array_matrix(int x, int y);
int main() {
  int **matrix, **result;
  int n, m;
  input_matrix_size(&n, &m);
  matrix = create_single_array_matrix(n, m);
  input(matrix, n, m);
  result = create_single_array_matrix(n, m);
  // output(matrix, n, m);
  // printf("\n");
  sort_vertical(matrix, n, m, result);
  output(result, n, m);
  printf("\n");
  printf("\n");

  sort_horizontal(matrix, n, m, result);
  output(result, n, m);

  /* for (int i = 0; i < m; i++)
  {
      free(result[i]);
      free(matrix[i]);
  } */
  free(result);
  free(matrix);
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
  int *temp = (int *)malloc(sizeof(int) * n * m);
  int index = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // printf(" M=%d ", matrix[i][j]);
      temp[index] = matrix[i][j];
      index++;
    }
  }
  // printf("\n");
  quick_sort(temp, 0, n * m - 1);
  /* for (int i = 0; i < n * m - 1; i++)
  {
      printf(" %d ", temp[i]);
  } */
  // printf("\n");
  // printf("\n");
  int direction = 0;
  index = 0;
  for (int i = 0; i < n; i++) {
    if (direction == 0) {
      for (int j = 0; j < m; j++) {
        result_matrix[j][i] = temp[index];
        // printf("R[%d][%d]=%d ind=%d ", j, i, result_matrix[j][i],
        // temp[index]);
        index++;
      }
      direction = 1;

    } else {
      for (int j = m - 1; j >= 0; j--) {
        result_matrix[j][j] = temp[index];
        // printf("R[%d][%d]=%d ind=%d ", j, i, result_matrix[j][i],
        // temp[index]);
        index++;
      }

      direction = 0;
    }
  }
  // result_matrix[0][0] = 119;
  // result_matrix[2][1] = 119;
  free(temp);
  // printf("\n");
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
  int *temp = (int *)malloc(sizeof(int) * n * m);
  int index = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      // printf(" M=%d ", matrix[i][j]);
      temp[index] = matrix[i][j];
      index++;
    }
  }
  quick_sort(temp, 0, n * m - 1);
  /*  for (int i = 0; i < n * m - 1; i++)
   {
       printf(" %d ", temp[i]);
   } */

  int direction = 0;
  index = 0;
  for (int i = 0; i < m; i++) {
    if (direction == 0) {
      for (int j = 0; j < n; j++) {

        result_matrix[i][j] = temp[index];
        index++;
      }
      direction = 1;

    } else {
      for (int j = n - 1; j >= 0; j--) {
        result_matrix[i][j] = temp[index];
        index++;
      }

      direction = 0;
    }
  }
  free(temp);
}

void quick_sort(int *a, int left, int right) {
  int pivot;
  int index;
  int l_hold = left;
  int r_hold = right;
  pivot = a[left];
  while (left < right) {
    while ((a[right] > pivot) && (left < right))
      right--;
    if (left != right) {
      a[left] = a[right];
      left++;
    }
    while ((a[left] < pivot) && (left < right))
      left++;
    if (left != right) {
      a[right] = a[left];
      right--;
    }
  }
  a[left] = pivot;
  index = left;
  left = l_hold;
  right = r_hold;
  if (left < index)
    quick_sort(a, left, index - 1);
  if (right > index)
    quick_sort(a, index + 1, right);
}

int **create_two_array_matrix(int n, int m) {
  int *data = (int *)malloc(sizeof(int) * n * m);
  int **ptr = (int **)malloc(sizeof(int) * m);
  for (int i = 0; i < m; i++) {
    *(ptr + i) = data + n * i;
  }
  return ptr;
}
int **create_single_array_matrix(int x, int y) {
  int **data = (int **)malloc(sizeof(int) * x * y + y * sizeof(int *));
  int *ptr = (int *)(data + y);
  for (int i = 0; i < y; i++) {
    data[i] = ptr + i * x;
  }
  return data;
}

void reverse_array(int *arr, int n) {
  int i = 0;
  while (i < (n / 2)) {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
    i++;
  }
}

/* void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    return;
} */

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

void output(int **matrix, int n, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d", matrix[i][j]);
      if (j != n - 1) {
        printf(" ");
      }
    }
    if (i != m - 1) {
      printf("\n");
    }
  }
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