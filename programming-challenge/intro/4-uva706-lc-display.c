#include<stdio.h>

/* WIDTH <= LEN * (SCALE + 2) + (LEN - 1) */
#define WIDTH 150
/* HEIGHT <= SCALE * 2 + 3 */
#define HEIGHT 30

#define LEN 10
#define SCALE 10

int parseDigit (long number, int digit[]);
int lcPosition (int s, int p);
int lcDisplay (int scale, int len, int digit[], char screen[HEIGHT][WIDTH]);
int printArea (char area[HEIGHT][WIDTH], int rows, int columns);
int main () {
  char screen[HEIGHT][WIDTH];
  int digit[LEN];
  int scale, len;
  long number;
  while (scanf ("%d %ld", &scale, &number) != EOF) {
    if (!(scale || number)) break;
    len = parseDigit (number, digit);
    lcDisplay (scale, len, digit, screen);
    printArea (screen, scale * 2 + 3, (scale + 3) * len - 1);
    printf ("\n");
  }
  return 0;
}
int parseDigit (long number, int digit[]) {
  if (number == 0)
    return (digit[0] = 0) + 1;
  int len = 0;
  while (number > 0) {
    digit[len++] = number % 10;
    number /= 10;
  }
  return len;
}
int lcDisplay (int scale, int len, int digit[], char screen[HEIGHT][WIDTH]) {
  char figure[10][5][3] = {
    {" - ","| |","   ","| |"," - "},  /*0*/
    {"   ","  |","   ","  |","   "},  /*1*/
    {" - ","  |"," - ","|  "," - "},  /*2*/
    {" - ","  |"," - ","  |"," - "},  /*3*/
    {"   ","| |"," - ","  |","   "},  /*4*/
    {" - ","|  "," - ","  |"," - "},  /*5*/
    {" - ","|  "," - ","| |"," - "},  /*6*/
    {" - ","  |","   ","  |","   "},  /*7*/
    {" - ","| |"," - ","| |"," - "},  /*8*/
    {" - ","| |"," - ","  |"," - "}   /*9*/
  };

  int i, j, m, n;
  for (n = 0, i = len - 1; i >= 0; i--) {
    for (m = 0; m < scale * 2 + 3; m++) {
      for (j = 0; j < scale + 2; j++) {
	screen[m][n+j] = figure[ digit[i] ]
	  [ lcPosition (scale, m) ][ lcPosition (scale,j) ];
      }
      screen[m][n+scale+2] = ' ';
    }
    n += scale + 3;
  }
  return 0;
}
int lcPosition (int s, int p) {
  /* s = scale, p = position*/
  if (p == 0)               return 0;
  if (0 < p && p < s+1)     return 1;
  if (p == s+1)             return 2;
  if (s+1 < p && p < s*2+2) return 3;
  if (p == s*2+2)           return 4;
}
int printArea (char area[HEIGHT][WIDTH], int rows, int columns) {
  int m, n;
  for (m = 0; m < rows; m++) {
    for (n = 0; n < columns; n++)
      printf ("%c", area[m][n]);
    printf ("\n");
  }
  return 0;
}

  /* alt code in lcDisplay() */
  /*
  for (m = 0; m < scale * 2 + 3; m++)
    for (n = 0; n < (scale + 2) * len + (len - 1); n++)
      screen[m][n] = ' ';
  for (m = 0, n = 0, i = len - 1; i >= 0; i--) {
    screen[m]          [n]         = figure[ digit[i] ][0][0];
    screen[m]          [n+scale+1] = figure[ digit[i] ][0][2];
    screen[m+scale+1]  [n]         = figure[ digit[i] ][2][0];
    screen[m+scale+1]  [n+scale+1] = figure[ digit[i] ][2][2];
    screen[m+scale*2+2][n]         = figure[ digit[i] ][4][0];
    screen[m+scale*2+2][n+scale+1] = figure[ digit[i] ][4][2];
    for (j = 1; j <= scale; j++) {
      screen[m]          [n+j]       = figure[ digit[i] ][0][1];
      screen[m+j]        [n]         = figure[ digit[i] ][1][0];
      screen[m+j]        [n+scale+1] = figure[ digit[i] ][1][2];
      screen[m+scale+1]  [n+j]       = figure[ digit[i] ][2][1];
      screen[m+scale+1+j][n]         = figure[ digit[i] ][3][0];
      screen[m+scale+1+j][n+scale+1] = figure[ digit[i] ][3][2];
      screen[m+scale*2+2][n+j]       = figure[ digit[i] ][4][1];
    }
    n += scale + 3;
  }
  */

