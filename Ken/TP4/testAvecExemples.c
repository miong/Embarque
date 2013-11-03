#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "colimacon.h"


int egalite_entre_tableaux(int** arrayTest,int* arrayExemple,int rows,int columns){
	int i;
	int taille= rows*columns;
	int* itemTest=*arrayTest;
	int* itemExemple=arrayExemple;
	for(i=0;i<taille;i++){		
		if(itemTest[i]!=itemExemple[i]){
			return 0;
		}	
	}
	return 1;
}



int main(int argc, char *argv[]){

	int tableau_1_1[1] = {1};




	int tableau_1_10[10]={	1,
				2,
				3,
				4,
				5,
				6,
				7,
				8,
				9,
				10
				};

	int tableau_10_1[10]={1,2,3,4,5,6,7,8,9,10};




	int tableau_5_7[35]={
				1, 2, 3, 4, 5, 6, 7,
				20,21,22,23,24,25,8,
				19,32,33,34,35,26,9,
				18,31,30,29,28,27,10,
				17,16,15,14,13,12,11
				};

			
	int tableau_6_4[24]={
				1,2,3,4,
				16,17,18,5,
				15,24,19,6,
				14,23,20,7,
				13,22,21,8,
				12,11,10,9
				};

	


	printf("Beginning of test phase\n");
	//test tableau[1][1]
	int* arrayTest;
	if(colimacon(&arrayTest,1,1)>=0){
		if(egalite_entre_tableaux(&arrayTest,tableau_1_1,1,1)==0){
			printf("Echec test tableau_1_1.\n");
			return 0;			
		}
	}



	//test tableau[1][10]
	if(colimacon(&arrayTest,1,10)>=0){
		if(egalite_entre_tableaux(&arrayTest,tableau_1_10,1,10)==0){
			printf("Echec test tableau_1_10.\n");
			return 0;			
		}
	}




	//test tableau[10][1]
	if(colimacon(&arrayTest,10,1)>=0){
		if(egalite_entre_tableaux(&arrayTest,tableau_10_1,10,1)==0){
			printf("Echec test tableau_10_1.\n");
			return 0;			
		}
	}



	//test tableau[5][7]
	if(colimacon(&arrayTest,5,7)>=0){
		if(egalite_entre_tableaux(&arrayTest,tableau_5_7,5,7)==0){
			printf("Echec test tableau_5_7.\n");
			return 0;			
		}
	}

	
	//test tableau[6][4]
	if(colimacon(&arrayTest,6,4)>=0){
		if(egalite_entre_tableaux(&arrayTest,tableau_6_4,6,4)==0){
			printf("Echec test tableau_6_4.\n");
			return 0;			
		}
	}

	printf("Test d'égalité vérifié sur 5 exemples\n");
	return 1;
}
