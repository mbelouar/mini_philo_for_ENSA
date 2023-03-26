#include "philosophers.h"

int    main(void)
{
    int i;
    int k;
    for (i = 1; i <= 5; i++)
    {
        k = pthread_mutex_init(&chopstick[i], NULL);
        if (k == -1)
        {
            printf("\n Mutex initialization failed");
            exit(1);
        }
    }
    for (i = 1; i <= 5; i++)
    {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        k = pthread_create(&philosopher[i], NULL, (void *)func, arg);
        if (k != 0)
        {
            printf("\n Thread creation error \n");
            exit(1);
        }
    }
    for (i = 1; i <= 5; i++)
    {
        k = pthread_join(philosopher[i], NULL);
        if (k != 0)
        {
            printf("\n Thread join failed \n");
            exit(1);
        }
    }
    for (i = 1; i <= 5; i++)
    {
        k = pthread_mutex_destroy(&chopstick[i]);
        if (k != 0)
        {
            printf("\n Mutex Destroyed \n");
            exit(1);
        }
    }
    return (0);
}

void    *func(void *arg)
{
    int n = *(int *)arg;
    printf("\n\033[1;32mPhilosopher %d is thinking...\033[0m\n", n);
    pthread_mutex_lock(&chopstick[n]);
    pthread_mutex_lock(&chopstick[(n + 1) % 5]);
    printf("\n\033[1;33mPhilosopher %d is eating...\033[0m\n", n);
    sleep(3);
    pthread_mutex_unlock(&chopstick[n]);
    pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
    printf("\n\033[1;34mPhilosopher %d finished eating.\033[0m\n", n);
	return (0);
}

