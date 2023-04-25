#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include<semaphore.h>

pthread_mutex_t mutex;
sem_t sm;
FILE *fptr_read,*fptr_write;

void* file_writer(void* arg) {
      int argument=*(int*)arg;
      for(int i=0;i<5;++i){
        printf("[Thread %d]Waiting for semaphore\n", argument);
        sem_wait(&sm);
        printf("[Thread %d]Waiting for lock\n", argument);
        pthread_mutex_lock(&mutex);
        printf("[Thread %d]Lock acquired\n", argument);
        fprintf(fptr_write,"%d",i+1);
        printf("Wrote in file by thread %d: %d\n",argument,i);
        pthread_mutex_unlock(&mutex);
        printf("[Thread %d]Lock released\n", argument);
        sem_post(&sm);
        printf("[Thread %d]Semaphore value incremented\n", argument);
        sleep(1);
      }
}

void* file_reader(void* arg) {
    int argument=*(int*)arg;
    for(int i=0;i<5;++i){
        printf("[Thread %d]Waiting for lock\n", argument);
        pthread_mutex_lock(&mutex);
        printf("[Thread %d]Lock acquired for computing semaphore value\n", argument);
        int semVal;
        sem_getvalue(&sm,&semVal);
        pthread_mutex_unlock(&mutex);
        printf("[Thread %d]Lock released after computing semaphore value\n", argument);
        if(semVal==1){
          int num;
          fscanf(fptr_read,"%d",&num);
          printf("Got value by thread %d: %d\n",argument,num);
        }
        sleep(2);
    }
}

int main(int argc, char* argv[]) {
    fptr_write = fopen("data.txt", "w");
    fptr_read = fopen("data.txt", "r");
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sm,0,1);
    for(int i = 0; i < 4; i++) {
            int *a=malloc(sizeof(int));
            *a=i;
            if(i%2==0){
              if (pthread_create(&th[i], NULL, &file_reader, a) != 0) {
                  perror("Failed to create thread");
              }
            }else{
              if (pthread_create(&th[i], NULL, &file_writer, a) != 0) {
                  perror("Failed to create thread");
              }
            }
    }
    

    for (int i = 0; i < 4; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&sm);
    fclose(fptr_read);
    fclose(fptr_write);
    return 0;
}
