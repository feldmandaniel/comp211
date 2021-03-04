/* COMP 211 lab 4:  function definitions.
 *
 * N. Danner
 *
 */

#include <math.h>
#include <stdio.h>

/* hyp(a, b) = √(a² + b²).
 */
double hyp(double a, double b) {
    double c = sqrt(a*a + b*b) ;

    return c ;
}

/* printstars(n): prints n *'s to the terminal.
 */
void printstars(int n) {

    for (int i=0; i<n; i+=1) {
        printf("*") ;
    }
    printf("\n") ;

    return ;
}

int main(int argc, char **argv) {

    double x, y, z ;

    printf("Enter a side length: ") ;
    scanf("%lf", &x) ;

    printf("Enter another side length: ") ;
    scanf("%lf", &y) ;

    z = hyp(x, y) ;

    printf("The hyp. of a right tri with side lengths %lf and %lf if %lf.\n",
            x, y, z) ;

    printstars(40) ;

    return 0 ;
    
}
