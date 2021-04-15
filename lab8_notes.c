// /*
// hd -> value = 8, hd -> next -> value = 5,
// hd -> next -> next -> value = 7,
// hd -> next -> next -> next = NULL.
// hd -> next = 624
//         mem_loc = 600             mem_loc = 624             mem_loc = 616
// hd -> [value: 8 | next: 624] -> [value: 5 | next: 616] -> [value: 7 | next: x] -> x
//
// represents the sequence of values (8, 7, 5)
// */
// struct node{
//   /* this allocated memory in the heap with a
//   value and a pointer to a next value.
//   The next value is the memory location of the next value. */
//   int value;
//   struct node *next;
// }
//
// struct node * hd = malloc(sizeof(struct node));
//
// add (struct node){
// /* to add up the #s in the seq tstarting at hd */
//   int sum = 0;
//   struct nod & p = hd;
//   while (p = NULL){
//     sum = sum + p -> value; /* process node p */
//     p = p -> next; /* "move" node p to next node */
//   }
// }
//
// point_to_k{
//   struct node * p = hd;
//   for (int i = 0, i < k, i + 1){
//     p = p -> next;
//   }
// }
//
// /* insert 3 at index 0: hd represent seq <3, 8, 5, 7> */
//
// m = malloc( - - - );   /* (1) make a new node m. */
// m -> value = 3;        /* (2) set value field of m to 3. */
// m -> next = hd;        /* (3) set succesor of m to 8. */
// hd = m;                /* (4) set hd to m. */
//
// m = malloc( - - - );   /* (1) make a new node m. */
// m -> value = 3;        /* (2) set value field of m to 3. */
// m -> next = hd;        /* (3) set succesor of m to 8. */
// hd = m;                /* (4) set hd to m. */


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
                node* m = malloc(sizeof(node)) ;
                m->val = val ;
                m->next = hd ;
                hd = m ;
            }
            else {
                node* m = hd ;
                node* n = malloc(sizeof(node)) ;

                /* Move m to the index-(index-1) node, which is the node just
                 * before where we want the new node.
                 */
                for (int i=0; i<index-1; i+=1) m = m->next ;

                n->val = val ;
                n->next = m->next ;
                m->next = n ;

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

            if (index == 0) {
                /* Move hd to its successor, free hd.
                 */
                node* m = hd ;
                hd = hd->next ;
                free(m) ;
            }
            else {
                node* m = hd ;
                node* n ;

                /* Move m to the node just before the one we want to delete.
                 */
                for (int i=0; i<index-1; i+=1) m = m->next ;

                /* Remember the node we are going to delete in order to free it.
                 */
                n = m->next ;

                /* Make m's next pointer "jump over" n.
                 */
                m->next = m->next->next ;

                /* Free the node we have deleted from the sequence.
                 */
                free(n) ;
            }
        }

        else if (choice > 0) {
            printf("Invalid choice!\n") ;
        }
    } while (choice != 0) ;

    return 0 ;
}
