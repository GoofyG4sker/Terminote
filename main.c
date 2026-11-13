#include <stdio.h>
#include <stdlib.h>

typedef enum{
  TRUE,
  FALSE
}state;

struct flags{

  state title = FALSE;
  state message = FALSE;

}flags;

//Function Declarations
// char parseFlag(char flag);


int main(int argc , char *argv[]){

    if(argc>1){
      for(int i=1;i!=argc;i++){
        if(argv[i][0]=='-'){
          //Parse the flag
        }else{
          //Throw Error
          fnprintf(stderr,"Invalid Syntax");
          exit(0);
        }
      }
    }

    return 0;
}

char parseFlag(char flag){
    if(strcmp(flag,'t')==0){
      flags.title = TRUE;
    }else if(strcmp(flag,'m')==0){
      flag.message = TRUE;
    }else{
      fnprintf(stderr,"Invalid Flag");
      exit(0);
    }

}


