#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 32

int main() {
	char command[SIZE];
	char exit[SIZE] = "exit\0";

	while(1) {
		printf("Enter a command or 'exit' to quit: $ ");
		scanf("%s", &command); 		
		
		if (strcmp(command, exit) == 0)
			break;

		if (fork() != 0) {
			// parent code
			int status;
			waitpid(-1, &status, 0);
		} else {
			// child code
			execve(command, NULL, 0);
			break;
		}
	}
}
// execute program in current dir
// take input as stdin (enter command)
// doesnt exist / cant run (ask again)
// only have to exit once
// child should break out of loop
// child needs to say its parent's pid and is own pid
