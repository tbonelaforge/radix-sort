#ifndef _PERMUTATION_H_
#define _PERMUTATION_H_

struct permutation {
    int * _elements;
    int _length;
};

struct permutation * new_permutation( int );
void initialize_permutation( struct permutation * );
void destroy_permutation( struct permutation * );
void swap_permutation_elements( struct permutation *, int, int );
int get_permutation_length( struct permutation * );
int get_permutation_element( struct permutation *, int );
void print_permutation( struct permutation * );

#endif
