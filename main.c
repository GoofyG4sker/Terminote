#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
  TRUE,
  FALSE
}state;

struct flags{

  state title;
  state message;

}flags;

//Function Declarations
void parseFlag(char flag);


int main(int argc , char *argv[]){

    if(argc>1){
      for(int i=1;i!=argc;i++){
        if(argv[i][0]=='-'){
          //Parse the flag]
          parseFlag(argv[i][1]);
        }else{
          //Throw Error
          fprintf(stderr,"Invalid Syntax");
          exit(0);
        }
      }
    }

    return 0;
}

void parseFlag(char flag){
    if(flag=='t'){
      flags.title = TRUE;
    }else if (flag=='m'){
      flags.message = TRUE;
    }else{
      fprintf(stderr,"Invalid Flag");
      exit(0);
    }

}


