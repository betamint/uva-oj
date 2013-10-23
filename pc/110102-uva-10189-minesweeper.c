#include<stdio.h>
#define MAX 100
char matrix[MAX][MAX];
int field[MAX][MAX];
int scanField (int n, int m, char matrix[][MAX]);
int calcField (int n, int m, char matrix[][MAX], int field[][MAX]);
int printField (int n, int m, int field[][MAX]);
int main () {
  int a, b;
  int count = 0;
  while (scanf( "%d %d", &a, &b) != EOF) {
    if (a == 0 && b == 0)
      return 0;
    if (count > 0)
      printf ("\n");
    count++;
    scanField (a, b, matrix);
    calcField (a, b, matrix, field);
    printf ("Field #%d:\n", count);
    printField (a, b, field);
  }
  return 0;
}
int scanField (int n, int m, char matrix[][MAX]) {
  int i;
  for (i = 0; i < n; i++)
    scanf ("%s", matrix[i]);
  return 0;
}
int calcField (int n, int m, char matrix[][MAX], int field[][MAX]) {
  int i, j;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      field[i][j] = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (matrix[i][j] == '*')
	{
	  if (i > 0 && j > 0)     field[i-1][j-1] ++;
	  if (i > 0)              field[i-1][j] ++;
	  if (i > 0 && j < m-1)   field[i-1][j+1] ++;
	  if (j > 0)              field[i][j-1] ++;
	  if (j < m-1)            field[i][j+1] ++;
	  if (i < n-1 && j > 0)   field[i+1][j-1] ++;
	  if (i < n-1)            field[i+1][j] ++;
	  if (i < n-1 && j < m-1) field[i+1][j+1] ++;
	}
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (matrix[i][j] == '*')
	field[i][j] = 9;
  return 0;
}
int printField (int n, int m, int field[][MAX]) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (field[i][j] == 9)
	printf ("*");
      else
	printf ("%d", field[i][j]);
    }
    printf ("\n");
  }
  return 0;
}
