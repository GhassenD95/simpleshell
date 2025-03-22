#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> // For open()

#define MAX_INPUT 1024
#define MAX_ARGS 64

void execute_command(char **args) {
    // Handle commands
    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting the shell...\n");
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        // Handle cd command
        if (args[1] == NULL) {
            char *home = getenv("HOME");
            if (home == NULL) {
                fprintf(stderr, "cd: HOME environment variable not set\n");
            } else {
                if (chdir(home) != 0) {
                    perror("cd");
                }
            }
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd");
            }
        }
        return; 
    }else if(strcmp(args[0], "help") == 0){
    	printf("Available commands: \n"); 
    	//
    	printf("cd [dir] - change directory.\n"); 
    	printf("exit - exit shell.\n"); 
    	printf("ls - list files.\n"); 
    	printf("pwd - current directory.\n"); 
    }else{

	int input_redirect = 0; // <  
	int output_redirect = 0; // >
	int append_redirect = 0; // >>

	char* input_file = NULL; 
	char *output_file = NULL; 

    int saved_stdin = dup(STDIN_FILENO);
    int saved_stdout = dup(STDOUT_FILENO);

	for(int i = 0; args[i] != NULL; i++){
		if(strcmp(args[i], "<") == 0){
			input_redirect = 1; 
			input_file = args[i + 1]; 
			args[i] = NULL; 
		}else if(strcmp(args[i], ">") == 0){
			output_redirect = 1; 
			output_file = args[i + 1]; 
			args[i] = NULL; 
		}else if(strcmp(args[i], ">>") == 0){
			output_file = args[i + 1];
			append_redirect = 1; 
			args[i] = NULL; 
		}
	}

	if(input_redirect){
		int fd = open(input_file, O_RDONLY); 
		if(fd < 0){
			perror("open"); 
			return ; 
		}
		dup2(fd, STDIN_FILENO); 
		close(fd); 
	}

if (output_redirect || append_redirect) {
    
    int flags = O_WRONLY | O_CREAT;
    if (append_redirect) {
        flags |= O_APPEND;
    } else {
        flags |= O_TRUNC;
    }

    int fd = open(output_file, flags, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}
	
    	    // Handle external commands
    pid_t pid = fork();
    if (pid == 0) {
        // Child process: execute the command
        execvp(args[0], args);
        // If execvp fails
        perror("execvp");
        exit(1);
    } else if (pid > 0) {
        // Parent process: wait for the child to finish
        wait(NULL);
    } else {
        // Fork failed
        perror("fork");
    }

        dup2(saved_stdin, STDIN_FILENO);
        dup2(saved_stdout, STDOUT_FILENO);
        close(saved_stdin);
        close(saved_stdout);


    }

}

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    char *token;
    int i;

    while (1) {
        // Print the prompt
        printf("> ");

        // Read user input
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break; // Exit on EOF (Ctrl+D)
        }

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Tokenize the input
        i = 0;
        token = strtok(input, " ");
        while (token != NULL && i < MAX_ARGS - 1) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate the argument list

        // Execute the command if input is not empty
        if (i > 0) {
            execute_command(args);
        }

        // Reset i for the next command
        i = 0;
    }

    return 0;
}
