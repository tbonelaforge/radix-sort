#include "cycle_formula.h"
#include "cycle_formula_multiplication1.h"

struct cycle_formula * multiply_cycle_formula( struct cycle_formula * input ) {
    int max_element = prepare_cycle_formula_for_multiplication( input );
    int max_result_length = 2 * ( max_element + 1 );
    struct cycle_formula * result = new_cycle_formula( max_result_length );

    while ( advance_cycle_formula_to_first_untagged( input ) ) {
        set_cycle_formula_tag( input, 1 ); // Tag the start of this cycle
        extract_cycle_from_cycle_formula( input, result );
        reset_cycle_formula_position( input );
    }
    return result;
}


int prepare_cycle_formula_for_multiplication( struct cycle_formula * self ) {
    int element;
    int cycle_start_element;
    int max_element = 0;
    int CYCLE_BEGIN = 0;
    int CYCLE_END = 1;
    int state = CYCLE_END;

    reset_cycle_formula_position( self );
    while ( self->_position < self->_length ) {
        element = get_cycle_formula_element( self );
        if ( element == LPAREN ) {
            set_cycle_formula_tag( self, 1 ); // Tag left parens.
            state = CYCLE_BEGIN;
        } else if ( element == RPAREN ) { // Replace right parens.
            set_cycle_formula_element( self, cycle_start_element );
            set_cycle_formula_tag( self, 1 ); // Tagged copy of start element.
        } else { // Element is a regular number.
            if ( element > max_element ) {
                max_element = element; // Compute max.
            }
            if ( state == CYCLE_BEGIN ) {
                cycle_start_element = element;
                state = CYCLE_END; 
            }
        }
        increment_cycle_formula_position( self );
    }
    reset_cycle_formula_position( self );
    return max_element;
}

void extract_cycle_from_cycle_formula( struct cycle_formula * input, struct cycle_formula * result ) {
    int start_element = get_cycle_formula_element( input );
    int current_element = next_cycle_formula_element( input );

    start_cycle_in_cycle_formula( result, start_element );
    while ( ( current_element = trace_cycle_formula_element( input, current_element ) ) != start_element ) {
        append_to_cycle_formula( result, current_element, 0 );
        reset_cycle_formula_position( input );
    }
    stop_cycle_in_cycle_formula( result );
}

int trace_cycle_formula_element( struct cycle_formula * input, int current_element ) {
    int next_element;

    while ( cycle_formula_has_next( input ) ) {
        next_element = next_cycle_formula_element( input );
        if ( next_element == current_element ) {
            set_cycle_formula_tag( input, 1 ); // Tag this element.
            current_element = next_cycle_formula_element( input );
        }
    }
    return current_element;
}
