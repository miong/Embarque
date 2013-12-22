/**********************************************************************/
/*                                                                    */
/*                TP7 - INVERSION.C - MION GIOVANNI                   */
/*                                                                    */
/**********************************************************************/
  // NOTE : lancer le programme avec taskset -c 0 ./temps_crea_thread


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>
#include <errno.h>

static int medium_ended;

void P(int semid,short nb){
	struct sembuf op;	
	op.sem_num = nb;
	op.sem_op = -1;
	op.sem_flg = 0;
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

void* thread1_code(void* args){
	int sems,i;
  key_t clef;
	struct sched_param param;
	
	param.sched_priority = 30;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	clef = ftok("./semfile",'S');	
	sems = semget(clef, 2,0666);
	printf("Thread 30\n");

	P(sems,0);
	while(i<5000000){
		i++;
	}
	V(sems,0);
  pthread_exit(NULL);
}

void* thread2_code(void* args){
	struct sched_param param;
	
	param.sched_priority = 50;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	printf("Thread 50\n");
	medium_ended = 1;
  pthread_exit(NULL);
}

void* thread3_code(void* args){
	int sems;
  key_t clef;
	struct sched_param param;
	
	param.sched_priority = 80;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	clef = ftok("./semfile",'S');	
	sems = semget(clef, 2,0666);
	printf("Thread 80\n");
	printf("try to get the sem\n");
	P(sems,0);
	printf("sem OK\n");
	if(medium_ended == 1)
		printf("INVERSION DE PRIORITE\n");
	else
		printf("PAS D'INVERSION DE PRIORITE\n");
  pthread_exit(NULL);
}

int main(int argc,char** argv){
	pthread_t threads[3];
	int sems;
  key_t clef;
  void *arg;
  arg = malloc(sizeof(char));
	clef = ftok("./semfile",'S');
  sems = semget(clef, 2, IPC_CREAT | 0666);
  semctl(sems, 0, SETVAL, 0);
  semctl(sems, 1, SETVAL, 0);
	
	pthread_create(&threads[0],NULL,&thread1_code,arg);
	sleep(5);
	pthread_create(&threads[1],NULL,&thread3_code,arg);
	sleep(5);
	pthread_create(&threads[2],NULL,&thread2_code,arg);

	return 0;
}

