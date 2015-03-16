#include <stdio.h>

#include "cycle_formula.h"
#include "cycle_formula_multiplication2.h"



int main() {
printf( "Testing\n" );
    int test_elements[] = { LPAREN, 1, 3, 5, RPAREN, LPAREN, 3, 4, 5, RPAREN , LPAREN, 1, 4, 7, RPAREN, LPAREN, 2, 3, RPAREN };
    int test_tags[]     = { 0,      0, 0, 0, 0, 0,      0, 0, 0, 0, 0,      0, 0, 0, 0, 0,      0, 0, 0 };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 20 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 19 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    printf( "About to multiply out the test cycle formula...\n" );
    struct cycle_formula * result_cycle_formula = multiply_cycle_formula( test_cycle_formula );

    printf( "The result of the multiplication looks like:\n");
    print_cycle_formula( result_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( result_cycle_formula );
}
