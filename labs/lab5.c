#include <stdio.h>
#include <math.h>
#include <stdbool.h>

unsigned long ilog(unsigned long n, unsigned long b){
  unsigned long k = 0;
  while (n >= b){
    k = k + 1;
    n = n/b;
    printf("k = %lu, n = %lu\n", k, n);
  }
  return (k);
}

unsigned long base_10(unsigned long n){

}

int main(int argc, char **argv) {
  unsigned long x, base, ilog_n;
  printf("Enter a number n: ");
  scanf("%lu", &x);
  printf("Enter a number b: ");
  scanf("%lu", &base);
  ilog_n = ilog(x, base);
  return printf("ilog = %lu\n", ilog_n);
}
