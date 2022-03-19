//Solution for Producer – 
/*
do{

//produce an item

wait(empty);
wait(mutex);

//place in buffer

signal(mutex);
signal(full);

}while(true)
*/

//Solution for Consumer – 
/*
do{

wait(full);
wait(mutex);

// remove item from buffer

signal(mutex);
signal(empty);

// consumes item

}while(true)
*/


//when the buffer size is inifite-
#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
using namespace std;

// Declaration
int r1,total_produced=0,total_consume=0;

// Semaphore declaration
sem_t notEmpty;

// Producer Section
void* produce(void *arg){
	while(1){
	cout<<"Producer produces item."<<endl;
	cout<<"Total produced = "<<++total_produced<<
		" Total consume = "<<total_consume*-1<<endl;
	sem_post(¬Empty);	
	sleep(rand()%100*0.01);
	}
}

// Consumer Section
void* consume(void *arg){
	while(1){
	sem_wait(¬Empty);
	cout<<"Consumer consumes item."<<endl;	
	cout<<"Total produced = "<<total_produced<<
		" Total consume = "<<(--total_consume)*-1<<endl;
	sleep(rand()%100*0.01);
	}	
}

int main(int argv,char *argc[]){

	// thread declaration
	pthread_t producer,consumer;

	// Declaration of attribute......
	pthread_attr_t attr;

	// semaphore initialization
	sem_init(¬Empty,0,0);

	// pthread_attr_t initialization
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);

	// Creation of process
	r1=pthread_create(&producer,&attr,produce,NULL);
	if(r1){
	cout<<"Error in creating thread"<<endl;
	exit(-1);
	}

	r1=pthread_create(&consumer,&attr,consume,NULL);
	if(r1){
	cout<<"Error in creating thread"<<endl;
	exit(-1);
	}

	// destroying the pthread_attr
	pthread_attr_destroy(&attr);

	// Joining the thread
	r1=pthread_join(producer,NULL);
	if(r1){
	cout<<"Error in joining thread"<<endl;
	exit(-1);
	}

	r1=pthread_join(consumer,NULL);
	if(r1){
	cout<<"Error in joining thread"<<endl;
	exit(-1);
	}

	// Exiting thread
	pthread_exit(NULL);

	return 0;
}


/Where the buffer size is fixed or finite –/Where the buffer size is fixed or finite –
#include <bits/stdc++.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

// Declaration
int r1, items = 0;

// Semaphore declaration
sem_t notEmpty, notFull;

// Producer Section
void* produce(void* arg)
{
	while (1) {
		sem_wait(¬Full);
		sleep(rand() % 100 * 0.01);
		cout <<
	"Producer produces item.Items Present = "
			<< ++items << endl;
		sem_post(¬Empty);
		sleep(rand() % 100 * 0.01);
	}
}

// Consumer Section
void* consume(void* arg)
{
	while (1) {
		sem_wait(¬Empty);
		sleep(rand() % 100 * 0.01);
		cout <<
	"Consumer consumes item.Items Present = "
			<< --items << endl;
		sem_post(¬Full);
		sleep(rand() % 100 * 0.01);
	}
}

int main(int argv, char* argc[])
{

	int N;
	cout <<
	"Enter the capacity of the buffer" << endl;
	cin >> N;

	// thread declaration
	pthread_t producer, consumer;

	// Declaration of attribute......
	pthread_attr_t attr;

	// semaphore initialization
	sem_init(¬Empty, 0, 0);
	sem_init(¬Full, 0, N);

	// pthread_attr_t initialization
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,
			PTHREAD_CREATE_JOINABLE);

	// Creation of process
	r1 = pthread_create(&producer, &attr,
						produce, NULL);
	if (r1) {
		cout <<
		"Error in creating thread" << endl;
		exit(-1);
	}

	r1 = pthread_create(&consumer, &attr,
						consume, NULL);
	if (r1) {
		cout <<
		"Error in creating thread" << endl;
		exit(-1);
	}

	// destroying the pthread_attr
	pthread_attr_destroy(&attr);

	// Joining the thread
	r1 = pthread_join(producer, NULL);
	if (r1) {
		cout << "Error in joining thread" << endl;
		exit(-1);
	}

	r1 = pthread_join(consumer, NULL);
	if (r1) {
		cout << "Error in joining thread" << endl;
		exit(-1);
	}

	// Exiting thread
	pthread_exit(NULL);

	return 0;
}
