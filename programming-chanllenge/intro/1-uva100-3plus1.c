#include<stdio.h>
int lenOf3n1 (int n);
int maxLenOf3n1 (int a, int b);
int main () {
  int a, b;
  while (scanf ("%d %d", &a, &b) != EOF) {
    int len = maxLenOf3n1 (a, b);
    printf ("%d %d %d\n", a, b, len);
  }
  return 0;
}
int maxLenOf3n1 (int a, int b) {
  if (a > b) {
    a = a + b;
    b = a - b;
    a = a - b;
  }
  int maxlen = 0;
  int len;
  int i;
  for (i = a; i <= b; i++) {
    len = lenOf3n1 (i);
    if (len > maxlen)
      maxlen = len;
  }
  return maxlen;
}
int lenOf3n1 (int n) {
  int len = 1;
  while (n != 1) {
    if (n % 2 == 1)
      n = n * 3 + 1;
    else
      n = n / 2;
    len++;
  }
  return len;
}
