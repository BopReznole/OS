#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int main(void) {
	pid_t pid;
	
	// Open the file in write mode
	FILE *fp = fopen("output.txt", "w+");
	if (fp == NULL) {
		perror("Error opening file");
		return EXIT_FAILURE;
	}
	
	// Fork to create a child process
	pid = fork();
	if (pid < 0) {
		perror("fork error");
		return 1;
	}

	if (pid == 0) { // Child process
		// Write some text to the file
		fprintf(fp, "Child process ID: %d.\n", getpid());

		printf("Child process ID written to output.txt sucessfully.\n");
	}
	else { // Parent process
		// Write some text to the file
		fprintf(fp, "Parent process ID: %d.\n", getpid());

		printf("Parent process ID written to output.txt sucessfully.\n");

		wait(NULL); // Wait for the child to finish
	}
	
	// Close the file
	if (fclose(fp) !=0) {
		perror("Error closing file");
		return EXIT_FAILURE;
	}
	
	return 0;
}

