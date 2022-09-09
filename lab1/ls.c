#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void _ls(const char *dir,char op);


int main(int argc,char **argv){
    //printf("%s",argv[1]);
    if (argc == 1){
       _ls(".",'e');
    }
    else if(argc == 2){
        //printf("sd\n");
        if(strcmp( argv[1], "-R") == 0)
            _ls(".", 'R');
        else if(strcmp( argv[1], "-a") == 0 || strcmp( argv[1], "-l") == 0)
            _ls(".", argv[1][1]);
        else
            _ls(argv[1], 'e');
    } 
   exit(EXIT_SUCCESS);
}


void _ls(const char *dir,char op){
    struct dirent *d;
	DIR *dh = opendir(dir);
    if (!dh)
	{
		if (errno == ENOENT)
		{
			//If the directory is not found
			perror("Directory doesn't exist");
		}
		else
		{
			//If the directory is not readable then throw error and exit
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}

    if( op == 'R'){
        while ((d = readdir(dh)) != NULL){
            printf("%s\n",d->d_name);
       
            if(d->d_type==DT_DIR && ((strcmp(".",d->d_name)!=0) && (strcmp("..",d->d_name)!=0))){
                char path[100]={0};
                strcat(path,dir);
                strcat(path,"/");
                strcat(path,d->d_name);
                printf("sub directory of %s is\t",d->d_name);
                _ls(path,'R');
            }	
  	    } 
    } else{
        while ((d = readdir(dh)) != NULL)
	    {
		    //If hidden files are found we continue
		    if (!(op == 'a') && d->d_name[0] == '.')
			continue;
		    printf("%s  ", d->d_name);
		    if(op == 'l') printf("\n");
	    }
	    if(!(op == 'l'))
	    printf("\n");
    }
}
