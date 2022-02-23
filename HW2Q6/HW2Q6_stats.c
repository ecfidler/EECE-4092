/**
 * 
 *
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons, 2013.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* the list of integers */
int *list;

/* the threads will set these values */
double average;
int maximum;
int minimum;

void *calculate_average(void *param);
void *calculate_maximum(void *param);
void *calculate_minimum(void *param);

int argLength;

int main(int argc, char *argv[])
{
	pthread_t tid0;
	pthread_t tid1;
	pthread_t tid2;
	pthread_attr_t attr0;
	pthread_attr_t attr1;
	pthread_attr_t attr2;


	if (argc <= 2) {
		printf("Not enough Arguments passed!");
		return -1;
	}

	list = malloc((argc-1) * sizeof(int));

	argLength = argc-1;

	for (int i = 0; i < argLength; i++) {
		list[i] = atoi(argv[i+1]);
	}

	pthread_attr_init(&attr0);
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);

	pthread_create(&tid0,&attr0,calculate_average,list);
	pthread_create(&tid1,&attr1,calculate_maximum,list);
	pthread_create(&tid2,&attr2,calculate_minimum,list);

	pthread_join(tid0,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	printf("average = %f\n",average);
	printf("maximum = %d\n",maximum);
	printf("minimum = %d\n",minimum);

	return 0;
}

void *calculate_average(void *param)
{
	int sum = 0;
	for (int i = 0; i< argLength; i++) {
		printf("%d ", list[i]);
		sum += list[i];
	}
	average = (double)sum/(double)argLength;
}

void *calculate_maximum(void *param)
{
	int max = 0;
	for (int i = 0; i < argLength; i++) {
		if (list[i]>max) {
			max = list[i];
		}
	}
	maximum = max;
}

void *calculate_minimum(void *param)
{
	int min = list[0];
	for (int i = 0; i < argLength; i++) {
		if (list[i]<min) {
			min = list[i];
		}
	}
	minimum = min;
}

