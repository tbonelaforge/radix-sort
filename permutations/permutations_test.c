#include <stdio.h>
#include <stdlib.h>

#include "permutations.h"

void print_array(int *, int);

int main() {
    printf( "About to create a new cycle." );
    struct cycle * c = new_cycle( 3, 1, 2, 3 );
    printf( "Successfully created the cycle, it has length: %d, and elements: %d, %d, %d\n", c->length, c->elements[0], c->elements[1], c->elements[2] );
    printf( "About to create a new array to work on.\n" );
    int a[4] = { 42, 43, 44, 45 };
    printf( "Before applying the cycle, the array looks like:\n" );
    print_array( a, 4 );
    printf( "About to apply the cycle to the array\n" );
    apply_cycle( c, a );
    printf( "After applying the cycle to the array, it now looks like:\n" );
    print_array( a, 4 );
}

void print_array( int * a, int length ) {
    int i;

    printf( "[" );
    for ( i = 0; i < length; i++ ) {
        printf( "%d", a[i] );
        if ( i < length - 1 ) {
            printf( ", " );
        }
    }
    printf( "]" );
}
