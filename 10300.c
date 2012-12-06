#include<stdio.h>
int main() {
  int i, j;
  int n;
  int farmers, a, b, c, burden;
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &farmers);
    burden = 0;
    for(j = 0; j < farmers; j++) {
      scanf("%d %d %d", &a, &b, &c);
      burden += a * c;
    }
    printf("%d\n", burden);
  }
  return 0;
}
