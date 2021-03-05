#include <stdio.h>
#include <math.h>

long double monthly_pay(long double loan_amount, long double term, long double apr){
  long double mon_pay, r, apr_synth;
  term = term * 12;
  apr_synth = pow(1 + apr/12, term);
  mon_pay = (loan_amount * apr_synth * apr) / (12 * (apr_synth - 1));
  printf("loan amount = %Lf, term = %Lf, monthly pay = %Lf, and apr = %Lf\n",loan_amount, term, mon_pay, apr_synth);

  return mon_pay;
  }

long double monthly_balance(long double loan_amount, long double term, long double mon_pay){
  long double i = 0, remain_pay;
  term = term * 12;
  while (i < term){
    i = i + 1;
    remain_pay = mon_pay * (i);
  }
  printf("remain pay = %Lf\n", remain_pay);
  return remain_pay;
  }

  long double calculate_interest(long double loan_amount, long double term, long double apr, long double mon_pay){
    long double interest, i = 0;
    term = term * 12;
    while (i < term){
    i = i + 1;
    interest = loan_amount * (apr / 12);
    loan_amount = mon_pay - interest;
    printf("interest = %Lf, monthly_pay = %Lf\n", interest, mon_pay);
  }
    return interest;
  }

/*long double calculate_loan(long double loan_amount, long double mon_pay, long double interest, long double term){
  int i = 0;
  long double principle, term;
  while (i < term){
  i = i + 1;
  calculate_interest(loan_amount, )
  principle = mon_pay - interest;
  printf("principle = %Lf\n", principle);
  remaining_pay = loan_amount - principle;
  printf("remaining = %Lf\n", principle);

}
 return remain_pay;
}*/


int main() {
  long double term, interest, mp;
  interest = calculate_interest(10000, 2, 0.03, mp);
  mp = monthly_pay(10000, 2, 0.03);
  //calculate_loan(10000, mp, interest, 24);


  return 0;
}
