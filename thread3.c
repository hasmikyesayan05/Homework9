#include <stdio.h>
#include <pthread.h>

void *printNumbers(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Thread %lu: %d\n",
               (unsigned long)pthread_self(), i);
    }

    return NULL;
}

int main() {
    pthread_t threads[3];

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, printNumbers, NULL);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
