/**********************************************************************/
/*                                                                    */
/*                  TP3 - TEMPS_CREA_PROC.C - MION GIOVANNI           */
/*                                                                    */
/**********************************************************************/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

double array_moy(long* array,int length){
  //decalration des variables
  double cpt;
  int ind;
  
  //Parcour du tableau et calcule de la somme des elements
  cpt=0;
  for(ind=0;ind<length;ind++)
    cpt+=array[ind];
  
  //Retourne la moyenne en divisant la somme par le nombre d'elements
  return cpt/length;
}

int main(int argc,char** argv){

  //declaration des variables
  struct timespec t_start,t_stop;
  long mem_creations[50];
  double moy;
  int i,j,ret_fork;
  
  //mesure du temps de creation d'un processus
  
  //on fait cette mesure sur 50 cretaions de 50 processus et on calcule la moyenne
  for(i=0;i<50;i++){
    
    //prise du temps avant creation.
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start);
    for(j=0;j<50;j++){
      //creation du fils
      ret_fork = fork();
      if(ret_fork==0){
	//dans le fils, on se fait rien et l'on quitte.
	exit(1);
      }
    }
      //dans le pere on attend la fin du fils et l'on recupere le temps
    for(j=0;j<50;j++)
      wait(NULL);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop);
    //on calcule le temps reel passer entre les deux temps et on la stock dans mem_creations
    mem_creations[i]= ( ((t_stop.tv_sec*pow(10,9)+t_stop.tv_nsec) - (t_start.tv_sec*pow(10,9)+t_start.tv_nsec))/50 );
  }
  
  //calule de la moyenne et affichage de celle-ci
  moy = array_moy(mem_creations,50);
  printf("la moyenne de temps pour la creation/destruction de processus est:\n%f nanosecondes\n%f secondes\n",moy,moy/pow(10,9));


  return 1;

}

