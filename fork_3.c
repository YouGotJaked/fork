#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 3

int main() {
	int i, lvl = 1, children = 3;

	for (i = 0; i < children; i++) {
		if (fork() != 0) {
			int status;
			waitpid(-1, &status, 0);
		} else {
			lvl++;
			printf("The child PID is %d and the parent PID is %d\n", getpid(), getppid());
			i = -1;
		}
	
		if (lvl >= MAX)
			break;
	}
} 
