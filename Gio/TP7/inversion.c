
/**********************************************************************/
/*                                                                    */
/*                TP7 - INVERSION.C - MION GIOVANNI                   */
/*                                                                    */
/**********************************************************************/
  // NOTE : lancer le programme avec taskset -c 0 ./temps_crea_thread


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

//variables globales
static int medium_ended;
static int go_foward;
pthread_mutex_t mutex;

// main du thread de basse priorite
void* thread1_code(void* args){
	struct sched_param param;
	
	param.sched_priority = 30;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	printf("Thread basse priorite\n");

	pthread_mutex_lock(&mutex);
	while(!go_foward); // attente active avant de liberer le mutex
	pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

// main du thread de moyenne priorite
void* thread2_code(void* args){
	struct sched_param param;
	
	param.sched_priority = 50;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	printf("Thread moyenne priorite\n");
	medium_ended = 1; // declaration de la terminaison du thread de moyenne priorite
  pthread_exit(NULL);
}

// main du thread de haute priorite
void* thread3_code(void* args){
	struct sched_param param;
	
	param.sched_priority = 80;
	pthread_setschedparam(pthread_self(),SCHED_FIFO,&param);
	printf("Thread haute priorité\n");
	pthread_mutex_lock(&mutex); // tentative de recuperation du mutex
	if(medium_ended == 1) // le thread de moyenne priorité s est execute avant recuperation du mutex si vrai
		printf("INVERSION DE PRIORITE\n");
	else
		printf("PAS D'INVERSION DE PRIORITE\n");
  pthread_exit(NULL);
}

int main(int argc,char** argv){
	pthread_t threads[3];
	pthread_mutexattr_t   m_attr;
  void *arg;
  arg = malloc(sizeof(char));

	//creation des attributs du mutex
	pthread_mutexattr_init(&m_attr);
	pthread_mutexattr_setpshared(&m_attr, PTHREAD_PROCESS_SHARED);
	if(argc==2 && strcmp(argv[1],"heritage")==0){
		pthread_mutexattr_setprotocol(&m_attr, PTHREAD_PRIO_INHERIT);	
		printf("Heritage de priorité activé\n");
	}
	// initialisation du mutex
	pthread_mutex_init(&mutex, &m_attr);	

	//Creation des threads espacees dans le temps pour verifier l'inversion de priorite
	pthread_create(&threads[0],NULL,&thread1_code,arg);
	sleep(5);
	pthread_create(&threads[1],NULL,&thread3_code,arg);
	sleep(5);
	pthread_create(&threads[2],NULL,&thread2_code,arg);
	go_foward=1; // fin d'attente active pour le thread de basse priorite
	pthread_join(threads[1],NULL);
	return 0;
}

