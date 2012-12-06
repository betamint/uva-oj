#include<stdio.h>
#include<string.h>
int main() {
  int i, j;
  int n;
  char s[25];
  int xs, max, sum;
  while(scanf("%d", &n) == 1 && n != 0) {
    max = 0;
    sum = 0;
    for(i = 0; i < n; i++) {
      xs = 0;
      scanf("%s", s);
      xs += strlen(s);
      if(xs < 25) {
	scanf("%s", s);
	xs += strlen(s);
      }
      sum += xs;
      if(xs > max) max = xs;
    }
    printf("%d\n", n * max - sum);
  }
  return 0;
}
