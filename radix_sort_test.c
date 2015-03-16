
#include <stdio.h>
#include <stdlib.h>

//#include "bounded_queue.h"
#include "radix_sort.h"

#include "permutation_iterator.h"
#include "permutation.h"

void print_array(int A[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N -1) {
            printf(", ");
        }
    }
}

void permute_array(int * source, int * target, struct permutation * this_perm) {
    int i;

    for (i = 0; i < this_perm->_length; i++) {
        target[i] = source[this_perm->_elements[i]];
    }
}

void test_permutations(int A[], int N, int direction) {
    struct permutation_iterator * perm_it = new_permutation_iterator(N);
    struct permutation * this_perm = NULL;
    int * permuted_array = NULL;
    
    permuted_array = malloc(N * sizeof(int));
    if (!permuted_array) {
        printf("Ran out of memory!\n");
        exit(1);
    }
    do {
        this_perm = perm_it->_permutation;
        permute_array(A, permuted_array, this_perm);
        printf("About to radix sort the array:\n");
        print_array(permuted_array, N);
        printf("\nAfter radix sort, the array is:\n");
        radix_sort(permuted_array, N, direction);
        print_array(permuted_array, N);
        printf("\n");
    } while (iterate_permutation(perm_it));
    free(permuted_array);
    destroy_permutation_iterator(perm_it);
}

int main() {
    int N;
    int A[] = { 5, 1, 3, 7, 4, 6, 5 };
    
    N = 7;
    
    printf("About to test all permutations ascending\n");
    test_permutations(A, N, ASCENDING);
    printf("All done!\n");

    printf("About to test all permutations descending\n");
    test_permutations(A, N, DESCENDING);
    printf("All done!\n");
}
