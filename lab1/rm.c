#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
int main(int argc, char *argv[])
{
    
    if(strcmp( argv[1], "-i") == 0){

        int i = 2;
        while(i < argc){
            printf("remove %s?", argv[i]);
            char ans[3];
            scanf("%[^\n]%*c", ans);
            if(ans[0] == 'y'){
                remove(argv[i]);
                i++;
            }
            else{
                i++;
                continue;
            }
        }
        
    } else{
        int i = 1;
        while(i < argc){
            remove(argv[i]);
            i++;
        }
    }   

    return 0;
      
}
