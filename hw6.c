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


/* Creates an empty buffer. insertionMark starts at negative one because
it is conceptually the value of the "index of the character to the left"
which in this case does not exist, but would be negative one if it did.
*/
buffer *empty()
{
  buffer *b = malloc(sizeof(buffer)) ;
  b->insertionMark = -1 ;

  return b ;
}

/*
This for loop should iterate through and move all characters to the right of
the insertion mark up one. Then the function change the character after the
insertionMark to "c", then it moves the insertion mark up one so it is to the
right of the character that was just added.
*/
void insert(buffer *b, char c)
{
  for(int i = ((b->insertionMark) + 1); i < (BUF_LEN - 2) ; i++)
  {
    b->c[i + 1] = b->c[i];
  }
  b->c[(b->insertionMark) + 1] = c;
  (b->insertionMark++);

}

/*
delete_left first checks
*/

void delete_left(buffer *b)
{
  /* Fix duplicate character at end of buffer
  */
  if(b->insertionMark != -1)
  {
    for(int i = (b->insertionMark) ; i < BUF_LEN - 2; i++)
    {
      b->c[i] = b->c[i + 1];
    }
  }

  (b->insertionMark)--;
}

void delete_right(buffer *b)
{
  /* Reduntant if, actually it's not redundant I don't think, give it a glance
  later.
  */
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
  if(b->insertionMark != -1)
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
  printf("Contents was called with buffer ") ;
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
  print_array(e, BUF_LEN - 2 - (b->insertionMark)) ;
}
