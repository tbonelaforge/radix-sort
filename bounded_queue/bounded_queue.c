
#include <stdlib.h>
#include <stdio.h>

#include "bounded_queue.h"

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
