all : permutation_iterator_test

permutation_iterator_test : permutation_iterator_test.c permutation_iterator.o permutation.o
	gcc permutation_iterator_test.c permutation_iterator.o permutation.o -o permutation_iterator_test

permutation_iterator.o : permutation_iterator.c permutation_iterator.h permutation.h
	gcc -I . -c permutation_iterator.c -o permutation_iterator.o

permutation.o : permutation.c permutation.h
	gcc -I . -c permutation.c -o permutation.o
