#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 4

// include overview of each program

int main() {
	int i, lvl = 1, children = 2, once = 0;

	for (i = 0; i < children; i++) {
		if (fork() != 0) {
			printf("PID: %d\n", getpid());
			int status;
			waitpid(-1, &status, 0);
		} else {
			lvl++;
			printf("The child PID is %d and the parent PID is %d, i = [%d], children = [%d], lvl = [%d]\n", getpid(), getppid(), i, children, lvl);
			if (lvl == 3)
				children = 3;
			i = -1;
		}
	
		if (lvl >= MAX)
			break;
	}
} 
