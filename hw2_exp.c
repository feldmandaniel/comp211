#include <stdio.h>
int main() {
    unsigned long fact;
    double power = 0;
    unsigned long x;
    unsigned long exponent;
    double dummy = 1;
    double lastterm = 1;
    unsigned long e = 1;
    unsigned long result;
    printf("Enter an integer: ");
    scanf("%lu", &x);

    // shows error if the user enters a negative integer
    if (x < 0)
        printf("Error! Try again, factorial of a negative number doesn't exist.");
    else {
        for (fact = 1, power = 0, dummy = 1; x - power > 0; power++) {
             fact *= (x + power);
             printf("fact = %lu\n", fact);
             dummy = (dummy * x);
             printf("power = %f\n", lastterm);
             lastterm = dummy/fact;
             printf("lastterm = %f\n", lastterm);
             printf("lastterm = %f\n", lastterm);

        }
        lastterm = dummy/fact;
        printf("lastterm = %f\n", lastterm);
        printf("Factorial = %lu\n", fact);


        /*for (dummy = 1; exponent > 0; --exponent){
            dummy = (dummy * x);
            printf("x = %lu\n", dummy);*/
        }
      printf("x to the power = %f\n", dummy);
    return 0;
}


// review psuedo-code
// write out in python
