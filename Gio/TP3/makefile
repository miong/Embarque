.PHONY: clean, mrproper,

all: temps_crea_proc temps_crea_thread temps_switch_proc

temps_crea_proc: temps_crea_proc.c
	gcc -Wall temps_crea_proc.c -o temps_crea_proc -lrt

temps_crea_thread: temps_crea_thread.c
	gcc -Wall temps_crea_thread.c -o temps_crea_thread -lrt -pthread

temps_switch_proc: temps_switch_proc.c
	gcc -Wall temps_switch_proc.c -o temps_switch_proc -lrt

clean:
	rm -rf *.o *~

mrproper: clean
	rm -rf temps_crea_thread
	rm -rf temps_switch_proc
	rm -rf temps_crea_proc
