#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t full,empty,mutex;
int buffer[5],pro[10],con[10],item=0,get=0,put=0,gitem;
void *producer(void*arg)
{
    do
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[put%5]=item;
        item++;
        printf("\nProducer %d produce %d item buffered [%d]:%d",(*(int*)arg),buffer[put%5],put%5,item);
        put++;
        sem_post(&mutex);
        sem_post(&full);
        sleep(3);
    } while (put<5);
}
void *consumer(void *arg)
{
    do
    {
        sem_wait(&full);
        sem_wait(&mutex);
        gitem=buffer[get%5];
        printf("\nConsumer %d consumes %d items buffered[%d]:%d",(*(int*)arg),buffer[get%5],get%5,gitem);
        get++;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    } while (get<5);
    
}
void main()
{
    int p,c,i,j,a[20],b[20];
    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,5);
    printf("Enter the number of producers\n");
    scanf("%d",&p);
    printf("Enter the number of consumers\n");
    scanf("%d",&c);
    for(i=0;i<p;i++)
    {
        pro[i]=i;
        pthread_create(&a[i],NULL,producer,&pro[i]);
    }
    for(j=0;j<c;j++)
    {
        con[j]=j;
        pthread_create(&b[j],NULL,consumer,&con[j]);
    }
    for(i=0;i<p;i++)
    {
        pthread_join(a[j],NULL);
    }
    for(j=0;j<c;j++)
    {
        pthread_join(b[j],NULL);
    }
}