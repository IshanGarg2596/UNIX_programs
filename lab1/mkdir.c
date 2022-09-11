#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char* argv[]){


if(argc!=2 || strcmp(argv[1], "--help") == 0)
  {
    printf("\nusage: mkdir creates a directory\n");
    return 0;
   // break;
  }
  char *cmd = "mkdir";
  char *args[3];
  args[0] = "mkdir";
  args[1] = argv[1];
  args[2] = NULL;

  execvp(cmd, argv);

  return 0;
}
