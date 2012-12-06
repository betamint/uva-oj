#include<stdio.h>
#include<string.h>
#define MAXLEN 100 + 5

char l1[MAXLEN];
char l2[MAXLEN];
char s[5][MAXLEN];

int main() {
  int n;
  int i, j, k;
  scanf("%d", &n);
  fgets(l1, MAXLEN, stdin);
  for(i = 0; i < n; i++) {
    fgets(l1, MAXLEN, stdin);
    fgets(l2, MAXLEN, stdin);

    for(j = 0; j < 5; j++) s[j][0] = 0;
    for(j = 0; l1[j] != '<'; j++) sprintf(s[0] + strlen(s[0]), "%c", l1[j]);
    for(j++; l1[j] != '>'; j++) sprintf(s[1] + strlen(s[1]), "%c", l1[j]);
    for(j++; l1[j] != '<'; j++) sprintf(s[2] + strlen(s[2]), "%c", l1[j]);
    for(j++; l1[j] != '>'; j++) sprintf(s[3] + strlen(s[3]), "%c", l1[j]);
    for(j++; l1[j] != 0; j++) sprintf(s[4] + strlen(s[4]), "%c", l1[j]);

    j = 0;
    while(l2[j] != '.') j++;
    l2[j] = 0;

    printf("%s%s%s%s%s", s[0], s[1], s[2], s[3], s[4]);
    printf("%s%s%s%s%s", l2, s[3], s[2], s[1], s[4]);
  }
  return 0;
}
