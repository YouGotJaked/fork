#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int i, pid;
	
	for (i = 0; i < 8; i++) {
		if (fork() != 0) {
			int status;
			waitpid(-1, &status, 0);
			break;
		} else {
			printf("The child PID is %d, and the parent PID is %d\n", getpid(), getppid());
		}
	}
}
