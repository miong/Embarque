/**********************************************************************/
/*                                                                    */
/*                  TP3 - TEMPS_CREA_PROC.C - MION GIOVANNI           */
/*                                                                    */
/**********************************************************************/
  // NOTE : lancer le programme avec taskset -c 0 ./temps_crea_thread


#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

double array_moy(double* array,int length){
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
	struct timespec t_start_rt,t_stop_rt,t_start_cpu,t_stop_cpu,cpu_res,rt_res;
  double mem_creations_rt[50],mem_creations_cpu[50];
  double moy_rt,moy_cpu;
  int i,j,ret_fork;
  
  // on regarde la resolution des mesures
  clock_getres(CLOCK_REALTIME,&rt_res);
  clock_getres(CLOCK_PROCESS_CPUTIME_ID,&cpu_res);

  //mesure du temps de creation d'un processus
  
  //on fait cette mesure sur 50 cretaions de 50 processus et on calcule la moyenne
  for(i=0;i<50;i++){
    
    //prise du temps avant creation.
		clock_gettime(CLOCK_REALTIME, &t_start_rt);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start_cpu);

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
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop_cpu);
    clock_gettime(CLOCK_REALTIME, &t_stop_rt);
    //on calcule le temps reel passer entre les deux temps et on la stock dans mem_creations
    mem_creations_cpu[i]= ( ((t_stop_cpu.tv_sec*pow(10,9)+t_stop_cpu.tv_nsec) - (t_start_cpu.tv_sec*pow(10,9)+t_start_cpu.tv_nsec))/50.0 );
    mem_creations_rt[i]= ( ((t_stop_rt.tv_sec*pow(10,9)+t_stop_rt.tv_nsec) - (t_start_rt.tv_sec*pow(10,9)+t_start_rt.tv_nsec))/50.0 );
  }
  
  //calule de la moyenne et affichage de celle-ci
  moy_cpu = array_moy(mem_creations_cpu,50);
  moy_rt = array_moy(mem_creations_rt,50);
  printf("\nla moyenne de temps CPU pour la creation/destruction de processus est:\n%f nanosecondes\n%f secondes\n\n",moy_cpu,moy_cpu/pow(10,9));
  printf("la moyenne de temps RT pour la creation/destruction de processus est:\n%f nanosecondes\n%f secondes\n\n",moy_rt,moy_rt/pow(10,9));

  printf("resolution des mesures:\nCPU = %ld nsec\nRT = %ld nsec\n\n",cpu_res.tv_nsec,rt_res.tv_nsec);


  return 1;

}

