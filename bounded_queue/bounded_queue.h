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
