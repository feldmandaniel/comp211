#include <stdio.h>

unsigned long l2, n;

unsigned long ilog2(unsigned long n){

  for(l2 = 0; n > 1;){

    l2 += 1;
    n = n/2;

}

  return l2;

}

int main(int argc, char **argv) {

  unsigned long x, ilog;

  printf("Enter a number: ") ;
  scanf("%lu", &x) ;

  ilog = ilog2(x);

  return printf("ilog =%lu\n", ilog);
;

}
