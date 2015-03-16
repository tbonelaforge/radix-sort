#include <stdio.h>
#include <string.h>

#include "cycle_formula.h"

void trace_test_case1();
void trace_test_case2();
void trace_test_case3();
void extract_test_case1();
void multiply_test_case1();
void multiply_test_case2();

int main() {
    printf( "============================================================\n" );
    printf( "Testing the trace function\n" );
    printf( "============================================================\n" );
    trace_test_case1();
    trace_test_case2();
    trace_test_case3();

    printf( "============================================================\n" );
    printf( "Testing the extract function\n" );
    printf( "============================================================\n" );
    extract_test_case1();

    printf( "============================================================\n" );
    printf( "Testing the multiply function\n" );
    printf( "============================================================\n" );
    multiply_test_case1();

    printf( "============================================================\n" );
    printf( "Testing the multiply function\n" );
    printf( "============================================================\n" );
    multiply_test_case2();
}

void trace_test_case1() {
    int test_elements[] = { LPAREN, 1, 3, 5, 1, LPAREN, 2, 4, 2 };
    int test_tags[]     = { 1,      0, 0, 0, 1, 1,      0, 0, 1 };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 10 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 9 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    test_cycle_formula->_position = 2; // Artificially advance
    printf( "After artificially advancing the position, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    int target = get_cycle_formula_element( test_cycle_formula );
    printf( "The value at position 2 is:\n%d\n", target );
    printf( "About to trace that value through the cycle formula.\n" );
    int trace_result = trace_cycle_formula_element( test_cycle_formula, target );
    printf( "The result of tracing that target all the way through the cycle_formula is:\n%d\n", trace_result );
    printf( "And after the trace, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
}

void trace_test_case2() {
    int test_elements[] = { LPAREN, 1, 3, 5, 1, LPAREN, 3, 4, 3 };
    int test_tags[]     = { 1,      0, 0, 0, 1, 1,      0, 0, 1 };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 10 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 9 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    test_cycle_formula->_position = 2; // Artificially advance
    printf( "After artificially advancing the position, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    int target = get_cycle_formula_element( test_cycle_formula );
    printf( "The value at position 2 is:\n%d\n", target );
    printf( "About to trace that value through the cycle formula.\n" );
    int trace_result = trace_cycle_formula_element( test_cycle_formula, target );
    printf( "The result of tracing that target all the way through the cycle_formula is:\n%d\n", trace_result );
    printf( "And after the trace, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
}

void trace_test_case3() {
    int test_elements[] = { LPAREN, 1, 3, 5, 1, LPAREN, 3, 4, 5, 3, LPAREN, 1, 4, 7, 1, LPAREN, 2, 3, 2 };
    int test_tags[]     = { 1,      0, 0, 0, 1, 1,      0, 0, 0, 1, 1,      0, 0, 0, 1, 1,      0, 0, 1 };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 20 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 19 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    test_cycle_formula->_position = 2; // Artificially advance
    printf( "After artificially advancing the position, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    int target = get_cycle_formula_element( test_cycle_formula );
    printf( "The value at position 2 is:\n%d\n", target );
    printf( "About to trace that value through the cycle formula.\n" );
    int trace_result = trace_cycle_formula_element( test_cycle_formula, target );
    printf( "The result of tracing that target all the way through the cycle_formula is:\n%d\n", trace_result );
    printf( "And after the trace, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
}

void extract_test_case1() {
    int test_elements[] = { LPAREN, 1, 3, 5, 1, LPAREN, 3, 4, 5, 3, LPAREN, 1, 4, 7, 1, LPAREN, 2, 3, 2 };
    int test_tags[]     = { 1,      0, 0, 0, 1, 1,      0, 0, 0, 1, 1,      0, 0, 0, 1, 1,      0, 0, 1 };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 20 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 19 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    test_cycle_formula->_position = 2; // Artificially advance
    printf( "After artificially advancing the position, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    struct cycle_formula * result_cycle_formula = new_cycle_formula( 14 );
    printf( "About to extract a cycle from the cycle formula.\n" );
    extract_cycle_from_cycle_formula( test_cycle_formula, result_cycle_formula );
    printf( "After extracting, the test_cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );
    printf( "And the result cycle formula looks like:\n");
    print_cycle_formula( result_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( result_cycle_formula );
}

void multiply_test_case1() {
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

void multiply_test_case2() {
    int test_elements[] = { 
        LPAREN, 0, 2, 5, 6, RPAREN, 
        LPAREN, 1, 2, 3, RPAREN, 
        LPAREN, 0, 4, 3, RPAREN, 
        LPAREN, 5, 0, 3, 4, RPAREN,
        LPAREN, 1, 6, 5, 0, 4, RPAREN
    };
    int test_tags[]     = { 
        0,      0, 0, 0, 0, 0,
        0,      0, 0, 0, 0,      
        0,      0, 0, 0, 0,      
        0,      0, 0, 0, 0, 0,
        0,      0, 0, 0, 0, 0, 0
    };

    struct cycle_formula * test_cycle_formula = new_cycle_formula( 30 );

    initialize_cycle_formula( test_cycle_formula, test_elements, test_tags, 29 );

    printf( "After initializing, the cycle formula looks like:\n" );
    print_cycle_formula( test_cycle_formula );

    printf( "About to multiply out the test cycle formula...\n" );
    struct cycle_formula * result_cycle_formula = multiply_cycle_formula( test_cycle_formula );

    printf( "The result of the multiplication looks like:\n");
    print_cycle_formula( result_cycle_formula );
    destroy_cycle_formula( test_cycle_formula );
    destroy_cycle_formula( result_cycle_formula );
}
