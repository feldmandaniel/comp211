#include <stdio.h>
#include <math.h>
#include <stdbool.h>



int main(){
  find_or_validate();
  return 0;
}

int max_pow10(unsigned long digit){
  int k = 0;
  while (digit > pow(10, k)){
    k = k + 1;
  }
  return k;
}

int sum_digits(int digit){
  int digit_sum;
  digit = 2 * digit;
  if (digit >= 10){
    digit_sum = 1 + (digit % 10);
  }
  else{
    digit_sum = digit;
  }
  return digit_sum;
}

int checksum(unsigned long accnum){
  int odd_dig, even_dig, checksum = 0, sub_1, sub_2, k;
  int max_k = max_pow10(accnum);
  for(k = 1; max_k >= k; k = k + 2){
    sub_1 = (int) accnum % (int) pow(10, k);
    odd_dig = (int) sub_1 / (int) pow(10, k-1);
    accnum = accnum - sub_1;
    sub_2 = (int) accnum % (int) pow(10, k + 1);
    accnum = accnum - sub_2;
    even_dig = sum_digits(sub_2 / pow(10, k));
    checksum = checksum + odd_dig + even_dig;
  }
  return checksum;
}

void is_valid(unsigned long accnum, int checksum){
  bool x;
  if (checksum % 10 ==0){
    x = true;
    printf("%lu is a valid account number.\n", accnum);
  }
  else{
    printf("%lu is not a valid account number.\n", accnum);
    x = false;
  }
  return;
}

void validate(unsigned long accnum){
  int out_sum;
  printf("Enter a prefix with an even number of digits: ");
  scanf("%lu", &accnum);
  out_sum = checksum(accnum);
  is_valid(accnum, out_sum);
  return;
}

int construct_valid_accnum(unsigned long accnum){
  int out_sum = 1;
  printf("Enter a prefix with an even number of digits: ");
  scanf("%lu", &accnum);
  accnum = accnum * pow(10, 5 - max_pow10(accnum));
  while (out_sum % 10 > 0) {
    accnum = accnum + 1;
    out_sum = checksum(accnum);
  }
  printf("Constructed account number: %lu\n", accnum);
  return accnum;
}

void find_or_validate(){
  char val_or_con;
  printf("(V)alidate or (C)onstruct? ");
  scanf("%s", &val_or_con);
  if (val_or_con == 'V'){
    validate(val_or_con);
  }
  else if (val_or_con == 'C'){
    construct_valid_accnum(val_or_con);
  }
  return;
}
