#ifndef _CYCLE_FORMULA_MULTIPLICATION_H_
#define _CYCLE_FORMULA_MULTIPLICATION_H_

#include "cycle_formula.h"

struct cycle_formula * multiply_cycle_formula( struct cycle_formula * );
int get_max_element_in_cycle_formula( struct cycle_formula * );
void initialize_table( int *, int );
struct cycle_formula * make_cycle_formula_from_mapping( int *, int );
void initialize_tags( int *, int );
void extract_cycle_from_mapping_to_cycle_formula( int *, int *, int, struct cycle_formula * );

#endif
