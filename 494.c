#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXN 5000
char s[MAXN];
int main() {
  int i, first;
  int n, count;
  while(fgets(s, MAXN, stdin) != 0) {
    n = strlen(s);
    first = 1;
    count = 0;
    for(i = 0; i < n; i++)
      if(isalpha(s[i])) {
	if(first) {
	  first = 0; count++;
	}
      }
      else first = 1;
    printf("%d\n", count);
  }
  return 0;
}
