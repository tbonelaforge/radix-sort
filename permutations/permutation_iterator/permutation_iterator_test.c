#include <stdio.h>
#include <stdlib.h>

#include "permutation_iterator.h"
#include "permutation.h"

int main() {
    printf( "Testing the construction of a new permutation_iterator...\n" );
    struct permutation_iterator * test_permutation_iterator = new_permutation_iterator( 4 );
int stop_count = 0;
    do {
        print_permutation_iterator(test_permutation_iterator);
        printf("\n");
    } while((++stop_count < 200) && iterate_permutation(test_permutation_iterator));
printf("Done!\n");
}
