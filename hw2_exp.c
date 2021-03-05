#include <stdio.h>

unsigned long factorial(unsigned long x){
  unsigned long res_fact = 1;
  for(int i = 1; x >= i; i++){
    res_fact = (res_fact * i);
	}
	return res_fact;
}

unsigned long calculate_power(unsigned long y, unsigned long expo){
	unsigned long res_pow = 1;
	for (unsigned long i = 1; expo >= i; i++){
		res_pow = res_pow * y;
	}
	return res_pow;
}

unsigned long calculate_e(unsigned long n){
	unsigned long power = 0, pow_fact;
	double pow_pow, e = 1;
	long double eps = 0.00000001, lastterm = 1;
	while (lastterm > eps){
		power = power + 1;
		pow_fact = factorial(power);
		pow_pow = calculate_power(n, power);
		printf("factorial of %lu = %lu, %lu to the power of %lu = %f\n", power, pow_fact, n, power, pow_pow);
		lastterm = pow_pow / pow_fact;
		printf("lastterm = %Lf, at iteration = %lu\n", lastterm, power);
		e = e + lastterm;
			printf("e = %f\n", e);
	}
	printf("e to the power of %lu = %f\n", n, e);
	return e;
}

int main() {
	unsigned long e_var;
  printf("Get e to the power of: ");
  scanf("%lu", &e_var);
	calculate_e(e_var);
  return 0;
}
