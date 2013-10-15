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
	int** tmp;

	//definition des varibles de boucle
	int i;

	//creation du tableau
	tmp = (int**)malloc(rows*sizeof(int*));
	if(tmp==NULL)
	return -1;
	for(i=0;i<rows;i++){
			tmp[i]=(int*)malloc(columns*sizeof(int));
	    if(tmp[i]==NULL)
			return -1;
  } 

	//initialisation des variables de l'algorithme
	r_max = rows-1;
	r_min = 0;
	c_max = columns-1;
	c_min = 0;
	cpt = 1;
	cpt_max = rows * columns;

	// debut de l'algorithme de remplissage
	// on remplis les ligne et colonnes les plus extérieurs qui ne sont pas encore remplie (1 boucle "for" par bords)
	while(cpt <= cpt_max ){

			for(i=c_min;i<=c_max;i++){
				tmp[r_min][i]=cpt;
				cpt++;
			}
			r_min++;

			for(i=r_min;i<=r_max;i++){
				tmp[i][c_max]=cpt;
				cpt++;
			}
			c_max--;

			for(i=c_max;(i>=(int)c_min)&&((int)r_max>=(int)r_min);i--){
				tmp[r_max][i]=cpt;
				cpt++;
			}
			r_max--;

			for(i=r_max;(i>=(int)r_min)&&((int)c_max>=(int)c_min);i--){
				tmp[i][c_min]=cpt;
				cpt++;
			}
			c_min++;

	}
	*(array)=(int*)&(tmp[0]);
	if(array==NULL)
	return -1;

	return 0;

}
