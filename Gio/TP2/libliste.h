/**********************************************************************/
/*                                                                    */
/*                  TP2 - LIBLISTE.H - MION GIOVANNI                  */
/*                                                                    */
/**********************************************************************/

#include <stddef.h>

//definition de la macro container_of
//elle renvoi a comme valeur un pointeur vers la structure de type "type" contant le membre "membre" ayant comme valeur "ptr"
#define container_of(ptr, type, member) ({		\
			const typeof(  ((type *)0)->member ) *__mptr = (ptr);	\
			(type *) ( (char *)__mptr - offsetof(type,member) );})

//definition de la macro list_for_each_entry
//elle passe sur tout les elements de la liste dont la téte est "head" dont les elements on une structure list_head du nom de "membre"
// "cur" prend la valeur de chacun des elements de la liste
#define list_for_each_entry(cur, head, member)		\
			for(cur=container_of((head)->suivant,typeof(*cur),member);&(cur->member) != head;cur=container_of((cur->member).suivant,typeof(*cur),member))
			
// structure definissant un double maillage dans une liste
struct list_head{

	struct list_head *suivant;
	struct list_head *precedent;
};

// initialisation de la téte de liste
void INIT_LIST_HEAD (struct list_head *head);

//ajout de l'element node a la liste dont la téte est head
void list_add (struct list_head *node, struct list_head *head);

// suppresion de l'element node dans la liste a laquelle il appartient
void list_del (struct list_head *node);

