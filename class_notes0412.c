/* the editor buffer abstract type value "abcd|efghi"
insert(z):        delete_left:    delete_right:   move_right:
"abcdefghi"       "ab|defghi"     "abc|efghi"    "abcd|efghi"
                insert(z) = z-1   insert(z) = z
struct buffer {
char cs[48]; <- cs:[a, z, q, d, f, m, r, s...] --> to 48 characters
int size;
int insert;
}

cs: [a, b, c, d, e, f, g, h, i ...]  --> insert(b,'z') -->  cs: [a, b, c, d, e, z, f, g, h, i ...]
size: 9     insert: 2                     --> --> -->       size: 10    insert: 3

void insert(struct buffer *b, char c){
shift cs[insert + 1], ..., cs[size - 1] to cs[insert + 2], ..., cs[size] --> loops over all of the values where insert + i < size (or size - 1)
cs[insert + 1] = c;
size = size + 1;
insert = insert + 1;
}

USE THE NAMES HE GIVES, WHEN RUNNING MAKE SURE THAT CODE RUNS   C O M P L E T E L Y   S M O O T H L Y

doesn't go into code, but tells us how to write our code– defines what we mean:
represents a buffer with characters cs[0], ..., cs[size - 1]
insert = index of the character to the left of the insertion mark.



Linked lists:
strct arrayseq{
int xs[100];  <- xs[4, 19, 12, 83, ...] -> <4, 19, 12>
int sizeof;   <- size: 3                ->
}

linked lists is literallly the fastest way to access an element in the heap
*/
