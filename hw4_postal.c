
/* Daniel Feldman
   March 19, 2021  */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void automate_bars(bool len1, bool len2, bool len3, bool len4, bool len5);
void print_bar_for_dig(int digit);
void print_number_bars(unsigned int postal);
void draw_bar(bool full_half);


int main(){
  unsigned int usr_post;
  printf("Enter a 5-digit ZIP code: ");
  scanf("%u\n", &usr_post);
  usr_post = print_number_bars(12345);
  return 0;
}

void draw_bar(bool full_half) {
  /* returns full-length bar for full_half == true;
  returns half-length full_half == false  */
  if (full_half == true){
    printf("********\n");
  }
  else{
    printf("****\n");
  }
  return;
}

void automate_bars(bool len1, bool len2, bool len3, bool len4, bool len5){
  /* returns adequate 5-bar combination of full and half-length bars for each
     were the n-th boolean dictates the length of the n-th bar */
  draw_bar(len1);
  draw_bar(len2);
  draw_bar(len3);
  draw_bar(len4);
  draw_bar(len5);
  return;
}


void print_bar_for_dig(int digit){
  /* returns adequate 5-bar combination of full and half-length bars for each
     digit from 0-9.  */
  if (digit == 0){
    automate_bars(true, true, false, false, false);
  }
  else if (digit == 1){
    automate_bars(false, false, false, true, true);
  }
  else if (digit == 2){
    automate_bars(false, false, true, false, true);
  }
  else if (digit == 3){
    automate_bars(false, false, true, true, false);
  }
  else if (digit == 4){
    automate_bars(false, true, false, false, true);
  }
  else if (digit == 5){
    automate_bars(false, true, false, true, false);
  }
  else if (digit == 6){
    automate_bars(false, true, true, false, false);
  }
  else if (digit == 7){
    automate_bars(true, false, false, false, true);
  }
  else if (digit == 8){
    automate_bars(true, false, false, true, false);
  }
  else if (digit == 9){
    automate_bars(true, false, true, false, false);
  }
  return;
}

void print_number_bars(unsigned int postal){
  /* returns a full-height bar followed by the
  adequate 5-bar combination of full and half
  length bars  for each digit in the zip code,
  followed by the bars for the checksum digit,
  followed by a full-height bar.  */
  int digit, checksum = 0, sub, b;
  printf("The postal bar code for %u:\n", postal);
  draw_bar(true);
  for (int k = 4; k >= 0; k = k - 1){
    printf("\n");
    b = postal / pow(10, k);
    postal = postal - (b * pow(10, k));
    print_bar_for_dig(b);
    checksum = checksum + b;
  }
  checksum = checksum % 10;
  print_bar_for_dig(checksum);
  draw_bar(true);
  return;
}
