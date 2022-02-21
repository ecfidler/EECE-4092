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

int main(int argc, char *argv[])
{
	/* write your code: allocate memory to hold array of integers, create the threads, wait for the threads to exit, and print out the results */


	return 0;
}

void *calculate_average(void *param)
{
	/*write your code here*/

}

void *calculate_maximum(void *param)
{
	/*write your code here*/

}

void *calculate_minimum(void *param)
{
	/*write your code here*/

}

