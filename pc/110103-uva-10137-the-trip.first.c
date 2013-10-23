#include<stdio.h>
#define MAX 1000
#define SCALE 100
int main () {
  int n;
  long fee[MAX];
  while (scanf ("%d", &n) != EOF && n != 0) {
    long sum = 0, exchange_low = 0, exchange_high = 0;
    long mean, exchange;
    long i;
    double tmp;
    for (i = 0; i < n; i++) {
      scanf ("%lf", &tmp);
      fee[i] = (long)(tmp * SCALE + 0.5);
      sum += fee[i];
    }
    mean = sum / n;
    for (i = 0; i < n; i++) {
      if (fee[i] <= mean)
	exchange_low += mean - fee[i];
      if (fee[i] > mean)
	exchange_high += fee[i] - (mean + 1);
    }
    exchange = (exchange_low > exchange_high) ? exchange_low : exchange_high;
    printf ("$%.2f\n", (double)exchange / SCALE);
  }
  return 0;
}
