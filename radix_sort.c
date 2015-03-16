
#include <stdlib.h>
#include <stdio.h>

#include "radix_sort.h"
#include "bounded_queue.h"

const int ASCENDING = 1;
const int DESCENDING = 0;

int * radix_sort(int A[], int N, int direction) {
    BQueue zero_queue = new_bounded_queue(N);
    BQueue one_queue = new_bounded_queue(N);
    int max_length = get_max_binary_length(A, N);
    int i;
    int j;
    int x;
    int d;

    for (i = 0; i < max_length; i++) {
        initialize_queue(zero_queue);
        initialize_queue(one_queue);
        for (j = 0; j < N; j++) {
            x = A[j];
            d = get_bit(x, i);
            if (d == 1) {
                if (enqueue(one_queue, x) < 0) { // Passed bound
                    return NULL;
                }
            } else { // d == 0
                if (enqueue(zero_queue, x) < 0) { // Passed bound
                    return NULL;
                }
            }
        }
        if (direction == ASCENDING) {
            join_queues(zero_queue, one_queue, A, N);
        } else {
            join_queues(one_queue, zero_queue, A, N);
        }

    }
    destroy_bounded_queue(zero_queue);
    destroy_bounded_queue(one_queue);
    return A;
}

int get_bit(int p, int i) {
    int mask = 1 << i;

    return ( (p & mask) > 0 ) > 0 ? 1 : 0;
}

int get_max_binary_length(int A[], int N) {
    int i;
    int max_binary_length = 0;
    int length;

    for (i = 0; i < N; i++) {
        length = most_significant_binary_digit(A[i]) + 1;
        if (length > max_binary_length) {
            max_binary_length = length;
        }
    }
    return max_binary_length;
}

int most_significant_binary_digit(int p) {
    int result = -1;

    while (p > 0) {
        result += 1;
        p = p >> 1;
    }
    return result;
}
