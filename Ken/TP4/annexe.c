#include <stdio.h>
#include <stdlib.h>
#include "annexe.h"

int facteur_boucle(struct maillon* a, struct maillon* b){//fonction permettant de détecter si on va entrer dans une boucle, retourne -1 si oui et 1 si non
	struct maillon* iter1=a;
	struct maillon* iter2=b;
	if(iter1==NULL){
		return 1;
	}
	while((*iter1).precedent!=NULL){
		iter1=(*iter1).precedent;
		iter2=(*iter2).precedent;
		if((*iter1).valeur==(*a).valeur && (*iter2).valeur==(*b).valeur){// on regarde si on a déjà eu les valeurs de a et b sur les valeurs déjà parcourues
			return -1;
		}
	}
	return 1;
}

int print_from_maillon(struct maillon* a){//permet d'afficher les valeurs des éléments parcourus depuis un maillon en itérant sur son précédent.
	struct maillon* iter=a;
	printf("(");
	if(iter==NULL){
		return 0;
	}
	while(iter!=NULL){
		printf("%d ",(*iter).valeur);
		iter=(*iter).precedent;
	}
	printf(")\n");
	return 1;
}


int check_moves_in_array(int* array, unsigned int size){
	int indice=0;// int permettant de parcourir le tableau 
	int premierContenu=0;// int récupérant la valeur contenue dans une cellule
	int deuxiemeContenu=0;// int récupérant la valeur contenue dans une cellule
	int troisiemeContenu=0;// int récupérant la valeur contenue dans une cellule
	struct maillon** d;//permettant de recupérer l'adresse d'un pointeur de maillon
	d=malloc(1*sizeof(struct maillon**));
	if(d==NULL){
		printf("prévention de segmentation fault");
		return -2;	
	}
	struct maillon** to_print;//permettant de recupérer l'adresse d'un pointeur de maillon à partir duquel on va faire un print_from_maillon
	to_print=malloc(1*sizeof(struct maillon**));
	if(to_print==NULL){
		printf("prévention de segmentation fault");
		return 0;	
	}	
	while(indice<size && indice >=0){
	
					
		struct maillon* a;		
		a=malloc(1*sizeof(struct maillon));
		if(a==NULL){
			printf("prévention de segmentation fault");
			return -2;	
		}
		premierContenu=array[indice];
		(*a).valeur=premierContenu;
		(*a).precedent=*d;
		to_print=&a;//mise en mémoire du dernier élément parcouru pour un éventuel print_from_maillon
		if(facteur_boucle(*d,a)==-1){//détection de boucle
			print_from_maillon(*to_print);
			return -1;
		}

		indice=troisiemeContenu+premierContenu;
		if(indice>=size || indice<0){//détection segmentation fault
			print_from_maillon(*to_print);
			return deuxiemeContenu+troisiemeContenu;
		}
		
		
		struct maillon* b;
		b=malloc(1*sizeof(struct maillon));
		if(b==NULL){
			printf("prévention de segmentation fault");
			return -2;	
		}
		deuxiemeContenu=array[indice];
		(*b).valeur=deuxiemeContenu;
		(*b).precedent=a;
		to_print=&b;//mise en mémoire du dernier élément parcouru pour un éventuel print_from_maillon
		if(facteur_boucle(a,b)==-1){//détection de boucle
			print_from_maillon(*to_print);
			return -1;
		}

		indice=premierContenu+deuxiemeContenu;
		if(indice>=size || indice<0){//détection segmentation fault
			print_from_maillon(*to_print);
			return troisiemeContenu+premierContenu;
		}

		struct maillon* c;
		c=malloc(1*sizeof(struct maillon));
		if(c==NULL){
			printf("prévention de segmentation fault");
			return -2;	
		}
		troisiemeContenu=array[premierContenu+deuxiemeContenu];			
		(*c).valeur=troisiemeContenu;
		(*c).precedent=b;
		to_print=&c;//mise en mémoire du dernier élément parcouru pour un éventuel print_from_maillon
		if(facteur_boucle(b,c)==-1){//détection de boucle
			print_from_maillon(*to_print);
			return -1;
		}

		indice=deuxiemeContenu+troisiemeContenu;
		if(indice>=size || indice<0){//détection segmentation fault
			print_from_maillon(*to_print);	
			return premierContenu+deuxiemeContenu;
		}
		d=&c;//mise en mémoire de l'adresse de c pour l'utiliser au prochain passage dans la boucle while

	}
	
	return 0;	

}

