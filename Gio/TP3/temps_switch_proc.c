/**********************************************************************/
/*                                                                    */
/*                TP3 - TEMPS_SWITCH_PROC.C - MION GIOVANNI           */
/*                                                                    */
/**********************************************************************/
  // NOTE : lancer le programme avec taskset -c 0 ./temps_crea_thread


#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

void P(int semid,short nb){
	struct sembuf op;	
	op.sem_num = nb;
	op.sem_op = -1;
	op.sem_flg = 25;
	if(semop(semid, &op, 1)<0){
	  printf("Erreur P : %d\n",errno);
	}
}

void V(int semid,short nb){
	struct sembuf op;	
	op.sem_num = nb;
	op.sem_op = 1;
	op.sem_flg = 0;
	if(semop(semid, &op, 1)<0){
	  printf("Erreur V : %d\n",errno);
	}
}

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
  int i,j,ret_fork,sems;
  key_t clef;
  
  
  
  // Creation de la clef et initilaisation des sémaphores
  clef = ftok("./semfile",'S');
  sems = semget(clef, 2, IPC_CREAT | 0666);
  semctl(sems, 0, SETVAL, 0);
  semctl(sems, 1, SETVAL, 0);

  // on regarde la resolution des mesures
  clock_getres(CLOCK_REALTIME,&rt_res);
  clock_getres(CLOCK_PROCESS_CPUTIME_ID,&cpu_res);

  //mesure du temps de creation d'un processus
  
  //on fait cette mesure sur 50 cretaions de 50 processus et on calcule la moyenne
  for(i=0;i<50;i++){
    
    //creation du fils et changements de context 1000 fois
    ret_fork = fork();
    if(ret_fork==-1){
	printf("Erreur impossible de crée de processus fils");
	exit(1);
    }
    if(ret_fork){
			//dans le pere
	
			//prise du temps avant creation.
      clock_gettime(CLOCK_REALTIME, &t_start_rt);
      clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_start_cpu);
			for(j=0;j<1000;j++){
	  		V(sems,0);
	  		//printf("%d a vendu s1\n",ret_fork);
    		P(sems,1);
	  		//printf("%d a prid s2\n",ret_fork);
			}
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t_stop_cpu);
    	clock_gettime(CLOCK_REALTIME, &t_stop_rt);
			wait(NULL);
    }else{
			//dans le fils
			for(j=0;j<1000;j++){
	  		P(sems,0);
	  		//printf("%d a prid s1\n",ret_fork);
    		V(sems,1);
	  		//printf("%d a vendu s2\n",ret_fork);
			}
			exit(1);
    }
    
    //on calcule le temps reel passer entre les deux temps et on la stock dans mem_creations
    mem_creations_cpu[i]= ( ((t_stop_cpu.tv_sec*pow(10,9)+t_stop_cpu.tv_nsec) - (t_start_cpu.tv_sec*pow(10,9)+t_start_cpu.tv_nsec))/1000.0 );
    mem_creations_rt[i]= ( ((t_stop_rt.tv_sec*pow(10,9)+t_stop_rt.tv_nsec) - (t_start_rt.tv_sec*pow(10,9)+t_start_rt.tv_nsec))/1000.0 );
  }

  //calule de la moyenne et affichage de celle-ci
  moy_cpu = array_moy(mem_creations_cpu,50);
  moy_rt = array_moy(mem_creations_rt,50);
  printf("\nla moyenne de temps CPU pour le changement de processus est:\n%f nanosecondes\n%f secondes\n\n",moy_cpu,moy_cpu/pow(10,9));
  printf("la moyenne de temps RT pour le changement de processus est:\n%f nanosecondes\n%f secondes\n\n",moy_rt,moy_rt/pow(10,9));

  printf("resolution des mesures:\nCPU = %ld nsec\nRT = %ld nsec\n\n",cpu_res.tv_nsec,rt_res.tv_nsec);


  return 1;

}

