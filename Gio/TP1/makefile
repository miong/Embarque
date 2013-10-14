
all: main test clean

main: libcolimacon.so libcolimacon.a
	gcc  main.c -o main -L . -lcolimacon

libcolimacon.so: colimacon.o
	gcc -o libcolimacon.so -shared colimacon.o

colimacon.o: colimacon.c
	gcc -Wall -c colimacon.c -o colimacon.o -fPIC 

test: libcolimacon.so
	gcc test.c -o test -L . -lcolimacon
clean:
	rm -rf *.o

mrproper: clean
	rm -rf main
	rm -rf *.so
