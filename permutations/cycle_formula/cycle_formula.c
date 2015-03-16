#include <stdlib.h>
#include <stdio.h>

#include "cycle_formula.h"


struct cycle_formula * new_cycle_formula( int max_length ) {
printf( "INside new cycle_formula\n" );
    struct cycle_formula * new_cycle_formula = malloc( sizeof( struct cycle_formula ) );
    if ( !new_cycle_formula ) {
        return NULL;
    }
    new_cycle_formula->_elements = malloc( max_length * sizeof( int ) );
    if ( !new_cycle_formula->_elements ) {
        return NULL;
    }
    new_cycle_formula->_tags = malloc( max_length * sizeof( int ) );
    if ( !new_cycle_formula->_tags ) {
        return NULL;
    }
    new_cycle_formula->_length = 0;
    new_cycle_formula->_max_length = max_length;
    new_cycle_formula->_position = -1; // Start with empty formula.
    return new_cycle_formula;
}

void destroy_cycle_formula( struct cycle_formula * self ) {
    free( self->_elements );
    free( self->_tags );
    free( self );
}



int cycle_formula_has_next( struct cycle_formula * input ) {
    if ( input->_position < input->_length - 1 ) {
        return 1;
    }
    return 0;
}

int next_cycle_formula_element( struct cycle_formula * input ) {
    increment_cycle_formula_position( input );
    return input->_elements[input->_position];
}

void append_to_cycle_formula( struct cycle_formula * self, int element, int tag ) {
    if ( self->_position >= self->_max_length ) {
        printf( "Can't append to cycle_formula:\n" );
        print_cycle_formula( self );
        exit( 1 );
    }
    increment_cycle_formula_position( self );
    set_cycle_formula_element( self, element );
    set_cycle_formula_tag( self, tag );
    self->_length++;
}

void increment_cycle_formula_position( struct cycle_formula * self ) {
    self->_position++;
}

int get_cycle_formula_element( struct cycle_formula * self ) {
    return self->_elements[self->_position];
}

int get_cycle_formula_tag( struct cycle_formula * self ) {
    return self->_tags[self->_position];
}

void set_cycle_formula_tag( struct cycle_formula * self, int tag ) {
    self->_tags[self->_position] = tag;
}

void set_cycle_formula_element( struct cycle_formula * self, int element ) {
    self->_elements[self->_position] = element;
}

void initialize_cycle_formula( struct cycle_formula * self, int * elements, int * tags, int length ) {
    int i = 0;

    while ( self->_length < self->_max_length && i < length ) {
        append_to_cycle_formula( self, elements[i], tags[i] );
        i++;
    }
}

void reset_cycle_formula_position( struct cycle_formula * self ) {
    self->_position = 0;
}

void print_cycle_formula( struct cycle_formula * self ) {
    print_cycle_formula_elements( self );
    printf( "\n" );
    print_cycle_formula_tags( self );
    printf( "\n" );
    show_cycle_formula_position( self );
    printf( "\n" );
}

void print_cycle_formula_elements( struct cycle_formula * self ) {
    process_cycle_formula( self, &print_cycle_formula_element );
}

void print_cycle_formula_tags( struct cycle_formula * self ) {
    process_cycle_formula( self, &print_cycle_formula_tag );
}

void print_cycle_formula_element( struct cycle_formula * self ) {
    int element = self->_elements[self->_position];

    if ( element == LPAREN ) {
        printf( "%" PRINT_PADDING "s", "(" );
        return;
    }
    if ( element == RPAREN ) {
        printf( "%" PRINT_PADDING "s", ")" );
        return;
    }
    printf( "%" PRINT_PADDING "d", element );
    
}

void print_cycle_formula_tag( struct cycle_formula * self ) {
    int tag = self->_tags[self->_position];
    if ( tag == 1 ) {
        printf( "%" PRINT_PADDING "s", "t" );
        return;
    }
    printf( "%" PRINT_PADDING "s", " " );
}

void process_cycle_formula( struct cycle_formula * self, ptr2cycle_formula_processor processor ) {
    int original_position = self->_position;
    reset_cycle_formula_position( self );
    while ( self->_position < self->_length ) {
        (*processor)( self );
        increment_cycle_formula_position( self );
    }
    self->_position = original_position;
}

int POSITION_TO_SHOW = -1;

void show_cycle_formula_position( struct cycle_formula * self ) {
    POSITION_TO_SHOW = self->_position;
    process_cycle_formula( self, &mark_cycle_formula_position );
}

void mark_cycle_formula_position( struct cycle_formula * self ) {
    if ( self->_position == POSITION_TO_SHOW ) {
        printf( "%" PRINT_PADDING "s", "^" );
        return;
    }
    printf( "%" PRINT_PADDING "s", " " );
}



void start_cycle_in_cycle_formula( struct cycle_formula * self, int start_element ) {
    append_to_cycle_formula( self, LPAREN, 0 );
    append_to_cycle_formula( self, start_element, 0 );
}

void stop_cycle_in_cycle_formula( struct cycle_formula * self ) {
    append_to_cycle_formula( self, RPAREN, 0 );
}

struct cycle_formula * advance_cycle_formula_to_first_untagged( struct cycle_formula * self ) {
    while ( self->_position < self->_length ) {
        if ( !get_cycle_formula_tag( self ) ) { // Untagged element.
            return self;
        }
        increment_cycle_formula_position( self );
    }
    return NULL;
}






