#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int max_pow10(unsigned long digit){
  int k = 0;
  while (digit > pow(10, k)){
    k = k + 1;
    printf("k = %d\n", k);
  }
  printf("final k = %d\n", k);
  return k;
}

int sum_digits(int digit){
  int digit_sum;
  printf("digit = %d\n", digit);
  digit = 2 * digit;
  if (digit > 10){
    digit_sum = 1 + (digit % 10);
  }
  else{
    digit_sum = digit;
  }
  printf("digit_sum = %d\n", digit_sum);
  return digit_sum;
}

int checksum(unsigned long accnum){
  int odd_dig, even_dig, checksum = 0, sub_1, sub_2, k;
  int max_k = max_pow10(accnum);
  for(k = 1; max_k >= k; k = k + 2){
    sub_1 = (int) accnum % (int) pow(10, k);
    printf("sub_1 = %d\n", sub_1);
    odd_dig = (int) sub_1 / (int) pow(10, k-1);
    printf("odd_dig = %d\n", odd_dig);
    accnum = accnum - sub_1;
    printf("accnum = %lu\n", accnum);
    sub_2 = (int) accnum % (int) pow(10, k + 1);
    printf("sub_2 = %d\n", sub_2);
    accnum = accnum - sub_2;
    printf("accnum = %lu\n", accnum);
    even_dig = sum_digits(sub_2 / pow(10, k));
    printf("even_dig = %d\n", even_dig);
    checksum = checksum + odd_dig + even_dig;
    printf("checksum = %d \n", checksum);
  }
  printf("final checksum = %d\n", checksum);
  return checksum;
}

bool is_valid(int checksum){
  bool x;
  if (checksum % 10 ==0){
    x = true;
    printf("VALID BRUH\n");
  }
  else{
    printf("NOT valid bruh\n");
    x = false;
  }
  return x;
}


bool validate(accnum){
  int out_sum;
  bool valid;
  printf("Account number: ");
  scanf("%u", &accnum);
  out_sum = checksum(accnum);
  valid = is_valid(out_sum);
  return valid;
}

int find_valid_accnum(unsigned long accnum){
  bool valid;
  int out_sum;
  printf("Account number: ");
  scanf("%lu", &accnum);
  accnum = (int) accnum * (int) pow(10, 5 - max_pow10(accnum));
  printf("accnum = %lu\n", accnum);
  while (!valid) {
    accnum = accnum + 1;
    printf("accnum = %lu\n", accnum);
    out_sum = checksum(accnum);
    valid = is_valid(out_sum);
  }
  printf("accnum = %lu\n", accnum);
  return accnum;
}

int main(){
  int v;
  bool valid;
  unsigned long usr_acc;
  /*valid = validate(usr_acc);*/
  v = find_valid_accnum(usr_acc);
  return v;
}
