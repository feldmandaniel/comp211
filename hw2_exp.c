#include <stdio.h>

int factorial(int x){
  int result = 1;
  for(int i = 1; x >= i; i++){
    result = (result * i);
    printf("factorial of %i = %i\n", i, result);
	}
	printf("final factorial = %i\n", result);
	return result;
}

int main() {

  factorial(6);

}
