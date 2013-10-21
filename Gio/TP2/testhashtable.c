/**********************************************************************/
/*                                                                    */
/*                  TP2 - TESTHASHTABLE.C - MION GIOVANNI                 */
/*                                                                    */
/**********************************************************************/

#include "libhashtable.h"
#include <stdlib.h>
#include <stdio.h>

// definition de la structure d'un element entier dans une hash_table
struct myhashentry{
	int element;
	struct hash_table_entry hte;
};

int main(int argc,char **argv){
	
	//creation et initialisation d'une hash_table ht
	struct hash_table ht;
	INIT_HASH_TABLE(&ht);

	// creation d'un element 1 d'id 4096 et ajout de cette element a ht
	struct myhashentry e1;
	e1.element = 1;
	e1.hte.entry_id = 4096;
	hash_table_add(&(e1.hte),&ht);

	// creation d'un element 2 d'id 8192 et ajout de cette element a ht
	struct myhashentry e2;
	e2.element = 2;
	e2.hte.entry_id = 8192;
	hash_table_add(&(e2.hte),&ht);

	// affichage des indices des listes dans une hash_table pour les 20 premiers multiple de 4096
	// une bonne fonction de hachage renvoi des valeurs differentes
	int id;
	for(id=0;id<20;id++)
		printf("hash=%d\n",hash_entry_id(4096*id));
	
	//recuperation de l'element d'id 4096 dans la hash_table ht. Il doit etre trouver
	// le pointeur e pointe sur l'element s'il est trouver ou est egale a null sinon
	struct myhashentry *e;
	hash_table_get_by_id(e,ht,4096,hte);
	if(e != NULL)
		printf("id trouver ! valeur de l'element : %d\n",e->element);
	else
		printf("id non trouver");

	// suppression de l'element 1 d'id 4096 de la hash_table ht	
	hash_table_del(&(e1.hte));

	//recuperation de l'element d'id 4096 dans la hash_table ht. Il ne doit pas etre trouver
	// le pointeur e pointe sur l'element s'il est trouver ou est egale a null sinon
	hash_table_get_by_id(e,ht,4096,hte);
	if(e != NULL)
		printf("id trouver ! valeur de l'element : %d\n",e->element);
	else
		printf("id non trouver\n\n");	

	return 0;

}
