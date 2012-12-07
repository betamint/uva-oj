#include<stdio.h>
#include<string.h>
#define MAX 30
char buf[MAX * 3];
int stack[MAX];
int ordered[MAX];
int position(int x);
int flip(int x);
int int_cmp(int* x, int* y);
int main() {
  int pancakes;
  char c;
  int i, p;
  int end = 0;
  for(;;) {
    pancakes = 0;
    while(scanf("%d", &stack[pancakes++]) != EOF && getchar() != '\n') NULL;
    if(pancakes == 1) break;

    printf("%d", stack[0]);
    for(i = 1; i < pancakes; i++) printf(" %d", stack[i]);
    printf("\n");

    memcpy(ordered, stack, MAX);
    qsort(ordered, pancakes, sizeof(int), int_cmp);

    for(i = pancakes - 1; i >= 0; i--)
      if((p = position(ordered[i])) != i) {
	if(p != 0) {
	  flip(p);
	  printf("%d ", pancakes - p);
	}
	flip(i);
	printf("%d ", pancakes - i);
      }
    printf("0\n");
  }
  return 0;
}
int position(int x) {
  int i = 0;
  while(stack[i++] != x) NULL;
  return i - 1;
}
int flip(int x) {
  int i, t;
  for(i = 0; i < x - i; i++) {
    t = stack[i];
    stack[i] = stack[x - i];
    stack[x - i] = t;
  }
  return 0;
}
int int_cmp(int* x, int* y) {
  return *x - *y;
}
