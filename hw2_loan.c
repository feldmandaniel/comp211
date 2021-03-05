#include <stdio.h>
#include <math.h>

long double monthly_pay(long double loan_amount, long double term, long double apr){
  long double mon_pay, r, apr_synth;
  term = term * 12;
  apr_synth = pow(1 + apr/12, term);
  mon_pay = (loan_amount * apr_synth * apr) / (12 * (apr_synth - 1));
  return mon_pay;
  }

long double calculate_interest(long double loan_amount, long double term, long double apr){
  long double interest, i = 0;
  term = term * 12;
  while (i < term){
  i = i + 1;
  interest = loan_amount * (apr / 12);
  }
  return interest;
  }

long double calculate_loan(long double loan_amount, long double term, long double apr){
  int i = 0;
  long double principle, interest, total_interest = 0;
  long double mon_pay = monthly_pay(loan_amount, term, apr);
  printf("Month\t\tPrinciple\t\tInterest\t\tRemaining\n");
  printf("-----------------------------------------------------------------------------\n");
  term = term * 12;
  while (i < term){
  i = i + 1;
  interest = calculate_interest(loan_amount, term, apr);
  total_interest = total_interest + interest;
  principle = mon_pay - interest;
  loan_amount = loan_amount - principle;
  printf("%d\t\t%Lf\t\t%Lf\t\t%Lf\n",i, principle, interest, loan_amount);
}
  printf("-----------------------------------------------------------------------------\n");
  printf("Monthly payment = %Lf; total_interest = %Lf\n", mon_pay, total_interest);
 return loan_amount;
}


int main() {
  long double term, apr, loan_amount;
  printf("Loan amount: ");
  scanf("%Lf", &loan_amount);
  printf("Term in years (must be an integer): ");
  scanf("%Lf", &term);
  printf("Interest (for 5 percent, enter 0.05, etc.): ");
  scanf("%Lf", &apr);
  calculate_loan(loan_amount, term, apr);
  return 0;
}
