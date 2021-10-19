#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 10000

int saldo;
pthread_mutex_t saldoLock = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){
    //char *c = (char *)arg; 
    //printf("hola desde un hilo %s \n",c);
    int lsaldo;
    pthread_mutex_lock(&saldoLock);
    lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_mutex_unlock(&saldoLock);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;  
    char *s = "soy un argumento";
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL,suma100,NULL);
    }
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("Saldo final es %d\n",saldo);
    pthread_exit(NULL);
}