/**********************************************************************/
/*                                                                    */
/*                  TP1 - TEST.C - MION GIOVANNI                      */
/*                                                                    */
/**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "libcolimacon.h"

int array_equals(int **array1,int *array2,unsigned int rows,unsigned int columns){
    
		//déclaration des variables
		int *p2;
		int p1,i,j;

		//test d'égalité des valeurs des deux tableaux
		for(i=0;i<rows;i++){
				for(j=0;j<columns;j++){
					//calcule des addresse des elements array1[i][j] et array2[i][j] et comparaison
					p1= (*array1)[i*columns + j];
					p2=(int*) (array2 + i*columns + j);
					if(!(p1==(int)*p2))
						return 0;
        }
     }
		return 1;

}

int main(int argc,char **argv){

		// Declaration des variables
		int *array1;
		int i,j;

		// Declaration des donnée de tests : valeurs attendu pour les tableau 1x1, 2x2, 2x3, 3x2, 4x4 et 5x5 
		int test11[1][1] = {
						{1}
						};    

		int test22[2][2] = {
						{1,2},
						{4,3}
						};

		int test23[2][3] = {
						{1,2,3},
						{6,5,4}
						}; 

		int test32[3][2] = {
						{1,2},
						{6,3},
						{5,4}
						};

		int test44[4][4] = {
						{1,2,3,4},
						{12,13,14,5},
						{11,16,15,6},
						{10,9,8,7}
						};

		int test55[5][5] = {
						{1,2,3,4,5},
						{16,17,18,19,6},
						{15,24,25,20,7},
						{14,23,22,21,8},
						{13,12,11,10,9}
						};

		//compilation des données de test dans un tableau a deux dimmensions de	tableaux
		int ***allTest = (int ***)malloc(5*sizeof(int**));
		for(i=0;i<5;i++){
			allTest[i]= (int**)calloc(5,sizeof(int*));
			if(allTest[i]== NULL){
				printf("probleme d'allocation pour allTest");
				return -1;
      }
		}

		allTest[0][0]= test11[0];
		allTest[1][1]= test22[0];
		allTest[1][2]= test23[0];
		allTest[2][1]= test32[0];
		allTest[3][3]= test44[0];
		allTest[4][4]= test55[0];

		// debut des tests		
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(allTest[i][j]!=NULL && colimacon(&array1,(unsigned int)i+1,(unsigned int)j+1)>=0)
					if(!(array_equals(&array1,allTest[i][j],(unsigned int)i+1,(unsigned int)j+1))){
						// si echec alors affichage du message d'erreur et exit
						printf("Echec du test pour la valeur %dx%d\n",i+1,j+1);
						return -1;
				}

		printf("Test effectue avec succes\n");
		return 0;
}
