/**********************************************************************/
/*                                                                    */
/*                  TP3 - TEMPS_CREA_THREAD.C - MION GIOVANNI         */
/*                                                                    */
/**********************************************************************/
  // NOTE : lancer le programme avec taskset -c 0 ./temps_crea_thread



#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

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

void* thread_code(void* args){
  pthread_exit(NULL);
}

int main(int argc,char** argv){

  //declaration des variables
  pthread_t threads[50];
  struct timespec t_start_rt,t_stop_rt,t_start_cpu,t_stop_cpu,cpu_res,rt_res;
  double mem_creations_rt[50],mem_creations_cpu[50];
  double moy_cpu,moy_rt;
  int i,j;
  void *arg;
  
  //mesure du temps de creation/destruction d'une thread

  // on regarde la resolution des mesures
  clock_getres(CLOCK_REALTIME,&rt_res);
  clock_getres(CLOCK_PROCESS_CPUTIME_ID,&cpu_res);

  //on fait cette mesure sur 50 cretaions de 50 processus et on calcule la moyenne
  arg = malloc(3*sizeof(char));
  for(i=0;i<50;i++){
    
    //prise du temps avant creation.
    clock_gettime(CLOCK_REALTIME, &t_start_rt);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start_cpu);
    for(j=0;j<1000;j++){
      //creation du thread
      pthread_create(&threads[i],NULL,&thread_code,arg);
      //attente la fin de la thread
      pthread_join(threads[i],NULL);
    }
    //on recupere le temps
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop_cpu);
    clock_gettime(CLOCK_REALTIME, &t_stop_rt);
    //on calcule le temps reel passer entre les deux temps et on la stock dans mem_creations
    mem_creations_cpu[i]= ( ((t_stop_cpu.tv_sec*pow(10,9)+t_stop_cpu.tv_nsec) - (t_start_cpu.tv_sec*pow(10,9)+t_start_cpu.tv_nsec))/1000.0 );
    mem_creations_rt[i]= ( ((t_stop_rt.tv_sec*pow(10,9)+t_stop_rt.tv_nsec) - (t_start_rt.tv_sec*pow(10,9)+t_start_rt.tv_nsec))/1000.0 );
  }
  
  //calule de la moyenne et affichage de celle-ci
  moy_cpu = array_moy(mem_creations_cpu,50);
  moy_rt = array_moy(mem_creations_rt,50);
  printf("\nla moyenne de temps CPU pour la creation/destruction de threads est:\n%f nanosecondes\n%f secondes\n\n",moy_cpu,moy_cpu/pow(10,9));
  printf("la moyenne de temps RT pour la creation/destruction de threads est:\n%f nanosecondes\n%f secondes\n\n",moy_rt,moy_rt/pow(10,9));

  printf("resolution des mesures:\nCPU = %ld nsec\nRT = %ld nsec\n\n",cpu_res.tv_nsec,rt_res.tv_nsec);


  return 1;

}
