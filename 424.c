#include<stdio.h>
#include<string.h>
#define MAX 100 + 5
char inp[MAX];
int num[MAX];
int sum[MAX];
int main() {
  int nlen, slen = 0;
  int i;
  int res, g;
  memset(sum, 0, sizeof(sum));
  while(scanf("%s", inp) != EOF) {
    if(strcmp(inp, "0") == 0) break;

    nlen = strlen(inp);
    if(slen < nlen) slen = nlen;
    for(i = 0; i < nlen; i++) num[i] = inp[nlen - 1 -i] - '0';

    g = 0;
    for(i = 0; i < slen; i++) {
      res = sum[i] + num[i] + g;
      g = res / 10;
      sum[i] = res % 10;
    }
    if(g != 0) sum[slen++] = g;
  }
  for(i = slen - 1; i >= 0; i--) printf("%d", sum[i]);
  printf("\n");
  return 0;
}
