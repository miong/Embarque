/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBHASHTABLE.C - MION GIOVANNI              */
/*                                                                    */
/**********************************************************************/

#include "libhashtable.h"
#include <stdlib.h>
#include <stdio.h>

void INIT_HASH_TABLE(struct hash_table *ht){

	int i;
	for(i=0;i<nbListe;i++){
		INIT_LIST_HEAD(&(ht->table[i].liste));
	}
}


int hash_entry(struct hash_table_entry *hte){
	return hash_entry_id(hte->entry_id);
}

int hash_entry_id(int id){
	return (256*id)%50;
}

void hash_table_add(struct hash_table_entry *hte,struct hash_table *ht){

	int hash_index;
	
	hash_index = hash_entry(hte);
	list_add(&(hte->liste),&(((ht->table)[hash_index]).liste));

}

void hash_table_del(struct hash_table_entry *hte){

	list_del(&(hte->liste));

}
