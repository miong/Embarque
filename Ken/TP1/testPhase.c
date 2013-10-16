#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"




int main(int argc, char *argv[]){//proramme qui va lancer la fonction test avec differents parametres mis en entree 

	int i,j;
	printf("Beginning of test phase\n\n\n");
	for(i=0;i<5;i++){// ici les parametres (10,10) (100,100) (1000,1000) (10000,10000) seront testes
		j=pow(10,i);
		test(j,j);
	}
	printf("End of test phase\n\n\n");
	return 1;
}
