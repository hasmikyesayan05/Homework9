#include <stdio.h>
#include <pthread.h>

int numbers[] = {1, 2, 3, 4, 5, 6};

void *calculateSum(void *arg) {
    int start = *(int *)arg;
    int sum = 0;

    for (int i = start; i < start + 3; i++) {
        sum += numbers[i];
    }

    printf("Thread %lu: Sum = %d\n",
           (unsigned long)pthread_self(), sum);

    return NULL;
}

int main() {
    pthread_t threads[2];
    int starts[2] = {0, 3};

    for (int i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, calculateSum, &starts[i]);
    }

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
