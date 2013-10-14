/**********************************************************************/
/*                                                                    */
/*                  TP1 - COLIMACON - MION GIOVANNI                   */
/*                                                                    */
/**********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "libcolimacon.h"

int array_equals(int **array1,int *array2,unsigned int rows,unsigned int columns){
    
    //déclaration des variables
    int *p1,*p2;
    int i,j;
    
    //test d'égalité des valeurs des deux tableaux
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
		  p1=(int*) (*(*(array1)+i)+j*sizeof(int));
		  p2=(int*) (array2 + i*columns + j);
		  if(!((int)*p1==(int)*p2))
              return 0;
        }
      }
    return 1;
    
}

int main(int argc,char **argv){
    // Declaration des variables
    int *array1;
    int val_ret;
    
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
            
    // debut des tests
    if(colimacon(&array1,(unsigned int)1,(unsigned int)1)>=0)
       if(!(array_equals(&array1,test11[0],(unsigned int)1,(unsigned int)1))){
            printf("Echec du test pour la valeur 1x1\n");
            return -1;
       }                     

    if(colimacon(&array1,(unsigned int)2,(unsigned int)2)>=0)
       if(!(array_equals(&array1,test22[0],(unsigned int)2,(unsigned int)2))){
            printf("Echec du test pour la valeur 2x2\n");
            return -1;
       }                     

    if(colimacon(&array1,(unsigned int)2,(unsigned int)3)>=0)
       if(!(array_equals(&array1,test23[0],(unsigned int)2,(unsigned int)3))){
            printf("Echec du test pour la valeur 2x3\n");
            return -1;
       }                                

    if(colimacon(&array1,(unsigned int)3,(unsigned int)2)>=0)
       if(!(array_equals(&array1,test32[0],(unsigned int)3,(unsigned int)2))){
            printf("Echec du test pour la valeur 3x2\n");
            return -1;
       }                     

    if(colimacon(&array1,(unsigned int)4,(unsigned int)4)>=0)
       if(!(array_equals(&array1,test44[0],(unsigned int)4,(unsigned int)4))){
            printf("Echec du test pour la valeur 4x4\n");
            return -1;
       }                     

    if(colimacon(&array1,(unsigned int)5,(unsigned int)5)>=0)
       if(!(array_equals(&array1,test55[0],(unsigned int)5,(unsigned int)5))){
            printf("Echec du test pour la valeur 5x5");
            return -1;
       }                     
    
    printf("Test effectue avec succes\n");
}
