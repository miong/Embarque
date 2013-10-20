/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBLISTE.H - MION GIOVANNI                  */
/*                                                                    */
/**********************************************************************/

#include <stddef.h>

#define container_of(ptr, type, member) ({		\
			const typeof(  ((type *)0)->member ) *__mptr = (ptr);	\
			(type *) ( (char *)__mptr - offsetof(type,member) );})

#define list_for_each_entry(cur, head, member)		\
			for(cur=container_of((head)->suivant,typeof(*cur),member);&(cur->member) != head;cur=container_of((cur->member).suivant,typeof(*cur),member))
			

struct list_head{

	struct list_head *suivant;
	struct list_head *precedent;
};

void INIT_LIST_HEAD (struct list_head *head);
void list_add (struct list_head *node, struct list_head *head);
void list_del (struct list_head *node);

