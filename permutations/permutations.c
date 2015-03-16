#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "permutations.h"

struct cycle * new_cycle( int length, ... ) {
    int i;
    int * new_elements = malloc( length * sizeof(int) );

    if ( !new_elements ) {
        return NULL;
    }
    struct cycle * new_cycle = malloc( sizeof( struct cycle ) );
    if ( !new_cycle ) {
        return NULL;
    }
    va_list arg_pointer;
    va_start( arg_pointer, length );
    for ( i = 0; i < length; i++ ) {
        new_elements[i] = va_arg( arg_pointer, int );
    }
    va_end( arg_pointer );
    new_cycle->elements = new_elements;
    new_cycle->length = length;
    return new_cycle;
}

void apply_cycle( struct cycle * c , int * a ) {
    int t = a[c->elements[0]];
    int i;

    for ( i = 0; i <= c->length - 2; i++ ) {
        a[c->elements[i]] = a[c->elements[i + 1]];
    }

    // Now i = c->length-1
    a[c->elements[i]] = t;
}
