#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	pid_t pid;
	int i;
	
	// Create a new process
	for (i=0; i<3; i++)
	{
		pid = fork(); // Create a new process (fork)
		
		if (pid == 0) {
			// Child process
			printf("PID = %d, Parent PID = %d\n", getpid(), getppid());
			sleep(1); // Wait
			exit(0); // Terminate child process
		}
		else if (pid < 0) {
			// Error handling if fork fails
			perror("fork failed"); // Handle fork failure
			exit(1);
		}
	}
	
	return 0;
}
