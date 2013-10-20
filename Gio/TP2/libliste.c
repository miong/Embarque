/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBLISTE.C - MION GIOVANNI                  */
/*                                                                    */
/**********************************************************************/

#include "libliste.h"
#include <stdlib.h>

void INIT_LIST_HEAD (struct list_head *head){

	(*head).suivant=head;
	(*head).precedent=head;

}

void list_add (struct list_head *node, struct list_head *head){
	head->precedent->suivant=node;
	node->precedent=head->precedent;
	node->suivant=head;
	head->precedent=node;	
}

void list_del (struct list_head *node){
	node->precedent->suivant=node->suivant;
	node->suivant->precedent=node->precedent;
	node->suivant= (struct list_head *)NULL;
	node->precedent= (struct list_head *)NULL;
}
