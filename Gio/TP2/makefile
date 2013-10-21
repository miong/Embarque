all: testliste testhashtable clean

testliste: libTP2.so libliste.h  libhashtable.h
	gcc -Wall testliste.c -o testliste -L . -lTP2

testhashtable: libTP2.so libliste.h  libhashtable.h
	gcc -Wall testhashtable.c -o testhashtable -L . -lTP2

libTP2.so: libliste.o libhashtable.o
	gcc -o libTP2.so -shared libliste.o libhashtable.o

libhashtable.o: libhashtable.c
	gcc -fPIC -c libhashtable.c -o libhashtable.o

libliste.o: libliste.c
	gcc -fPIC -c libliste.c -o libliste.o

static: libliste.h libliste.c testliste.c libhashtable.h libhashtable.c
	gcc -c libliste.c -o libliste.o
	gcc -c libhashtable.c -o libhashtable.o
	ar -r libTP2.a libliste.o libhashtable.o
	gcc -Wall --static testliste.c -o testliste -L . -lTP2
	gcc -Wall --static testhashtable.c -o testhashtable -L . -lTP2
	rm -rf *.o *~

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf testliste testhashtable libTP2.so libTP2.a

