/**********************************************************************/
/*                                                                    */
/*                  TP1 - MAIN.C - MION GIOVANNI                      */
/*                                                                    */
/**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "libcolimacon.h"

void display_array(int *array,int rows,int columns){
	// declaration des variables
	int i,j;
	
	//debut du parcours et de l'affichage de array
	for(i=0;i<rows;i++){
		printf("[");
			for(j=0;j<columns;j++){
				//Calcule de l'addresse de l'éléments a la ligne i et la colonne j et affichage de l'element
				printf("%d; ",array[i*columns+j]);
     	}
			printf("]\n");
		}

}

int main(int argc,char **argv){
	if(argc<3){
			printf("Erreur: veuillez passer en argument au programme le nombre de lignes et le nombre de colonnes\n");
			return -1;
	}
  
	// definition des variables
	unsigned int rows,columns;
	int val_ret;
	int *array;

	//lecture des arguments et traitement des cas negatifs
	rows = (unsigned int)atoi(argv[1]);
	columns = (unsigned int) atoi(argv[2]);
	if(rows <=0 || columns <=0){
		printf("Les valeurs du nombre de colonnes et/ou de lignes est invalide\n");
		return -1;
	}

	//Creation du tableau par la librairie colimacon
	printf("Creation du tableau en colimacon de %d lignes et %d colonnes\n",rows,columns);
	val_ret = colimacon(&array,rows,columns);
	printf("Affichage du tableau\n\n");
	if(val_ret<0){
		//Erreur lors du traitement de colimacon
		printf("Erreur, la fonction colimacon a rencontree un probleme\n");
		return -1;       

	}else{

		// affichage des elements du tableau
		display_array(array,rows,columns);
		printf("fin\n");

		return 0;

  }

}
