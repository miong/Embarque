/**********************************************************************/
/*                                                                    */
/*                  TP2 - TESTLISTE.C - MION GIOVANNI                 */
/*                                                                    */
/**********************************************************************/

#include "libliste.h"
#include <stdlib.h>
#include <stdio.h>

// Structure d'un element d'un liste d'entier
struct mynode{
	int element;
	struct list_head l;
	
};

int main(int argc,char **argv){
	
	//creation et initialisation d'une liste lh pour une liste d'entier
	struct list_head lh;
	INIT_LIST_HEAD(&lh);

	// Creation de l'element 1 de la liste et ajout a la liste
	struct mynode un;
	un.element = 1;
	list_add(&(un.l),&lh);

	// Creation de l'element 2 de la liste et ajout a la liste
	struct mynode deux;
	deux.element = 2;
	list_add(&(deux.l),&lh);

	// Creation de l'element 3 de la liste et ajout a la liste
	struct mynode trois;
	trois.element = 3;
	list_add(&(trois.l),&lh);

	// parcours de lh avec un pointeur j et affichage de chaque elements
	struct mynode *j;
	printf("[");
	list_for_each_entry(j,&lh,l){
			printf(" %d ",j->element);
	}
	printf("]\n");
	
	// suppession de l'element deux
	list_del(&(deux.l));

	// parcours de lh avec un pointeur j et affichage de chaque elements
	printf("[");
	list_for_each_entry(j,&lh,l){
			printf(" %d ",j->element);
	}
	printf("]\n");

	return 0;
}
