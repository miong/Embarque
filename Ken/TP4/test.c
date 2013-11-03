#include <stdio.h>
#include <stdlib.h>
#include "colimacon.h"
#include <time.h>

void test(int rows, int columns){//fonction qui lance colimacon avec les entrees rows et columns en affichant a la fin si tout a bien fonctionne ou pas en indiquant les entrees prises en parametres et le
				//temps d'execution de colimacon
	double t1,t2;
	int* array=NULL;	
	t1=clock();
	
	if(colimacon(&array,rows,columns)==1){
		t2=clock();
		printf("Test succeeded rows : %d / columns : %d / time (s) : %f\n\n\n\n", rows, columns, (t2-t1)/(double)(CLOCKS_PER_SEC));
		}
	else{
		t2=clock();
		printf("Test failed rows : %d / columns : %d / time (s) : %f\n\n\n\n", rows, columns, (t2-t1)/(double)(CLOCKS_PER_SEC));
	
	}


}
