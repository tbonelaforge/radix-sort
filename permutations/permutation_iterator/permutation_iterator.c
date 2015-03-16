#include <stdlib.h>
#include <stdio.h>

#include "permutation_iterator.h"
#include "permutation.h"

struct permutation_iterator * new_permutation_iterator(int length) {
    struct permutation * new_perm = new_permutation( length );

    if ( !new_perm ) {
        return NULL;
    }
    int * new_displacements = malloc( length * sizeof( int ) );
    if ( !new_displacements ) {
        return NULL;
    }
    int * new_displacement_directions = malloc( length * sizeof( int ) );
    if ( !new_displacement_directions ) {
        return NULL;
    }
    struct permutation_iterator * new_permutation_iterator = malloc( sizeof( struct permutation_iterator ) );
    if ( !new_permutation_iterator ) {
        return NULL;
    }
    new_permutation_iterator->_permutation = new_perm;
    new_permutation_iterator->_displacements = new_displacements;
    new_permutation_iterator->_displacement_directions = new_displacement_directions;
    initialize_permutation_iterator( new_permutation_iterator );
    return new_permutation_iterator;
}

void initialize_permutation_iterator( struct permutation_iterator * self ) {
    int length = get_permutation_length( self->_permutation );
    int i;
    for ( i = 0; i < length; i++ ) {
        self->_displacements[i] = 0;
        self->_displacement_directions[i] = 1;
    }
}

struct permutation_iterator * iterate_permutation( struct permutation_iterator * self ) {
    int j = get_permutation_length( self->_permutation ) - 1;
    int s = 0; // Number of fully-displaced elements greater than j.
    int new_displacement = 0;
    int current_index = 0;
    int adjacent_index = 0;

    while ( 1 ) {
        new_displacement = self->_displacements[j] 
            + self->_displacement_directions[j];
        if ( new_displacement >= 0 && new_displacement <= j ) { // Safe
            break;
        }
        if ( new_displacement == j + 1 ) { // Can't displace any more.
            if ( j == 0 ) { // Last element
                return NULL; // All done.
            }
            s = s + 1; // Increase number of fully-displaced elements.
        }
        reverse_displacement_direction( self, j );
        j = j - 1; // Proceed to next inner element.
    }
    current_index = j - self->_displacements[j] + s;
    adjacent_index = j - new_displacement + s;
    swap_permutation_elements( self->_permutation, current_index, adjacent_index );
    self->_displacements[j] = new_displacement;
    return self;
}

void reverse_displacement_direction(struct permutation_iterator * self, int j) {
    self->_displacement_directions[j] *= -1;
}

void print_permutation_iterator( struct permutation_iterator * self ) {
    printf( "permutation: " );
    print_permutation( self->_permutation );
    printf( "\ndisplacements: " );
    print_permutation_iterator_displacements( self );
    printf( "\ndirections   : " );
    print_permutation_iterator_directions( self );
    printf( "\n" );
}

void print_permutation_iterator_displacements( struct permutation_iterator * self ) {
    int i;

    printf( "[ " );
    for ( i = 0; i < get_permutation_length( self->_permutation ) - 1; i++ ) {
        printf( "%d, ", self->_displacements[i] );
    }
    printf( "%d ]", self->_displacements[i] );
}

void print_permutation_iterator_directions( struct permutation_iterator * self ) {
    int i;

    printf( "[ " );
    for ( i = 0; i < get_permutation_length( self->_permutation ) - 1; i++ ) {
        printf( "%d, ", self->_displacement_directions[i] );
    }
    printf( "%d ]", self->_displacement_directions[i] );
}

void destroy_permutation_iterator( struct permutation_iterator * self ) {
    destroy_permutation( self->_permutation );
    free( self->_displacements );
    free( self->_displacement_directions );
    free( self );
}
