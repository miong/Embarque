all : main.c lib.a testPhase.c test.a
	gcc -o main main.c lib.a
	gcc -o testeur testPhase.c test.a -lm

lib.a : lib.o
	ar -q lib.a lib.o

lib.o : lib.c
	gcc -c lib.c -o lib.o  

test.o : test.c
	gcc -c test.c -o test.o

test.a : lib.o test.o
	ar -q test.a lib.o test.o
 
clean:
	rm -rf *.o *.a
	rm -rf *~


mrproper: clean
	rm -rf main
	rm -rf testeur

