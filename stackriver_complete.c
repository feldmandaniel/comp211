/* COMP 211 Lab 7:  Stack interface, driver, and implementation.
 *
 * N. Danner
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* **********
 * Stack interface.
 * **********
 */

/* The stack type.  A stack value abstractly is a stack of integers, with
 * direct access to only the integer on top.
 *
 * In documentation we will write <n_0,...,n_{k-1}> for a stack with elements
 * n_0,...,n_{k-1} bottom-to-top (so n_{k-1} is the top element and <> denotes
 * the empty stack.
 *
 * Also in documentation we treat a struct stack and a struct stack* as the
 * same type.
 */
struct stack ;

/* create() = <>.
 *
 * I.e., create() returns an empty stack.
 *
 * The user is responsible for freeing the pointer that is returned when it is
 * no longer needed.
 */
struct stack *create() ;

/* is_empty(<n_0,...,n_{k-1}>) = true,  if k = 0 (i.e., the stack is empty)
 *                               false, otherwise.
 */
bool is_empty(struct stack *s) ;

/* push(s, x):
 *
 * Pre-condition:   s = <n_0,...,n_{k-1}>
 * Post-condition:  s = <n_0,...,n_{k-1}, x>.
 *
 * In other words, push(s, x) pushes x onto the top of the stack s.
 */
void push(struct stack *s, int x) ;

/* peek(<n_0,...,n_{k-1}>) = n_{k-1}.
 *
 * Pre-condition:  !is_empty(s).
 *
 * In other words, peek(s) = the top element of s.
 */
int peek(struct stack *s) ;

/* pop(s):
 *
 * Pre-condition:   s = <n_0,...,n_k>
 *                  !is_empty(s)
 * Post-condition:  s = <n_0,...,n_{k-1}>
 *
 * In order words, pop(s) pops the top element off of s.
 */
void pop(struct stack *s) ;

/* print_stack(s):
 *
 * Post-condition:  a representation of s is printed to the terminal.
 *
 * A typical stack interface would never provide this function, because the
 * whol idea of using a stack is that the client only ever knows what is on the
 * top.  But since we're just learning about them, it can be helpful to know
 * the entire contents.
 */
void print_stack(struct stack *s) ;


/* **********
 * Driver program.
 *
 * A driver program that presents a menu of options for manipulating a stack.
 *
 * Notice that we can write this program without knowing the implementation; all we need to know is the interface as just given!
 */

/* Print the menu of options.
 */
void print_menu() {
    printf(
        "(0) Exit.\n"
        "(1) Push a value.\n"
        "(2) Peek at top value.\n"
        "(3) Pop top value.\n"
        "(4) Print entire stack.\n"
    ) ;

    return ;
}

int main(int argc, char **argv) {

    /* The stack to manipulate.
     */
    struct stack *s = create() ;

    /* User's menu response.
     */
    int resp ;

    do {
        /* Print menu and prompt for action.
         */
        printf("\n") ;
        print_menu() ;
        printf("Enter an action: ") ;
        do {
            scanf("%d", &resp) ;
        } while (resp < 0 || resp > 4) ;
        printf("\n") ;

        /* Act.
         *
         * A switch expression is a lot like an if-else if-else if-..., but you
         * can only test against literal expressions.  It is a nicer syntax
         * menu-like things.
         */
        switch (resp) {
            case 0: break ;
            case 1:
            {
                int v ;
                printf("Enter value: ") ;
                scanf("%d", &v) ;
                push(s, v) ;
                break ;
            }
            case 2:
                if (is_empty(s)) printf("Stack is empty!\n") ;
                else printf("The top value is %d.\n", peek(s)) ;
                break ;

            case 3:
                if (is_empty(s)) printf("Stack is empty!\n") ;
                else {
                    pop(s) ;
                    printf("Popped the top value.\n") ;
                }
                break ;

            case 4:
                print_stack(s) ;
                break ;
        }

    } while (resp != 0) ;

    free(s) ;
    return 0 ;
}


/* **********
 * Stack implementation.
 *
 * An implementation consists of an actual definition of the stack type, along
 * with actual definitions of the functions specified in the interface.
 *
 * **********
 */


/* We will implement a stack using an array.  The array elements
 * "left-to-right" represent the stack "bottom-to-top."  The array size is
 * fixed, and so will be larger than the number of elements in the stack.  How
 * do we know where the "top" is?  We have another field that tells us.  It
 * turns out that in practice, when using a section of an array to represent
 * something, and an int value to represent the end of that section, it is
 * usually easiest for the int value to actually be the index one past the
 * actual last element, and that is what we do here.
 */
struct stack {
    /* The stack elements, bottom to top, are xs[0],...,xs[top-1].
     *
     * Invariant:  0 <= top <= 10.
     */
    int xs[10] ;
    int top ;
} ;

struct stack *create() {
    struct stack *s = malloc(sizeof(struct stack)) ;

    return s ;
}

bool is_empty(struct stack *s) {
    return s->top == 0 ;
}

void push(struct stack *s, int x) {
    s->xs[s->top] = x ;
    s->top += 1 ;

    return ;
}

int peek(struct stack *s) {
    return s->xs[s->top-1] ;
}

void pop(struct stack *s) {
    /* Notice that we don't really "delete" the top element; there is no such
     * notion for an array.  We just decrement s->top, which says to ignore
     * what had been the top element.
     */
    s->top -= 1 ;

    return ;
}

void print_stack(struct stack *s) {
    for (int i=s->top-1; i>=0; i-=1) {
        printf("|%1d|\n", s->xs[i]) ;
    }
    printf("---\n") ;

    return ;
}
