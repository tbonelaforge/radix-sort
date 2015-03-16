all: bounded_queue permutation_iterator radix_sort.o radix_sort_test.bin triangular_numbers.bin codility_version.bin

radix_sort_test.bin: radix_sort_test.c radix_sort.c radix_sort.h ./bounded_queue/bounded_queue.c ./bounded_queue/bounded_queue.h ./permutations/permutation_iterator/permutation_iterator.c ./permutations/permutation_iterator/permutation_iterator.h ./permutations/permutation_iterator/permutation.c ./permutations/permutation_iterator/permutation.h
	gcc -I ./ -I ./permutations/permutation_iterator radix_sort_test.c radix_sort.o ./permutations/permutation_iterator/permutation_iterator.o ./permutations/permutation_iterator/permutation.o bounded_queue/bounded_queue.o -o radix_sort_test.bin

triangular_numbers.bin: triangular_numbers.c radix_sort.c radix_sort.h ./bounded_queue/bounded_queue.c ./bounded_queue/bounded_queue.h
	gcc -I ./ triangular_numbers.c radix_sort.o ./bounded_queue/bounded_queue.o -o triangular_numbers.bin

codility_version.bin: codility_version.c
	gcc codility_version.c -o codility_version.bin

radix_sort.o: radix_sort.c radix_sort.h
	gcc -I ./bounded_queue -c radix_sort.c -o radix_sort.o

bitwise_test.bin: bitwise_test.c
	gcc bitwise_test.c -o bitwise_test.bin

.PHONY: bounded_queue

bounded_queue:
	cd ./bounded_queue; make

.PHONY: permutations

permutation_iterator:
	cd ./permutations/permutation_iterator; make
