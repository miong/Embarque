
all: main test clean

main: libcolimacon.so 
	gcc  main.c -o main -L . -lcolimacon

libcolimacon.so: colimacon.o
	gcc -o libcolimacon.so -shared colimacon.o

colimacon.o: colimacon.c
	gcc -Wall -c colimacon.c -o colimacon.o -fPIC 

test: libcolimacon.so
	gcc test.c -o test -L . -lcolimacon

static:
	gcc -Wall -c colimacon.c -o colimacon.o
	ar -r libcolimacon.a colimacon.o
	gcc -Wall --static main.c -o main -L . -lcolimacon
	rm -rf *.o *~
clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf main
	rm -rf test	
	rm -rf *.a *.so
