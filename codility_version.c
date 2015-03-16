
#include <stdio.h>

#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

int * radix_sort(int *, int, int);
int most_significant_binary_digit(int); // most sig index
int get_max_binary_length(int *, int); // most sig index + 1
int get_bit(int, int);

extern const int ASCENDING;
extern const int DESCENDING;

#endif // RADIX_SORT

// INCLUDE radix_sort.c
#include <stdlib.h>
#include <stdio.h>

#ifndef _BOUNDED_QUEUE_H_
#define _BOUNDED_QUEUE_H_

struct bounded_queue {
    int * elements;
    int how_many_elements;
    int head;
    int tail;
};

typedef struct bounded_queue * BQueue;

BQueue new_bounded_queue(int);
void destroy_bounded_queue(BQueue);
int enqueue(BQueue, int); // Index of new element.
int dequeue(BQueue); // Index of dequeued element.
int join_queues(BQueue, BQueue, int *, int); // # total elems
void initialize_queue(BQueue);
void print_queue(BQueue);

#endif


// End bounded_queue.h

// INCLUDE bounded_queue.c


#include <stdlib.h>
#include <stdio.h>

BQueue new_bounded_queue(int N) {
    int * elements;
    BQueue self;

    elements = malloc(N * sizeof(int));
    if (!elements) {
        return NULL;
    }
    self = malloc(sizeof(struct bounded_queue));
    if (!self) {
        free(elements);
        return NULL;
    }
    self->elements = elements;
    self->how_many_elements = N;
    self->head = 0;
    self->tail = -1;
    return self;
}

void destroy_bounded_queue(BQueue self) {
    free(self->elements);
    free(self);
}

int enqueue(BQueue self, int x) {
    int i = self->tail + 1;

    if (i < self->how_many_elements) {
        self->elements[i] = x;
        self->tail = i;
        return i;
    } else {
        return -1;
    }
}

int dequeue(BQueue self) {
    int i;

    if (self->head <= self->tail) {
        i = self->head;
        self->head += 1;
        return i;
    } else {
        return -1;
    }
}

void initialize_queue(BQueue self) {
    self->head = 0;
    self->tail = -1;
}

int join_queues(BQueue a, BQueue b, int T[], int N) {
    int i;
    int j = 0;
    
    while ((i = dequeue(a)) >= 0 && j < N) {
        T[j] = a->elements[i];
        j += 1;
    }
    while ((i = dequeue(b)) >= 0 && j < N) {
        T[j] = b->elements[i];
        j += 1;
    }
    return j;
}

void print_queue(BQueue self) {
    int i = self->head;

    while (i <= self->tail) {
        printf("%d", self->elements[i]);
        if (i < self->tail) {
            printf(", ");
        }
        i += 1;
    }
}


// END bounded_queue.c

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


// END INCLUDE radix_sort.c


void print_array(int A[], int N) {
    int i;

    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i < N -1) {
            printf(", ");
        }
    }
}

int find_first_greater_than(int target, int A[], int start, int end) {
    while (A[start] <= target && start > end) {
        start -= 1;
    }
    if (start <= end) {
        return -1;
    }
    return start;
}

int solution(int A[], int N) {
    int count = 0;
    int i;
    int j;
    int k;
    int next_k;

    radix_sort(A, N, DESCENDING);
    for (i = 0; i <= N - 3; i++) {
        k = N - 1;
        for (j = i + 1; j <= N - 2; j++) {
            next_k = find_first_greater_than(A[i] - A[j], A, k, j);
            if (next_k > -1) {
                k = next_k;
                count += k - j;
            }
        }
    }
    return count;
}

int main() {
    int N;
    int result;

    printf("About to find all the triangular numbers in:\n");
    int A[] = { 15, 13, 8, 7, 5, 5, 3, 2, 1 };
    N = 9;
    print_array(A, N);
    result = solution(A, N);
    printf("\nThe result is: \n%d\n", result);

    printf("About to find all the triangular numbers in:\n");
    int A1[] = { 1, 1, 1, 1 };
    N = 4;
    print_array(A1, N);
    result = solution(A1, N);
    printf("\nThe result is: \n%d\n", result);

    printf("About to find all the triangular numbers in:\n");
    int A2[] = { 2, 1, 2 };
    N = 3;
    print_array(A2, N);
    result = solution(A2, N);
    printf("\nThe result is: \n%d\n", result);

    printf("About to find all the triangular numbers in:\n");
    int A3[] = { 2, 1, 1 };
    N = 3;
    print_array(A3, N);
    result = solution(A3, N);
    printf("\nThe result is: \n%d\n", result);

    printf("About to find all the triangular numbers in:\n");
    int A4[] = { 2, 1 };
    N = 2;
    print_array(A4, N);
    result = solution(A4, N);
    printf("\nThe result is: \n%d\n", result);
}
