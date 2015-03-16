#include <stdlib.h>
#include <stdio.h>
#include "permutation.h"

struct permutation * new_permutation( int length ) {
    int i;
    int * new_elements = malloc( length * sizeof( int ) );
    if (!new_elements) {
        return NULL;
    }
    struct permutation * new_permutation = malloc( sizeof( struct permutation ) );
    new_permutation->_elements = new_elements;
    new_permutation->_length = length;
    initialize_permutation( new_permutation );
    return new_permutation;
}

void initialize_permutation( struct permutation * self ) {
    int i;

    for ( i = 0; i < self->_length; i++ ) {
        self->_elements[i] = i;
    }
}

void destroy_permutation( struct permutation * self ) {
    free( self->_elements );
    free( self );
}

int get_permutation_length( struct permutation * self ) {
    return self->_length;
}

int get_permutation_element( struct permutation * self, int i ) {
    return self->_elements[i];
}

void swap_permutation_elements( struct permutation * self, int i, int j ) {
    int temp = self->_elements[i];

    self->_elements[i] = self->_elements[j];
    self->_elements[j] = temp;
}

void print_permutation( struct permutation * self ) {
    int i;

    printf( "[ " );
    for ( i = 0; i < self->_length - 1; i++ ) {
        printf( "%d, ", self->_elements[i] );        
    }
    printf( "%d ]", self->_elements[i] );
}
