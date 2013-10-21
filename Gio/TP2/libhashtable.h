/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBHASHTABLE.H - MION GIOVANNI              */
/*                                                                    */
/**********************************************************************/

#include "libliste.h"

// definition du nombre de liste contenu dans notre hashtable
#define nbListe 50

//definition de la macro hash_table_get_by_id
// "i" vaut soit :
// un pointeur vers la stucture contenant un hashtable entry du nom de "member" et ayant un id valant "id" dans la hash_table "ht"
// null si un tel element ne peut étre trouver
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

// definition de la structure hash_table_entry
struct hash_table_entry{

	int entry_id;	
	struct list_head liste;
	
};

//definition d'une hash_table
struct hash_table{

	struct hash_table_entry table[nbListe];

};

// initialisation d'une hash_table
void INIT_HASH_TABLE(struct hash_table *ht);

// calcule de l'indice de la liste en fonction de l'id d'un hash_table_entry
int hash_entry(struct hash_table_entry *hte);

// calcule de l'indice de la liste en fonction d'un id 
int hash_entry_id(int id);

//ajout a la hash_table ht un element hte
void hash_table_add(struct hash_table_entry *hte,struct hash_table *ht);

//suppression de l'element hte de la hash_table qui le contient
void hash_table_del(struct hash_table_entry *hte);

