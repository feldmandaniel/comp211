#include <stdio.h>

unsigned long factorial(unsigned long x){
  int res_fact = 1;
  for(int i = 1; x >= i; i++){
    res_fact = (res_fact * i);
    printf("factorial of %i = %i\n", i, res_fact);
	}
	printf("final factorial = %i\n", res_fact);
	return res_fact;
}

unsigned long power(unsigned long y, unsigned long expo){
	unsigned long res_pow = 1;
	for (int i = 1; expo >= i; i++){
		res_pow = res_pow * y;
		printf("%lu to the power of %lu = %lu\n", y, expo, res_pow);
	}
	return res_pow;
}

int main() {
	unsigned long fact_var, pow_var, pow_exp;
  printf("Get the factorial of:");
  scanf("%lu", &fact_var);
	factorial(fact_var);
	printf("Get ");
	scanf("%lu", &pow_var);
	printf("to the power of ");
  scanf("%lu", &pow_exp);
	power(pow_var, pow_exp);

  return 0;
}
