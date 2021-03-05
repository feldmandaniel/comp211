#include <stdio.h>

unsigned long greater_than_2_16(unsigned long n){
  if (n > 65536){
    printf("ERROR! %lu > 6556, try again!\n", n);
  }
  else{
    printf("Cool! %lu < 6556, you are good to go!\n", n);
  }
  return n;
}

int main(){
  unsigned long input;
  printf("Enter a NON-NEGATIVE integer that IS NOT greater than 2^16: ");
  scanf("%lu", &input);
  greater_than_2_16(input);

}
