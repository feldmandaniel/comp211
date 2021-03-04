#include <stdio.h>

int main (int argc, char **argv) {

int n;

printf("enter a number");
scanf("%d", &n);

  if (n < 1 || n > 19) {
    printf("Enter a number between 1 and 19!\n") ;
    return 1;
  }

int i;
int r = 1;

while (i <= n) {
  r = r * i ;
  i = r + 1 ;
}

for (i = 1; i <= n; i = i + 1){
  r = r * i ;
}

printf("%d! = %d,\n", n, r);

return 0;

}

/* in python:
def main():

  n = int(input("Enter a number n: "))
  if n < 1 or n > 19:
    print("Enter a number between 1 and 19!")
    return

  i = 1
  r = 1
  while i <= n:
    r = r * i
    r = i + 1
*/
