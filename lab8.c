/*  COMP 211 Lab 8:  singly-linked lists.
 *
 *  N. Danner
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Singly-linked node structure type.
 */
struct node {
    char val ;
    struct node* next ;
} ;

/* This line makes "node" an abbreviation for "struct node".
 */
typedef struct node node ;

/* length(n) = the length of the list that starts at node n.
 */
int length(node* n) {
    int l = 0 ;
    while (n != NULL) {
        l += 1 ;
        n = n->next ;
    }

    return l ;
}

/* print_seq(n) prints the characters of the sequence that begins at n.
 */
void print_seq(node* n) {
    printf("<") ;
    while (n != NULL) {
        printf("%c", n->val) ;
        n = n->next ;
    }
    printf(">\n") ;
}

int main() {

    node* hd = NULL ;

    int choice ;

    do {
        /* Print the sequence.
         */
        printf("Current sequence: ") ;
        print_seq(hd) ;
        printf("\n") ;

        printf("(0) Exit.\n") ;
        printf("(1) Insert value.\n") ;
        printf("(2) Delete value.\n") ;
        printf("Enter choice: ") ;
        scanf(" %d", &choice) ;

        if (choice == 1) {
            int index ;
            char val ;
            printf("Enter index for new value: ") ;
            scanf(" %d", &index) ;

            if (index > length(hd)) {
                printf("Invalid index!\n") ;
                continue ;
            }

            printf("Enter value (character): ") ;
            scanf(" %c", &val) ;

            if (index == 0) {
                /* Your code here.  To put a new value at index 0, make a new
                 * node, makes its value val, make its successor hd, and then
                 * reassign hd to the new node.
                 */
                 node index_0 = malloc(sizeof(node));
                 index_0 -> next = hd;
                 index_0 -> val = val;
                 hd = index_0;
            }
            else {
                /* Your code here.  To put a new value at index idx > 0,
                 * traverse the linked list to the node at index idx-1.  Then
                 * make a new node, make its value val, make its successor the
                 * node at index idx, and make it the successor of the node at
                 * index idx-1.
                 */
                 node * dummy = hd;
                 node * index_not_0 = malloc(sizeof(node));
                 n -> val = val;

                 for(int i = 0; i = index; i = i + 1){
                   index_not_0 = index_not_0 -> next;
                 }

                 n -> next = m -> next;
                 m -> next = n;
            }
        }

        else if (choice == 2) {
            int index ;
            printf("Enter index to delete: ") ;
            scanf(" %d", &index) ;

            if (index >= length(hd)) {
                printf("Invalid index!\n") ;
                continue ;
            }

            /* Your code here.  To delete the index-0 node, reassign hd to its
             * successor.  To delete the value at index idx > 0, traverse the
             * linked list to the node at index idx-1.  Then make that node's
             * successor its "double successor" to jump over the node at index
             * idx.  After you have these ideas implemented, go back and figure
             * out how to free the node that have been removed from the
             * sequence.
             */


        }

        else if (choice > 0) {
            printf("Invalid choice!\n") ;
        }
    } while (choice != 0) ;

    return 0 ;
}
