#include <stdio.h>
#include <stdlib.h>
#include "colimacon.h"
//Ce programmane permet d'appliquer colimacon sur un tableau à deux dimensions dont les nombres de lignes et colonnes sont entrés par l'utilisateur en parametre du main.
//Ensuite on affiche ce tableau si colimacon retourne 1, donc a bien rempli un tableau en spirale(cf. sujet).


int main(int argc, char *argv[]){
	if(argc<3){
                        printf("Vous n'avez pas entre de valeurs pour le nombre de lignes et de colonnes\n");
                        return 0;

        }

	int* tab=NULL;	// Creation d'un tableau vide
	int rows = 0; // Declaration et initialisation de rows representant le nombre de lignes
	int columns = 0;// Declaration et initialisation de columns representant le nombre de colonnes
	int res=0;// Declaration et initialisation de res , variable recuperant les entrees de l'utilisateur
	rows = (unsigned int)atoi(argv[1]);
	columns = (unsigned int) atoi(argv[2]);
	if(rows<1||columns<1){
		printf("Saisie invalide.\n");
		return 0;
	}
	if(colimacon(&tab,rows,columns)==1){//on execute colimacon et on controle sa valeur de retour, 1 pour une réussite, 0 pour un echec
		print2d(&tab,rows,columns);
	}
	else{
        printf("colimacon a echoue.");
	}
	return 1;
}
