#include<stdio.h>
#define MAX 1000
#define SCALE 100
int main () {
  int n;
  long fee[MAX];
  while (scanf ("%d", &n) != EOF && n != 0) {
    long sum = 0, exchange = 0;
    long mean, over;
    long highers = n;
    long i;
    double tmp;
    for (i = 0; i < n; i++) {
      scanf ("%lf", &tmp);
      fee[i] = (long)(tmp * SCALE + 0.5);
      sum += fee[i];
    }
    mean = sum / n;
    over = sum % n;
    for (i = 0; i < n; i++)
      if (fee[i] <= mean) {
	exchange += mean - fee[i];
	highers--;
      }
    if (over > highers)
      exchange += over - highers;
    printf ("$%.2f\n", (double)exchange / SCALE);
  }
  return 0;
}
