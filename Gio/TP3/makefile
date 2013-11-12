.PHONY: clean, mrproper,

all: temps_crea_proc temps_crea_thread

temps_crea_proc: temps_crea_proc.c
	gcc -Wall temps_crea_proc.c -o temps_crea_proc -lrt

temps_crea_thread: temps_crea_thread.c
	gcc -Wall temps_crea_thread.c -o temps_crea_thread -lrt -pthread
clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf temps_crea_thread
	rm -rf temps_crea_proc
