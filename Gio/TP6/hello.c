#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char** argv){
 int i;
 printf("Mionux - V1.0 - Linux modifier\n");
 printf("Ceci est l'initialisation du system Mionux\n");
 for(i=0;i<10;i++){ 	
    printf(".");
		fflush(stdout);
		sleep(1);
 }
 printf("____-------->OK\n");
 printf("Fin de l'initialisation\nPreparer vous a connaitre l'experience Mionux\n\n\n");	

 execv("./busybox",argv);
 printf("FAIL\n");
 return 0;
}
