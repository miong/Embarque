/**********************************************************************/
/*                                                                    */
/*                  TP1 - COLIMACON - MION GIOVANNI                   */
/*                                                                    */
/**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "libcolimacon.h"

int main(int argc,char **argv){
  if(argc<3){

    printf("Erreur: veuillez passer en argument au programme le nombre de lignes et le nombre de colonnes\n");
    return -1;

  }else{
    
    // definition des variables
    unsigned int rows,columns;
    int val_ret,i,j;
    int *array;
	int *p;

    rows = (unsigned int)atoi(argv[1]);
    columns = (unsigned int) atoi(argv[2]);
    if(rows <=0 || columns <=0){
      printf("Les valeurs du nombre de colonnes et/ou de lignes est invalide\n");
      return -1;
    }
    
    printf("Creation du tableau en colimacon de %d ligne et %d colonnes\n",rows,columns);
    val_ret = colimacon(&array,rows,columns);
    printf("Affichage du tableau\n\n");
    if(val_ret<0){

      printf("Erreur, la fonction colimacon a rencontrer un probleme\n");
      return -1;       

    }else{
      for(i=0;i<rows;i++){
        printf("[");
        for(j=0;j<columns;j++){
		  p=(int*) (*(*(&array)+i)+j*sizeof(int));
          printf("%d; ",*p);
        }
        printf("]\n");
      }
      printf("fin\n");
	
    }

    return 0;

  }


}
