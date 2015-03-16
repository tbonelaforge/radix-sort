all : test

test : permutations_test.c permutations.h permutations.o
	gcc permutations_test.c permutations.o -o permutations_test

permutations.o : permutations.c permutations.h
	gcc -c permutations.c -o permutations.o