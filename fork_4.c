#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define MAX 4

static int *count;

int main() {
    int i, lvl = 1, children = 2;
    
    //allows for shared memory between processes
    count = mmap(NULL, sizeof *count, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *count = 0;
    
	for (i = 0; i < children; i++) {
		if (fork() != 0) { //parent
			int status;
			waitpid(-1, &status, 0);
		} else { //child
			lvl++;
            		printf("Child PID: %d | Parent PID: %d\n", getpid(), getppid());
            		if (lvl == 3 && *count < 3) { //one process in level 3 creates 2 children, other three create 3 children
                		(*count)++;
				children = 3;
            		}
			i = -1;
		}
	if (lvl >= MAX)
		break;
	}
}
