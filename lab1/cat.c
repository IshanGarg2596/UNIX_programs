#include <stdio.h>
#include <sys/syscall.h>
#include <fcntl.h>

#define MAX_LIMIT 20

void printFile(char *fileName, int argc){
	
	int fd,i;
	char buf[2];

	fd=open(fileName,O_RDONLY,0777);
	
	if(fd==-argc)
	{
		printf("file open error");
	}
	else
	{
		while((i=read(fd,buf,1))>0)
		{
			printf("%c",buf[0]);
		}
		close(fd);
	}
}

int main( int argc,char *argv[3] )
{

	if(argc == 1){
		while(1){
			char str[MAX_LIMIT];
			scanf("%[^\n]%*c", str);
			printf("%s\n", str);
		}
	} else if(argc == 2){
		printFile(argv[1], argc);
	} else{
		int i = 1;
		while(i < argc){
			printFile(argv[i], argc);
			i++;
		}
	}

	return 0;
}
