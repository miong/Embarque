#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

// on considere qu'un palindrome peut se plier en deux et que les deux chaines obtenues sont inversement identiques
//si la taille de la chaine est impaire il y a un élément central indépendant qui n'appartient pas aux deux chaines obtenues après pliage
int palindrome(char* s){
	int i;
	int tailleC;
	int moitieTailleC;
	tailleC=strlen(s);
	moitieTailleC = tailleC/2;
	for(i=0;i<moitieTailleC;i++){
		if(s[i]!=s[tailleC-1-i]){ // on compare un élément de la tête à son homonyme de la fin 
			return 0;
		}
	}
	
	return 1;
}


