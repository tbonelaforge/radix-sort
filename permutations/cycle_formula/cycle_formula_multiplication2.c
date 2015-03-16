#include <stdio.h>

#include "cycle_formula.h"
#include "cycle_formula_multiplication2.h"

void print_table( int * table, int length ) {
    int i;
    for ( i = 0; i < length; i++ ) {
        printf( "%d ", table[i] );
    }
}

struct cycle_formula *  multiply_cycle_formula( struct cycle_formula * input ) {
    int z, j, temp, element;
    int max_element = get_max_element_in_cycle_formula( input );
    int table[max_element + 1];

    initialize_table( table, max_element + 1 );
    input->_position = input->_length;
    while ( input->_position-- ) {
        element = get_cycle_formula_element( input );
        if ( element == RPAREN ) {
            z = 0;
        } else if ( element == LPAREN ) {
            table[j] = z;
        } else { // Swap z into the table.
            temp = table[element];
            table[element] = z;
            z = temp;
            if ( table[element] == 0 ) {
                j = element;
            }
        }
    }
    return make_cycle_formula_from_mapping( table, max_element + 1 );
}

int get_max_element_in_cycle_formula( struct cycle_formula * input ) {
    int element;
    int max_element = 0;
    int original_position = input->_position;

    reset_cycle_formula_position( input );
    while ( input->_position < input->_length ) {
        element = get_cycle_formula_element( input );
        increment_cycle_formula_position( input );
        if ( element == LPAREN || element == RPAREN ) {
            continue;
        }
        if ( element > max_element ) {
            max_element = element;
        }
    }
    input->_position = original_position;
    return max_element;
}

void initialize_table( int * table, int length ) {
    int i;

    for ( i = 0; i < length; i++ ) {
        table[i] = i;
    }
}


struct cycle_formula * make_cycle_formula_from_mapping( int * table, int length ) {
    struct cycle_formula * result = new_cycle_formula( 2 * length );
    int tags[length];
    int i;

    initialize_tags( tags, length );
    for ( i = 0; i < length; i++ ) {
        if ( tags[i] ) { // Previously tagged.
            continue; // Skip previously tagged elements.
        }
        tags[i] = 1; // Tag this element.
        if ( table[i] == i ) { // Singleton cycle.
            continue; // Skip singleton cycles.
        }
        extract_cycle_from_mapping_to_cycle_formula( table, tags, i, result );
    }
    return result;
}

void initialize_tags( int * tags, int length ) {
    int i;

    for ( i = 0; i < length; i++ ) {
        tags[i] = 0;
    }
}

void extract_cycle_from_mapping_to_cycle_formula( int * mapping, int * tags, int i, struct cycle_formula * result ) {
    int start_element = i;

    start_cycle_in_cycle_formula( result, start_element );
    while( mapping[i] != start_element ) {
        tags[mapping[i]] = 1;
        i = mapping[i];
        append_to_cycle_formula( result, i, 0 );
    }
    stop_cycle_in_cycle_formula( result );
}
