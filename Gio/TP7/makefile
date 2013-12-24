.PHONY: clean, mrproper,

all: inversion

inversion: inversion.c
	gcc -Wall inversion.c -o inversion -pthread

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf inversion
