#include<stdio.h>
#include<ctype.h>
int main() {
  int i;
  int is_nline, n = 0;
  char c;
  while(scanf("%c", &c) != EOF) {
    if(c == '\n')
      if(is_nline) printf("\n");
      else { is_nline = 1; printf("\n"); }
    else is_nline = 0;    
    if(isdigit(c)) n += c - '0';
    if(isalpha(c) || c == '*') {
      if(c == 'b') c = ' ';
      for(i = 0; i < n; i++) printf("%c", c);
      n = 0;
    }
    if(c == '!') printf("\n");
  }
  return 0;
}
