#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void countFile(char* arg, char op){
    FILE * file;
    char ch;
    int characters=0, words=0, lines=0;
    file = fopen(arg, "r");
    while ((ch = fgetc(file)) != EOF)
    {
	characters++;
	if (ch == '\n')
	    lines++;
	if (ch == ' ' || ch == '\n')
	    words++;
    }
    if (characters > 0)
    {
	words++;
	lines++;
    }
    
    if(op == 'w')
        printf("%d %s\n", words-1, arg);
    else if(op == 'c')
        printf("%d %s\n", characters, arg);
    else if(op == 'l')
        printf("%d %s\n", lines-1, arg);
    else
        printf("%d %d %d %s\n", lines-1,words-1,characters, arg);
    

    fclose(file);
}

int main(int c, char *argv[])
{   
    char op = '0';
    if(argv[1][0] == '-'){
        if(strcmp(argv[1],"-w") ==0 ){
            op = 'w';
        } else if(strcmp(argv[1],"-c") ==0){
            op = 'c';
        } else{
            op = 'l';
        }

        for (int i = 2; i < c; i++)
        {
            countFile(argv[i], op);
        }
        
        return 0;
    }

    for (int i = 1; i < c; i++)
    {
        countFile(argv[i], op);
    }

    return 0;
}
