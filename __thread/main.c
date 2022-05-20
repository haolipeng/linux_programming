#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

__thread int g_mydata = 99;

void* thread_read(void* arg){
    while (1){
        printf("data:%d\n",g_mydata);
        sleep(1);
    }
    return NULL;
}

void* thread_write(void* arg){
    while (1){
        g_mydata++;
    }
    return NULL;
}


int main() {
    //1.create read data thread and write data thread
    pthread_t writeThread;
    pthread_t readThread;

    pthread_create(&readThread,NULL,thread_read,NULL);
    pthread_create(&writeThread,NULL,thread_write,NULL);

    pthread_join(writeThread,NULL);
    pthread_join(readThread,NULL);
    return 0;
}
