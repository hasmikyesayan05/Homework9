#include <stdio.h>
#include <pthread.h>

void *printMessage(void *arg) {
    printf("Thread %lu is running\n", (unsigned long)pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printMessage, NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
