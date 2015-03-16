#ifndef _CYCLE_FORMULA_H_
#define _CYCLE_FORMULA_H_

#define LPAREN -1
#define RPAREN -2
#define PRINT_PADDING "4"

struct cycle_formula {
    int * _elements;
    int * _tags;
    int _length;
    int _max_length;
    int _position;
};

typedef void (*ptr2cycle_formula_processor)( struct cycle_formula * ); 

struct cycle_formula * new_cycle_formula( int );
void destroy_cycle_formula( struct cycle_formula * );
struct cycle_formula * multiply_cycle_formula( struct cycle_formula * );
int trace_cycle_formula_element( struct cycle_formula *, int );
void extract_cycle_from_cycle_formula( struct cycle_formula *, struct cycle_formula * );
int cycle_formula_has_next( struct cycle_formula * );
int next_cycle_formula_element( struct cycle_formula * );
void append_to_cycle_formula( struct cycle_formula *, int, int );
void increment_cycle_formula_position( struct cycle_formula * );
int get_cycle_formula_element( struct cycle_formula * );
int get_cycle_formula_tag( struct cycle_formula * );
void set_cycle_formula_tag( struct cycle_formula *, int );
void set_cycle_formula_element( struct cycle_formula *, int );
void initialize_cycle_formula( struct cycle_formula *, int *, int *, int );
void reset_cycle_formula_position( struct cycle_formula * );
void print_cycle_formula( struct cycle_formula * );
void print_cycle_formula_elements( struct cycle_formula * );
void print_cycle_formula_tags( struct cycle_formula * );
void show_cycle_formula_position( struct cycle_formula * );
void mark_cycle_formula_position( struct cycle_formula * );
void print_cycle_formula_element( struct cycle_formula * );
void print_cycle_formula_tag( struct cycle_formula * );
void process_cycle_formula( struct cycle_formula *, ptr2cycle_formula_processor );
void start_cycle_in_cycle_formula( struct cycle_formula *, int );
void stop_cycle_in_cycle_formula( struct cycle_formula * );
int prepare_cycle_formula_for_multiplication( struct cycle_formula * );
struct cycle_formula * advance_cycle_formula_to_first_untagged( struct cycle_formula * );

#endif
