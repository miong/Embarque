/**********************************************************************/
/*                                                                    */
/*                  TP2 - TESTLISTE.C - MION GIOVANNI                 */
/*                                                                    */
/**********************************************************************/

#include "libhashtable.h"
#include <stdlib.h>
#include <stdio.h>

struct mynode{
	int element;
	struct list_head ld;
	
};

struct myhashentry{
	int element;
	struct hash_table_entry hte;
};

int main(int argc,char **argv){
	
	/*struct mynode zero;
	zero.element = 0;
	INIT_LIST_HEAD(&(zero.ld));
	printf("element=%d suivant=%p precedent=%p\n",zero.element,zero.ld.suivant,zero.ld.precedent);
	struct mynode un;
	un.element = 1;
	INIT_LIST_HEAD(&(un.ld));
	printf("element=%d suivant=%p precedent=%p\n",un.element,un.ld.suivant,un.ld.precedent);
	list_add(&(un.ld),&(zero.ld));
	printf("element=%d suivant=%p precedent=%p\n",zero.element,zero.ld.suivant,zero.ld.precedent);
	printf("element=%d suivant=%p precedent=%p\n",un.element,un.ld.suivant,un.ld.precedent);
	struct mynode deux;
	deux.element = 2;
	INIT_LIST_HEAD(&(deux.ld));
	list_add(&(deux.ld),&(zero.ld));
	struct mynode *j;
	printf("[");
	list_for_each_entry(j,&(zero.ld),ld){
			printf(" %d ",j->element);
	}
	printf("]\n");
	list_del(&(un.ld));
	printf("element=%d suivant=%p precedent=%p\n",zero.element,zero.ld.suivant,zero.ld.precedent);
	printf("element=%d suivant=%p precedent=%p\n",un.element,un.ld.suivant,un.ld.precedent);*/
	
	struct hash_table ht;
	INIT_HASH_TABLE(&ht);

	struct myhashentry e1;
	e1.element = 1;
	e1.hte.entry_id = 4096;
	hash_table_add(&(e1.hte),&ht);

	struct myhashentry e2;
	e2.element = 2;
	e2.hte.entry_id = 8192;
	hash_table_add(&(e2.hte),&ht);

	int id;
	for(id=0;id<20;id++)
		printf("hash=%d\n",hash_entry_id(4096*id));
		
	struct myhashentry *e;
	hash_table_get_by_id(e,ht,4096,hte);
	if(e != NULL)
		printf("%d\n",e->element);

	hash_table_del(&(e1.hte));

	hash_table_get_by_id(e,ht,4096,hte);
	if(e != NULL)
		printf("%d\n",e->element);
	return 0;
}
