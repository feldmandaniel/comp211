#include <stdio.h>

void print_array(double c[], int nc){
  for (int i = 0; i < nc; i += 1){
    printf("c[%d] = %lf\n", i, c[i]);
  }
  return;
}

void fill_array(double a[], int len){
  for (int i = 0; i < len; i += 1){
    double j;
    printf("Enter the value for a[%d]: ", i);
    scanf("%lf", &j);
    a[i] = j;
  }

  return;
}

int main(){

  /*An arrray deleration

  a is an array of int of length 5.
  a rerpresentts a sequense of int values.
  the values are: a[0], a[1], a[2], a[3], a[4].

  te value of a[0], etc. are unspecified
  (i.e. these are random numbers)
  */
  const int len = 5;
  double array[len];

  fill_array (array[len], len);
  print_array(array[len], len)
  return 0;
}
