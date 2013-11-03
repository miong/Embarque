#include "colimacon.h"
#include <stdio.h>
#include <stdlib.h>
//Ce fichier contient les fonctions colimacon et print2d

int colimacon (int **array, unsigned int rows, unsigned int columns){


    int i=0;//nombre de ligne(s) du haut deja remplie(s)
    int j=0;// nombre de colonne(s) de gauche deja remplie(s)
    int l=0;//la variable l va nous servir de compteur pour nos boucles for
    int k=1;//Declaration et initialisation de la variable k qui va nous permettre de remplir le tableau
    int limite= rows*columns;//DEclaration et initialisation de la variable limit definissant la taille maximale de allouee pour tmp
    int* tmp;//Declaration du tableau à remplir
    if(rows<1 || columns <1){//On verifie si les entrees sont >=1
        return 0;//Si oui le tableau n'est pas rempli en spirale et colimacon renvoie 0
    }

     
	
    tmp=(int*)malloc(limite*sizeof(int));//Initialisation et allocation de la mémoire pour le tableau de taille limite
    if(tmp==NULL){
		return 0;	
	}
    while(k<=limite){// On remplit le tableau avec k, il doit donc etre plus petit que limite

	 	for(l=j; l<=(columns-1-j) && k<=limite;l++){ //Remplissage horizontal de la gauche vers la droite de la ligne i
			tmp[i*columns+l]=k++;			
     	   }		
        i++;//nombre de ligne(s) du haut deja remplie(s)

        
            for(l=i;l<=rows-1-j && k<=limite;l++){ //Remplissage vertical du haut vers le bas de la colonne columns-1-j
                tmp[l*columns+columns-1-j]=k++;                
            }
        
      
            for(l=columns-1-i;l>=j && k<=limite;l--){//Remplissage horizontal de la droite vers la gauche de la ligne rows-1-j
                tmp[(rows-1-j)*columns+l]=k++;                
            }
       
       
            for(l=rows-1-i;l>=i && k<=limite;l--){//Remplissage vertical du bas vers le haut de la colonne j
                tmp[l*columns+j]=k++;                
            }
       	
        j++;// nombre de colonne(s) de gauche deja remplie(s)


    }



    *array=tmp;//On affecte a la valeur pointee par array la valeur de tmp, autrement dit l'adresse de ce vers quoi tmp pointe
  
    return 1;//On renvoie 1 si toutes les operations ont ete effectuees


}


void print2d(int** tab,unsigned int rows, unsigned int columns){//Fonction qui imprime rows*columns entiers a partir de l'adresse pointe par tab

    int* tableau= *tab;

    int i, j;
    for(i=0;i<rows;i++){//parcours des lignes
        for(j=0;j<columns;j++){//parcours des colonnes
            printf("[%d]\t",*(tableau+(i*columns)+j));//impression de la ligne i
        }
        printf("\n");
    }

}
