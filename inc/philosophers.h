#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define NUM_PHILOSOPHERS 5

pthread_t	threads[NUM_PHILOSOPHERS];
pthread_mutex_t chopstick[NUM_PHILOSOPHERS];
void	*philosopher(void *arg);
#endif