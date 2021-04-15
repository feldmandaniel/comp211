/* Richard Lourie hw6
"hw6.c"
*/

#include "hw6.h"
#include <stdio.h>
#include <stdlib.h>

void print_array(char c[], int size);

struct buffer
{
  int insertionMark ;
  char c[BUF_LEN - 1] ;
} ;

buffer *empty()
{
  buffer *b = malloc(sizeof(buffer)) ;
  b->insertionMark = 0 ;

  return b ;
}

void insert(buffer *b, char c)
{
  for(int i = ((b->insertionMark) + 1); i < (BUF_LEN - 2) ; i = i + 1)
  {
    b->c[i + 1] = b->c[i];
  }
  b->c[(b->insertionMark) + 1] = c;
  b->insertionMark++;

}

void delete_left(buffer *b)
{
  /* Fix duplicate character at end of buffer
  */
  if(b->insertionMark != 0)
  {
    for(int i = (b->insertionMark) ; i < BUF_LEN - 2; i++)
    {
      b->c[i] = b->c[i + 1];
    }
  }

  b->insertionMark--;
}

void delete_right(buffer *b)
{
  if(b->insertionMark != BUF_LEN - 2)
  {
    for(int i = ((b->insertionMark) + 1) ; i < BUF_LEN - 2; i++)
    {
      b->c[i] = b->c[i + 1];
    }
  }
}

void move_left(buffer *b)
{
  if(b->insertionMark != 0)
    (b->insertionMark)--;
}

void move_right(buffer *b)
{
  if(b->insertionMark != BUF_LEN - 2)
    (b->insertionMark)++;
}

void set(buffer *b, int n)
{
  b->insertionMark = n ;
}

void contents(buffer *b, char d[], char e[])
{
  printf("Contents was called with ") ;
  print_array(b->c, BUF_LEN - 1) ;
  printf("\n") ;

  for(int i = 0 ; i <= b->insertionMark ; i++)
  {
    d[i] = (b->c)[i] ;
  }

  for(int i = ((b->insertionMark) + 1) ; i <= BUF_LEN - 2 ; i++)
  {
    e[i - (b->insertionMark) - 1] = (b->c)[i] ;
  }
  print_array(d, BUF_LEN - 1) ;
}

void print_array(char c[], int size)
{
  for(int i = 0 ; i < size ; i++)
  {
    printf("%c", c[i]) ;
  }
}

void print_buffer(buffer *b)
{
  char d[(b->insertionMark) + 1] ;
  char e[BUF_LEN - 1 - (b->insertionMark)] ;

  contents(b, d, e) ;

  print_array(d, (b->insertionMark) + 1);
  printf("|");
  // print_array(e, BUF_LEN - 2 - (b->insertionMark)) ;
}
