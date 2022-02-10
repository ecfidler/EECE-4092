/**
 *
 * Operating System Concepts
 * Copyright John Wiley & Sons, 2013.
 */

#include "pid.h"
#include <pthread.h>
#include <stdio.h>
#include <string.h>

/**
 * Allocates the pid map.
 */
int allocate_map(void) 
{
	memset(pid_map, 0, sizeof pid_map);
	if (pid_map) {
		return 1;
	}
	else {
		return -1;
	}
}

/**
 * Allocates a pid
 */
int allocate_pid(void)
{
	for (int i = PID_MIN; i < PID_MAX; i++) {
		if (!pid_map[i]) {
			pid_map[i] = 1;
			return i;
		}
	}
	return -1;
}

/**
 * Releases a pid
 */
void release_pid(int pid)
{
	pid_map[pid] = 0;
}
