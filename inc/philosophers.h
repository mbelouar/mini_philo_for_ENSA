#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void            *func(void *arg);
pthread_t        philosopher[5];
pthread_mutex_t    chopstick[5];

#endif