#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> // Definition for fork() and execvp()
#include<sys/wait.h> // Definition for wait()

#define MAXLIST 100 // max number of commands


// function to separate command and its options (like -a) by separating when there is a space
void parseSpace(char* str, char** parsed)
{
    int i;
  
    for (i = 0; i < MAXLIST; i++) {
        parsed[i] = strsep(&str, " ");
  
        if (parsed[i] == NULL)
            break;
        if (strlen(parsed[i]) == 0)
            i--;
    }
}


int main(){
    char inputString[] = "pwd", *parsedArgs[MAXLIST];

    parseSpace(inputString, parsedArgs);


    // System Command execution starts here
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return 0;
    } else if (pid == 0) {
        if (execvp(parsedArgs[0], parsedArgs) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
    }

    return 0;
}