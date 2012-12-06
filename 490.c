#include<stdio.h>
#include<string.h>
#define NUM 100 + 5
char s[NUM][NUM];
int main() {
  int i, j;
  int n = 0, max_len = 0;
  memset(s, 0, sizeof(s));
  while(fgets(s[n++], NUM, stdin) != 0)
    if(strlen(s[n-1]) - 1 > max_len)
       max_len = strlen(s[n-1]) - 1;
  n--;
  for(i = 0; i < n; i++) {
    for(j = NUM - 1; s[i][j] != '\n'; j--)
      s[i][j] = ' ';
    s[i][j] = ' ';
  }
  for(i = 0; i < max_len; i++) {
    for(j = 0; j < n; j++)
      printf("%c", s[n-j-1][i]);
    printf("\n");
  }
  return 0;
}
