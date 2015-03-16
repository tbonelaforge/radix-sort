#ifndef _PERMUTATIONS_H_
#define _PERMUTATIONS_H_

struct cycle {
    int * elements;
    int length;
};

void apply_cycle( struct cycle *, int * );
struct cycle * new_cycle( int, ... );
#endif
