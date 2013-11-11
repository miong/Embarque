.PHONY: clean, mrproper,

all: main test

main: libcolimacon.so main.c
	gcc  main.c -o main -L . -lcolimacon

libcolimacon.so: libcolimacon.h
	gcc -Wall -c colimacon.c -o colimacon.o -fPIC
	gcc -o libcolimacon.so -shared colimacon.o 

test: libcolimacon.so test.c
	gcc test.c -o test -L . -lcolimacon

static: libcolimacon.a main_static test_static

libcolimacon.a: libcolimacon.h
	gcc -Wall -c colimacon.c -o colimacon.o
	ar -r libcolimacon.a colimacon.o

main_static: libcolimacon.a main.c
	gcc -Wall --static main.c -o main_static -L . -lcolimacon

test_static: libcolimacon.a test.c
	gcc -Wall --static test.c -o test_static -L . -lcolimacon

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf main main_static
	rm -rf test	test_static
	rm -rf *.a *.so

