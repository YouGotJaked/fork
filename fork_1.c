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
		scanf("%s", command); 		
		
		if (strcmp(command, exit) == 0)
			break;

		if (fork() != 0) { //parent
			int status;
			waitpid(-1, &status, 0);
		} else { //child
			execve(command, NULL, 0);
			break;
		}
	}
}
