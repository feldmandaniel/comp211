#include <stdio.h>

/*int try_assign_while(int x){
int i = 0;
  while (i < 4){
    i = i + 1;
    x = 3;
    printf("i = %d, x = %d\n", i, x);
  }
  printf("i = %d, x = %d\n", i, x);
  return x;
}*/

int main(){
  int random_number, result;
  /*printf("give me some number: ");
  scanf("%d", &random_number);*/
  int i = 0, x = 4;
    while (i < 4){
      i = i + 1;
      x = 3;
      printf("i = %d, x = %d\n", i, x);
    }
    printf("i = %d, x = %d\n", i, x);
  /*result = try_assign_while(random_number);
  printf("result = %d\n", result);*/
  return 0;
}
