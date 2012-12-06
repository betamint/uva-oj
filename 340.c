#include<stdio.h>
#define MAX 1000 + 5
int secret[MAX], guess[MAX];
int secret_match[MAX], guess_match[MAX];
int main() {
  int game = 0, end;
  int n, strong, weak;
  int i, j;
  while(scanf("%d", &n) != EOF && n != 0) {
    game++;
    printf("Game %d:\n", game);
    for(i = 0; i < n; i++) scanf("%d", &secret[i]);
    for(;;) {
      for(i = 0; i < n; i++) scanf("%d", &guess[i]);
      end = 1;
      for(i = 0; i < n; i++) if(guess[i] != 0) end = 0;
      if(end) break;

      memset(secret_match, 0, sizeof(secret_match));
      memset(guess_match, 0, sizeof(guess_match));
      strong = 0;
      weak = 0;
      for(i = 0; i < n; i++)
	if(guess[i] == secret[i]) {
	  guess_match[i] = 2;
	  secret_match[i] = 2;
	  strong++;
	}
      for(i = 0; i < n; i++)
	if(!guess_match[i])
	  for(j = 0; j < n; j++)
	    if(!secret_match[j] && guess[i] == secret[j]) {
	      guess_match[i] = 1;
	      secret_match[j] = 1;
	      weak++;
	      break;
	    }
      printf("    (%d,%d)\n", strong, weak);
    }
  }
  return 0;
}
