/* COMP 211 Homework 6:  Using arrays to implement an editor buffer
 *
 * N. Danner
 */

/* This line declares that struct buffer is a type, even though we aren't
 * writing its definition here.  It is asserting that somewhere, in some file,
 * there will be a definition of the form
 *
 *   struct buffer {
 *       ...
 *   } ;
 *
 * You will write that definition in hw6.c.
 */
struct buffer ;

/* The capacity of the editor buffer.  The editor buffer can hold at most
 * BUF_LEN - 1 characters.
 *
 * #define is a pre-processor directive; it instructs the compiler to modify
 * the source code before compiling it.  We have seen another such:  #include
 * instructs the compiler to insert the contents of the included file.
 * This #define directive tells the compiler to replace every instance of the
 * characters BUF_LEN with the characters 48.  That is technically different
 * than declaring a variable, because #define actually changes the characters
 * of the source that is compiled.  There is no "variable" BUF_LEN; it is just
 * as though you had written 48 everywhere as a magic number.
 *
 * I have told many of you to never use #define, and to define a const int
 * instead.  But it turns out that there is (at least) one instance where you
 * cannot do this:  you cannot use a const int as the size of an array
 * declaration if that declaration is not local to a function.  Unfortunately,
 * that is exactly the setting you will be in when you define struct buffer,
 * because you will have to define it at the top level of hw6.c, and part of
 * that definition will be to declare an array of size BUF_LEN.  So we must
 * use a #define to define BUF_LEN.
 */
#define BUF_LEN 48

/* This line just makes 'buffer' an abbreviation for 'struct buffer'.
 */
typedef struct buffer buffer ;

/* empty = an empty buffer.
 */
buffer *empty() ;

/* insert(buf, c) inserts c to the left of the insertion point of buf.  After
 * the insertion, the insert mark is to the right of c.
 */
void insert(buffer *, char) ;

/* delete_left(buf) deletes the character to the left of the insert mark.  If
 * there is no character to the left of the insert mark, this function has no
 * effect.
 */
void delete_left(buffer *) ;

/* delete_right(buf) deletes the character to the right of the insert mark.  If
 * there is no character to the right of the insert mark, this function has no
 * effect.
 */
void delete_right(buffer *) ;

/* move_left(buf) moves the insert mark one character to the left.  If there is
 * no character to the left of the insert mark, this functdion has no effect.
 */
void move_left(buffer *) ;

/* move_right(buf) moves the insert mark one character to the right.  If there
 * is no character to the right of the insert mark, this functdion has no
 * effect.
 */
void move_right(buffer *) ;

/* set(buf, n) sets the insert mark so that it is to the left of the n-th
 * character.  Characters are 0-indexed, so set(buf, 0) sets the insert mark to
 * the beginning of the buffer.  n may be equal to the length of the buffer; in
 * this case, the insert mark is set to the right of the last character.
 *
 * Pre-condition:  0 <= n <= len(buf).
 */
void set(buffer *, int) ;

/* contents(buf, left, right).
 *
 * Post-condition:  left and right are NULL-terminated strings corresponding to
 * the contents of buf to the left and right of the insert mark, respectively.
 *
 * Pre-conditions:  the sizes of left and right are at least one greater than
 * the contents of the buffer to the left and right of the insert mark,
 * respectively.
 */
void contents(buffer*, char[], char[]) ;

/*  print_buffer(buf).
 *
 *  Post-condition:  Some information about buf will be printed to ther
 *  terminal.
 *
 *  The implementation of this function is entirely up to you.  It is here to
 *  help you with debugging.  We will never use it, but there is an option in
 *  the driver program that will call this function with the current buffer.
 */
void print_buffer(buffer *) ;
