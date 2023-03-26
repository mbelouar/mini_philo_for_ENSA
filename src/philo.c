#include "philosophers.h"

void	*philosopher(void *arg)
{
	int	philosopher_id;
	int	left;
	int	right;

	philosopher_id = *(int *)arg;
	left = philosopher_id;
	right = (philosopher_id + 1) % NUM_PHILOSOPHERS;
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		printf("\n\033[1;32mPhilosopher %d is thinking...\033[0m\n", philosopher_id);
		pthread_mutex_lock(&chopstick[left]);
		pthread_mutex_lock(&chopstick[right]);
		printf("\n\033[1;33mPhilosopher %d is eating...\033[0m\n", philosopher_id);
		sleep(3);
		pthread_mutex_unlock(&chopstick[right]);
		pthread_mutex_unlock(&chopstick[left]);
		printf("\n\033[1;34mPhilosopher %d finished eating.\033[0m\n", philosopher_id);
	}
	return (NULL);
}

int	main(void)
{
    int thread_args[NUM_PHILOSOPHERS];
	int i, k;
	for (i = 1; i <= NUM_PHILOSOPHERS; i++)
	{
		k = pthread_mutex_init(&chopstick[i], NULL);
		if (k != 0)
		{
			printf("Mutex initialization failed\n");
			return (1);
		}
	}
	for (i = 1; i <= NUM_PHILOSOPHERS; i++)
	{
		thread_args[i] = i;
		k = pthread_create(&threads[i], NULL, (void *)philosopher, (void *)&thread_args[i]);
		if (k != 0)
		{
			printf("Thread creation error\n");
			return (1);
		}
	}
	for (i = 1; i <= NUM_PHILOSOPHERS; i++)
	{
		k = pthread_join(threads[i], NULL);
		if (k != 0)
		{
			printf("Thread join failed\n");
			return (1);
		}
	}
	for (i = 1; i <= NUM_PHILOSOPHERS; i++)
	{
		k = pthread_mutex_destroy(&chopstick[i]);
		if (k != 0)
		{
			printf("Mutex destroyed\n");
			return (1);
		}
	}
	return (0);
}
