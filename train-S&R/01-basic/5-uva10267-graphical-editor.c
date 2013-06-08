#include<stdio.h>
#include<string.h>
#define MAX 300
#define LEN_LINE 50
int newImg (char image[MAX][MAX],
	    int *size_m, int *size_n, char buffer[LEN_LINE]);
int clearImg (char image[MAX][MAX],
	      int size_m, int size_n);
int colorImg (char image[MAX][MAX],
	      int size_m, int size_n, char buffer[LEN_LINE]);
int drawVertical (char image[MAX][MAX],
		  int size_m, int size_n, char buffer[LEN_LINE]);
int drawHorizontal (char image[MAX][MAX],
		    int size_m, int size_n, char buffer[LEN_LINE]);
int drawRectangle (char image[MAX][MAX],
		   int size_m, int size_n, char buffer[LEN_LINE]);
int fillRelative (char image[MAX][MAX],
		  int size_m, int size_n, char buffer[LEN_LINE]);
int writeImg (char image[MAX][MAX],
	      int size_m, int size_n, char buffer[LEN_LINE]);
int isNearRelative (int relative[MAX][MAX], int i, int j);
int main () {
  char image[MAX][MAX];
  int size_m = 0, size_n = 0;
  char buffer[LEN_LINE];
  char command;
  int leave = 0;
  while (fgets(buffer, LEN_LINE, stdin) != 0) {
    sscanf (buffer, "%c", &command);
    switch (command) {
    case 'I':
      newImg (image, &size_m, &size_n, buffer);
      break;
    case 'C':
      clearImg (image, size_m, size_n);
      break;
    case 'L':
      colorImg (image, size_m, size_n, buffer);
      break;
    case 'V':
      drawVertical (image, size_m, size_n, buffer);
      break;
    case 'H':
      drawHorizontal (image, size_m, size_n, buffer);
      break;
    case 'K':
      drawRectangle (image, size_m, size_n, buffer);
      break;
    case 'F':
      fillRelative (image, size_m, size_n, buffer);
      break;
    case 'S':
      writeImg (image, size_m, size_n, buffer);
      break;
    case 'X':
      leave = 1;
      break;
    default:
      {}
    }
    if (leave == 1) break;
  }
  return 0;
}
int newImg (char image[MAX][MAX],
	    int *size_m, int *size_n, char buffer[LEN_LINE]) {
  int m, n;
  char cmd;
  sscanf (buffer, "%c %d %d", &cmd , &m, &n);

  *size_m = m;
  *size_n = n;
  clearImg (image, *size_m, *size_n);
  return 0;
}
int clearImg (char image[MAX][MAX],
	      int size_m, int size_n) {
  int i, j;
  for (i = 0; i <= size_m + 1; i++)
    for (j = 0; j <= size_n + 1; j++)
      image[i][j] = 'O';
  return 0;
}
int colorImg (char image[MAX][MAX],
	      int size_m, int size_n, char buffer[LEN_LINE]) {
  int x, y;
  char c;
  char cmd;
  sscanf (buffer, "%c %d %d %c", &cmd, &x, &y, &c);

  image[x][y] = c;
  return 0;
}
int drawVertical (char image[MAX][MAX],
		  int size_m, int size_n, char buffer[LEN_LINE]) {
  int x, y1, y2;
  char c;
  char cmd;
  sscanf (buffer, "%c %d %d %d %c", &cmd, &x, &y1, &y2, &c);

  int i;
  for (i = y1; i <= y2; i++)
    image[x][i] = c;
  return 0;
}
int drawHorizontal (char image[MAX][MAX],
		    int size_m, int size_n, char buffer[LEN_LINE]) {
  int x1, x2, y;
  char c;
  char cmd;
  sscanf (buffer, "%c %d %d %d %c", &cmd, &x1, &x2, &y, &c);

  int i;
  for (i = x1; i <= x2; i++)
    image[i][y] = c;
  return 0;
}
int drawRectangle (char image[MAX][MAX],
		   int size_m, int size_n, char buffer[LEN_LINE]) {
  int x1, x2, y1, y2;
  char c;
  char cmd;
  sscanf (buffer, "%c %d %d %d %d %c", &cmd, &x1, &x2, &y1, &y2, &c);

  int i, j;
  for (i = x1; i <= x2; i++)
    for (j = y1; j <= y2; j++)
      image[i][j] = c;
  return 0;
}
int fillRelative (char image[MAX][MAX],
		  int size_m, int size_n, char buffer[LEN_LINE]) {
  int x, y;
  char c;
  char cmd;
  sscanf (buffer, "%c %d %d %c", &cmd, &x, &y, &c);

  int relative[MAX][MAX];
  int i, j, k;
  for (i = 0; i <= size_m + 1; i++)
    for (j = 0; j <= size_n + 1; j++)
      relative[i][j] = 0;
  relative[x][y] = 1;
  for (k = 0; k < size_m || k < size_n; k++)
    for (i = 1; i <= size_m; i++)
      for (j = 1; j <= size_n; j++)
	if (image[i][j] == image[x][y] &&
	    isNearRelative (relative, i, j))
	  relative[i][j] = 1;
  for (i = 1; i <= size_m; i++)
    for (j = 1; j <= size_n; j++)
      if (relative[i][j])
	image[i][j] = c;
  return 0;
}
int isNearRelative (int relative[MAX][MAX], int a, int b) {
  int i, j;
  for (i = -1; i <= 1; i++)
    for (j = -1; j <= 1; j++)
      if (relative[a+i][b+j] == 1)
	return 1;
  return 0;
}
int writeImg (char image[MAX][MAX],
	      int size_m, int size_n, char buffer[LEN_LINE]) {
  char name[LEN_LINE];
  char cmd;
  sscanf (buffer, "%c %s", &cmd, name);

  printf ("%s\n", name);
  int i, j;
  for (j = 1; j <= size_n; j++) {
    for (i = 1; i <= size_m; i++)
      printf ("%c", image[i][j]);
    printf ("\n");
  }
  return 0;
}
