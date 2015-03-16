all : cycle_formula_multiplication_test1 cycle_formula_multiplication_test2

cycle_formula_multiplication_test1 : cycle_formula_multiplication_test1.c cycle_formula_multiplication1.o cycle_formula.o
	gcc cycle_formula_multiplication_test1.c cycle_formula_multiplication1.o cycle_formula.o -o cycle_formula_multiplication_test1

cycle_formula_multiplication_test2 : cycle_formula_multiplication_test2.c cycle_formula_multiplication2.o cycle_formula.o
	gcc cycle_formula_multiplication_test2.c cycle_formula_multiplication2.o cycle_formula.o -o cycle_formula_multiplication_test2

cycle_formula_multiplication2.o : cycle_formula_multiplication2.c cycle_formula_multiplication2.h cycle_formula.h
	gcc -c cycle_formula_multiplication2.c -o cycle_formula_multiplication2.o

cycle_formula_multiplication1.o : cycle_formula_multiplication1.c cycle_formula_multiplication1.h cycle_formula.h
	gcc -c cycle_formula_multiplication1.c -o cycle_formula_multiplication1.o

cycle_formula.o : cycle_formula.c cycle_formula.h
	gcc -c cycle_formula.c -o cycle_formula.o