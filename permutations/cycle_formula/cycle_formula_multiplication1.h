#ifndef _CYCLE_FORMULA_MULTIPLICATION_1_H_
#define _CYCLE_FORMULA_MULTIPLICATION_1_H_

struct cycle_formula * multiply_cycle_formula( struct cycle_formula * );


int prepare_cycle_formula_for_multiplication( struct cycle_formula * );

void extract_cycle_from_cycle_formula( struct cycle_formula *, struct cycle_formula * );

int trace_cycle_formula_element( struct cycle_formula *, int );

#endif
