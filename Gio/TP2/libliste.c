/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBLISTE.C - MION GIOVANNI                  */
/*                                                                    */
/**********************************************************************/

#include "libliste.h"
#include <stdlib.h>

// Initialisation d'une téte de liste
void INIT_LIST_HEAD (struct list_head *head){
	head->suivant=head;
	head->precedent=head;
}

// Ajout d'un element node a une liste dont la téte est head
void list_add (struct list_head *node, struct list_head *head){
	head->precedent->suivant=node;
	node->precedent=head->precedent;
	node->suivant=head;
	head->precedent=node;	
}

// suppresion de l'element node de la liste a laquelle il appartient
void list_del (struct list_head *node){
	node->precedent->suivant=node->suivant;
	node->suivant->precedent=node->precedent;
	node->suivant= (struct list_head *)NULL;
	node->precedent= (struct list_head *)NULL;
}
