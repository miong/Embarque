/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBHASHTABLE.H - MION GIOVANNI              */
/*                                                                    */
/**********************************************************************/

#include "libliste.h"

#define nbListe 50

#define hash_table_get_by_id(i,ht,id,member)		({ \
			int __index= hash_entry_id(id); \
			struct list_head *__lh = &(ht.table[__index].liste); \
			struct hash_table_entry *__hte; \
			list_for_each_entry(__hte,__lh,liste){ \
				if( __hte->entry_id == id ){ \
					break; \
				}\
			}\
			i= (__hte->entry_id == id) ? container_of(__hte,typeof(*i),member) : NULL; \
			})

struct hash_table_entry{

	int entry_id;	
	struct list_head liste;
	
};

struct hash_table{

	struct hash_table_entry table[nbListe];

};

void INIT_HASH_TABLE(struct hash_table *ht);
int hash_entry(struct hash_table_entry *hte);
int hash_entry_id(int id);
void hash_table_add(struct hash_table_entry *hte,struct hash_table *ht);
void hash_table_del(struct hash_table_entry *hte);

