#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    pthread_t thread = pthread_self();
    char threadName[256];
    int threadPriority;

    pthread_getname_np(thread, threadName, 256);
    threadPriority = sched_get_priority_max(SCHED_OTHER);

    printf("Thread Name: %s\n", threadName);
    printf("Thread Priority: %d\n", threadPriority);

    pthread_setname_np(pthread_self(), "New Thread Name");
    pthread_getname_np(thread, threadName, 256);

    printf("New Thread Name: %s\n", threadName);

    return NULL;
}

int main() {
    pthread_t thread1;

    pthread_create(&thread1, NULL, threadFunction, NULL);

    pthread_join(thread1, NULL);

    return 0;
}