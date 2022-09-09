#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
int main(int argc,char *argv[])
{
	if(argv[1][0] == '-'){
		argv[1] += 1;
		for (int i = 2; i < argc; i++)
		{	
			kill(atoi(argv[i]),atoi(argv[1]));
		}	
	} else{
		for (int i = 1; i < argc; i++)
		{
			kill(atoi(argv[i]),SIGKILL);
		}	
	}
	return 0;
}
