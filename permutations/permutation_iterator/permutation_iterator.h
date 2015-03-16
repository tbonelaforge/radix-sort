#ifndef _PERMUTATION_ITERATOR_H_
#define _PERMUTATION_ITERATOR_H_

#include "permutation.h"

struct permutation_iterator {
    struct permutation * _permutation;
    int * _displacements;
    int * _displacement_directions;
};

struct permutation_iterator * new_permutation_iterator( int );
void initialize_permutation_iterator( struct permutation_iterator * );
void destroy_permutation_iterator( struct permutation_iterator * );
struct permutation_iterator * iterate_permutation( struct permutation_iterator * );
void print_permutation_iterator( struct permutation_iterator * );
void print_permutation_iterator_displacements( struct permutation_iterator * );
void print_permutation_iterator_directions( struct permutation_iterator * );
void reverse_displacement_direction(struct permutation_iterator *, int);

#endif
