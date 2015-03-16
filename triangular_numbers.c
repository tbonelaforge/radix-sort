
#include <stdio.h>

#include "radix_sort.h"

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
