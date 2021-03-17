int main(){
  print("enter a ZIP code: ")
  scanf(%u, &zip)

  print_barcode(zip);
  return 0;
}

void print barcode(unsigned int z){
  int c;
  print_full_bar();
  c = checksum(z);
  print_digit_bar(c);
  print_full_bar();

  return;
}

  void print_digit_bar(int d){
    return;
  }

void checksum(int z){
  return;
}


print_bars(half, full, full, half, full){
  /*
  we end up printing a bunch of bars of each kind,
  why dont we just tell a function of wich one to print
  the bars in a certain order?

  Danner writes this funciton with booleans for
  is paramteres, interersting coice, we can just
  assign a number to both half and full and then
  that could print te exact amount of stars for each bar
  */

}
