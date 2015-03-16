all: bounded_queue.o bounded_queue_test.bin

bounded_queue.o: bounded_queue.c bounded_queue.h
	gcc -c bounded_queue.c -o bounded_queue.o

bounded_queue_test.bin: bounded_queue_test.c bounded_queue.h bounded_queue.c
	gcc -I ./ bounded_queue_test.c bounded_queue.o -o bounded_queue_test.bin
