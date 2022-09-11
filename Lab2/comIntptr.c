#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h> // Definition for fork() and execvp()
#include<sys/wait.h> // Definition for wait()

#define MAXCOM 1000 // max no of letters
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

void execArgs(char** parsed)
{
    // Forking a child
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..");
        return;
    } else if (pid == 0) {
        if (execvp(parsed[0], parsed) < 0) {
            printf("\nCould not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}

int main(){
    char inputString[MAXCOM], *parsedArgs[MAXLIST];

    

    while(1){
        printf("\n $ ");
        scanf("%[^\n]s", inputString);

        if(strcmp(inputString, "") == 0)
            continue;

        parseSpace(inputString, parsedArgs);

        execArgs(parsedArgs);
    }

    

    return 0;
}