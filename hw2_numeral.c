#include <stdio.h>

unsigned long greater_than_2_16(unsigned long n){
  printf("Enter non-negative decimal integer to convert: ");
  scanf("%lu", &n);
  while (n > 65536){
    printf("ERROR! %lu > 65536, try again!\n", n);
    printf("Enter non-negative decimal integer to convert: ");
    scanf("%lu", &n);
  }
  printf("Cool! %lu < 65536, you are good to go!\n", n);
  return n;
}

unsigned long calculate_power(unsigned long y, unsigned long expo){
	unsigned long res_pow = 1;
	for (unsigned long i = 1; expo >= i; i++){
		res_pow = res_pow * y;
	}
	return res_pow;
}

unsigned long loan(unsigned long n, unsigned long d){
  unsigned long d_to_k, k = 16, b, n2 = n;
  char c;
  printf("Conversion to base-%lu: ", d);
  while (k > 0){
    k = k - 1;
    d_to_k = calculate_power(d, k);
    b = n2 / d_to_k;
    n2 = n2 - (b * d_to_k);
    if (d == 16 && b > 10){
      c = 'A' + (b - 10);
      printf("%c", c);
    }
    else if (n > n2){
      printf("%lu", b);
    }
  }
  printf("\n");
  return 0;
}

int main(){
  unsigned long input, converted, n, b;
  n = greater_than_2_16(input);
  printf("Enter a base: ");
  scanf("%lu", &b);
  loan(n, b);
  return 0;
}
