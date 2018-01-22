#include <stdio.h> 
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i, children = 8;
	
	for (i = 0; i < children; i++) {
		if (fork() != 0) { //parent
			int status;
			waitpid(-1, &status, 0);
			break;
		} else { //child
			printf("The child PID is %d, and the parent PID is %d\n", getpid(), getppid());
		}
	}
}
