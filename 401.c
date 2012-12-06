#include<stdio.h>
#include<string.h>
#include<ctype.h>
char reverse[] = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";
int main() {
  char word[25];
  int i, len, locate;
  int palin, mirror;
  while(scanf("%s", word) == 1) {
    len = strlen(word);
    palin = 1;
    for(i = 0; i < len / 2 + 1; i++) {
      if(word[i] != word[len - i - 1]) palin = 0;
    }
    mirror = 1;
    for(i = 0; i < len / 2 + 1; i++) {
      if(isalpha(word[i])) locate = word[i] - 65;
      else locate = word[i] - 49 + 26;
      if(reverse[locate] != word[len - i - 1]) mirror = 0;
    }
    switch(palin + mirror * 2) {
    case 0:
      printf("%s -- is not a palindrome.\n\n", word);
      break;
    case 1:
      printf("%s -- is a regular palindrome.\n\n", word);
      break;
    case 2:
      printf("%s -- is a mirrored string.\n\n", word);
      break;
    case 3:
      printf("%s -- is a mirrored palindrome.\n\n", word);
    }
  }
  return 0;
}
