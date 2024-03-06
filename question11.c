#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by the first thread
void *threadFunction1(void *arg) {
    printf("Thread 1 is running\n");
    for (int i = 0; i < 5; i++) {
        printf("Thread 1: %d\n", i);
    }
    printf("Thread 1 is finished\n");
    return NULL;
}

// Function executed by the second thread
void *threadFunction2(void *arg) {
    printf("Thread 2 is running\n");
    for (int i = 0; i < 5; i++) {
        printf("Thread 2: %d\n", i);
    }
    printf("Thread 2 is finished\n");
    return NULL;
}

int main() {
    pthread_t tid1, tid2; // Thread IDs

    // Create the first thread
    if (pthread_create(&tid1, NULL, threadFunction1, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Create the second thread
    if (pthread_create(&tid2, NULL, threadFunction2, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for the first thread to finish
    if (pthread_join(tid1, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    // Wait for the second thread to finish
    if (pthread_join(tid2, NULL) != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("Both threads have finished\n");

    return 0;
}

