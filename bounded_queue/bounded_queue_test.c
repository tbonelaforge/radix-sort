
#include <stdio.h>

#include "bounded_queue.h"

int main() {
    int N = 3;
    BQueue test = new_bounded_queue(N);
    int v;

    printf("About to enqueue 1:\n");
    v = enqueue(test, 1);
    if (v >= 0) {
        printf("The newly-enqueued element is: %d\n", test->elements[v]);
    } else {
        printf("Could not enqueue anymore!1!\n");
    }

    printf("About to enqueue 2:\n");
    v = enqueue(test, 2);
    if (v >= 0) {
        printf("The newly-enqueued element is: %d\n", test->elements[v]);
    } else {
        printf("Could not enqueue anymore!1!\n");
    }

    printf("About to enqueue 3:\n");
    v = enqueue(test, 3);
    if (v >= 0) {
        printf("The newly-enqueued element is: %d\n", test->elements[v]);
    } else {
        printf("Could not enqueue anymore!1!\n");
    }

    printf("About to enqueue 4:\n");
    v = enqueue(test, 4);
    if (v >= 0) {
        printf("The newly-enqueued element is: %d\n", test->elements[v]);
    } else {
        printf("Could not enqueue anymore!1!\n");
    }

    printf("About to dequeue\n");
    v = dequeue(test);
    if (v >= 0) {
        printf("Just dequeued element: %d\n", test->elements[v]);
    } else {
        printf("Could not dequeue anymore!!!!\n");
    }

    printf("About to dequeue\n");
    v = dequeue(test);
    if (v >= 0) {
        printf("Just dequeued element: %d\n", test->elements[v]);
    } else {
        printf("Could not dequeue anymore!!!!\n");
    }

    printf("About to dequeue\n");
    v = dequeue(test);
    if (v >= 0) {
        printf("Just dequeued element: %d\n", test->elements[v]);
    } else {
        printf("Could not dequeue anymore!!!!\n");
    }

    printf("About to dequeue\n");
    v = dequeue(test);
    if (v >= 0) {
        printf("Just dequeued element: %d\n", test->elements[v]);
    } else {
        printf("Could not dequeue anymore!!!!\n");
    }


}
