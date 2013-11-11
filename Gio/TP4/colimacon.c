/**********************************************************************/
/*                                                                    */
/*                  TP1 - COLIMACON.C - MION GIOVANNI                 */
/*                                                                    */
/**********************************************************************/
#include <stdlib.h>
#include <stdio.h>

int colimacon(int **array, unsigned int rows, unsigned int columns){

	//definition des variables utilisees par l'algorithme
	unsigned int r_max,r_min,c_max,c_min,cpt,cpt_max;
	int* tmp;

	//definition des varibles de boucle
	int i;

	//creation du tableau
	tmp = (int*)malloc(rows*columns*sizeof(int)); 

	//initialisation des variables de l'algorithme
	r_max = rows-1;
	r_min = 0;
	c_max = columns-1;
	c_min = 0;
	cpt = 1;
	cpt_max = rows * columns;

	// debut de l'algorithme de remplissage
	// on remplit les lignes et colonnes les plus extérieures qui ne sont pas encore remplies (1 boucle "for" par bord)
	while(cpt <= cpt_max ){

			for(i=c_min;i<=c_max;i++){
				tmp[r_min * columns + i]=cpt;
				cpt++;
			}
			r_min++;

			for(i=r_min;i<=r_max;i++){
				tmp[i * columns + c_max]=cpt;
				cpt++;
			}
			c_max--;

			for(i=c_max;(i>=(int)c_min)&&((int)r_max>=(int)r_min);i--){
				tmp[r_max * columns + i]=cpt;
				cpt++;
			}
			r_max--;

			for(i=r_max;(i>=(int)r_min)&&((int)c_max>=(int)c_min);i--){
				tmp[i * columns + c_min]=cpt;
				cpt++;
			}
			c_min++;

	}
	*(array)=tmp;
	if(array==NULL)
	return -1;

	return 0;

}
