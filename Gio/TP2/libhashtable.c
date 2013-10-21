/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBHASHTABLE.C - MION GIOVANNI              */
/*                                                                    */
/**********************************************************************/

#include "libhashtable.h"
#include <stdlib.h>
#include <stdio.h>

// initialisation d'une hash_table
void INIT_HASH_TABLE(struct hash_table *ht){

	int i;
	for(i=0;i<nbListe;i++){
		INIT_LIST_HEAD(&(ht->table[i].liste));
	}
}

// calcule de l'indice de la liste en fonction de l'id d'un hash_table_entry
int hash_entry(struct hash_table_entry *hte){
	return hash_entry_id(hte->entry_id);
}

// calcule de l'indice de la liste en fonction d'un id 
int hash_entry_id(int id){
	return (256*id)%nbListe;
}

//ajout a la hash_table ht un element hte
void hash_table_add(struct hash_table_entry *hte,struct hash_table *ht){

	int hash_index;
	
	hash_index = hash_entry(hte);
	list_add(&(hte->liste),&(((ht->table)[hash_index]).liste));

}

//suppression de l'element hte de la hash_table qui le contient
void hash_table_del(struct hash_table_entry *hte){

	list_del(&(hte->liste));

}
