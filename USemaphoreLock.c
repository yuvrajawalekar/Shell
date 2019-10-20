//apropos semaphore


#include<stdio.h>
#include<semaphore.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<pthread.h>
#include<unistd.h>


int g_count = 10;
int value=0;
sem_t lock;

void* func1(void *input)
{
	sleep(1);
	//pthread_mutex_lock(&lock);
	int a=sem_wait(&lock);
	printf("%s: Initial Value is: %d\n", __func__, g_count);
	if (g_count > 0)
	{
		//sleep(1);
		g_count +=1;
		printf("%s: Incremented value : %d\n", __func__, g_count);
	}
	sleep(10);
	printf("Sem Value == %d\n", sem_getvalue(&lock, &value));
	int b=sem_post(&lock);
	//pthread_mutex_unlock(&lock);
	return NULL;
}

void* func2(void *input)
{
	int a=sem_wait(&lock);
	printf("%s: Initial Value is: %d===%d\n", __func__, g_count,a);
	if (g_count > 0)
	{	
		g_count+=1;
		printf("%s: Incremented Value: %d\n", __func__, g_count);
	}
	sleep(10);
	int b=sem_post(&lock);

	return NULL;
}



int main()
{
	pthread_t tid[2];

	sem_init(&lock, 0, 1);//unmaned semaphore

//	lock=sem_open("Priya_sem", O_CREAT ,0666,1);//named semaphore

	
	pthread_create(&tid[0], NULL, func1, NULL);
	pthread_create(&tid[1], NULL, func2, NULL);
	
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	sleep(15);
	int x=sem_destroy(&lock);
	if(x==0)
	printf("Semaphore destoyed Normally\n");
	else
	printf("Semaphore destoyed Abnormally\n");

	return 0;

}

