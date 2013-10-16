#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
//Ce programmane permet d'appliquer colimacon sur un tableau à deux dimensions dont les nombres de lignes et colonnes sont entrés par l'utilisateur.
//Ensuite on affiche ce tableau si colimacon retourne 1, donc a bien rempli un tableau en spirale(cf. sujet).


int main(int argc, char *argv[])
{
	int* tab=NULL;	// Creation d'un tableau vide
	int rows = 0; // Declaration et initialisation de rows representant le nombre de lignes
	int columns = 0;// Declaration et initialisation de columns representant le nombre de colonnes
	int res=0;// Declaration et initialisation de res , variable recuperant les entrees de l'utilisateur
	printf("Entrez un nombre de ligne(s) >=1 :\n");
	res=scanf("%d%*[^\n]",&rows);//on recupere le nombre de lignes, il doit commencer par un chiffre, par exemple si on a 54^^$ùf on recupere uniquement 54
	while(res<1 || rows<1){//on controle la saisie
		printf("Saisie incorrecte.\n");
		printf("Entrez un nombre de ligne(s) >=1 :\n");
		int c;
    		while ( ((c = getchar()) != '\n') && c != EOF);//on vide la saisie
		res=scanf("%d",&rows);
    		while ( ((c = getchar()) != '\n') && c != EOF);//on vide la saisie
	}
	printf("EntreZ un nombre de colonne(s) >=1 :");//on recupere le nombre de colonnes, il doit commencer par un chiffre, par exemple si on a 54^^$ùf on recupere uniquement 54
	res=scanf("%d",&columns);
	while(res<1){
		printf("Saisie incorrecte.\n");
		printf("Entrez un nombre de colonne(s) >=1 :");
		int c;
    		while ( ((c = getchar()) != '\n') && c != EOF);//on vide la saisie
		res=scanf("%d",&columns);
	}
	if(colimacon(&tab,rows,columns)==1){//on execute colimacon et on controle sa valeur de retour, 1 pour une resuusite, 0 pour un echec
		print2d(&tab,rows,columns);
	}
	else{
        printf("colimacon a echoue.");
	}

	return 1;
}
