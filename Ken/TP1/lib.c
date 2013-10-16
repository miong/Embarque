#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
//Ce fichier contient les fonctions colimacon et print2d

int colimacon (int **array, unsigned int rows, unsigned int columns){


    int i=0;
    int j=0;
    int l=0;//Declaration et initialisation des variables i,j et l qui vont nous permettre de parcourir le tableau
    int k=1;//Declaration et initialisation de la variable k qui va nous permettre de remplir le tableau
    int* tmp;//Declaration du tableau à remplir
    if(rows<1 || columns <1){//On verifie si les entrees sont >=1
        return 0;//Si oui le tableau n'est pas rempli en spirale et colimacon renvoie 0
    }

     

    tmp=(int*)calloc(rows*columns,sizeof(int));//Initialisation et allocation de la mémoire pour le tableau de taille rows*columns
    
    while(k<=rows*columns){// On remplit le tableau avec k, il doit donc etre plus petit que rows*columns

        for(l=j; l<=(columns-1-j);l++){//Remplissage horizontal de la gauche vers la droite de la ligne i
            *(tmp+i*columns+l)=k;
            k++;
        }
        i++;//on change de ligne
        if(k<=rows*columns){//Remplissage vertical du haut vers le bas de la colonne columns-1-j
            for(l=i;l<=rows-1-j;l++){

                *(tmp+l*columns+columns-1-j)=k;
                k++;
            }
        }
        if(k<=rows*columns){//Remplissage horizontal de la droite vers la gauche de la ligne rows-1-j
            for(l=columns-1-i;l>=j;l--){
   
                *(tmp+(rows-1-j)*columns+l)=k;
                k++;
            }
        }
        if(k<=rows*columns){//Remplissage vertical du bas vers le haut de la colonne j
            for(l=rows-1-i;l>=i;l--){

                *(tmp+l*columns+j)=k;
                k++;
            }
        }
        j++;// on change de colonne


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
