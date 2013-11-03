#ifndef _ENTETE_
#define _ENTETE_
struct maillon{
	int valeur;
	struct maillon* precedent;
};

extern int facteur_boucle(struct maillon* a, struct maillon* b);
extern int print_from_maillon(struct maillon* a);
extern int check_moves_in_array(int* array, unsigned int size);
#endif
