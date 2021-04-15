/* COMP 211 HW 6:  Using arrays to implement an editor buffer
 *
 * Driver program.
 *
 * N. Danner
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "hw6.h"

struct menu_opt {
    char* desc ;
    void (*act)(void) ;
} ;

/* Yes, I know I have said to not use global variables, except for constants.
 * But this program does in fact require a single global variable for the
 * (pointer to the) editor buffer, because it defines many different functions
 * that all need to modify it.
 *
 * But in fact, the way we use buf, it *is* actually constant, because the
 * value of buf is a heap location, and that never changes as this program
 * executes.   The contents of the heap at that location do change, but not
 * the location itself.
 *
 * We could get away without making this global if we were to define all the
 * do_ functions below locally to main.  But that is not permitted by the C
 * standard (though it is allowed by most modern compilers).
 */
buffer *buf = NULL ;

void do_exit() {
    free(buf) ;
    exit(0) ;
}

void do_make_empty() {
    if (buf != NULL) free(buf) ;
    buf = empty() ;
} ;

void do_insert() {
    char c ;
    printf("Enter character: ") ;
    scanf(" %1c", &c) ;
    insert(buf, c) ;
}

void do_delete_left() {
    delete_left(buf) ;
} ;

void do_delete_right() {
    delete_right(buf) ;
} ;

void do_move_left() {
    move_left(buf) ;
} ;

void do_move_right() {
    move_right(buf) ;
} ;

void do_set() {
    int n ;
    printf("Enter position: ") ;
    scanf("%d", &n) ;
    set(buf, n) ;
}

void do_print() {
    print_buffer(buf) ;
}

int main(int argc, char **argv) {

    /*
    struct menu_opt menu[] = {
        mnu_exit,
        mnu_empty,
        mnu_moveleft
    } ;
    */

    struct menu_opt menu[] = {
        {"Exit", do_exit},
        {"Create empty buffer", do_make_empty},
        {"Insert character", do_insert},
        {"Delete left", do_delete_left},
        {"Delete right", do_delete_right},
        {"Move insert mark left", do_move_left},
        {"Move insert mark right", do_move_right},
        {"Set insert mark position", do_set} ,
        {"Print buffer", do_print}
    } ;

    // WARNING:  this method for computing the size of an array only works when
    // the array is declared on the stack.  In particular, it is not valid when
    // the array is allocated using malloc, calloc, etc.
    int n_menu = sizeof(menu)/sizeof(struct menu_opt) ;

    int choice ;
    // buffer_contents cnt ;

    while (true) {

        for (int i=0; i<n_menu; ++i) {
            printf("(%d) %s\n", i, menu[i].desc) ;
        }
        printf("Enter choice: ") ;
        scanf("%u", &choice) ;
        menu[choice].act() ;

        printf("Buffer contents:\n") ;
        char left[BUF_LEN], right[BUF_LEN] ;
        contents(buf, left, right) ;
        printf("%s|%s\n", left, right) ;
    }

    return 0 ;
}
