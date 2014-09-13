#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void execute(char **args)
{
        args++; /* args need to move onto the correct binary */
        pid_t child_pid;
        int status;

        child_pid = fork();
        if (child_pid < 0) {
                fprintf(stderr, "Forking a child process failed!\n");
                exit(1);
        } else if (child_pid == 0) { /* this is what the child process will see as its pid */
                if (execvp(*args, args) < 0) {
                        fprintf(stderr, "executing %s failed!\n", *args);
                        exit(1);
                }
        } else { /* parent process will get the correct pid for the child process */
                while (wait(&status) != child_pid);
        }
}                         

int main(int argc, char **argv)
{
        int i;
        
        //char *args[2] = {"/bin/ls", "/"};
        execute(argv);

        return 0;
}

