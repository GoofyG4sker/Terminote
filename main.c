#include <stdio.h>






typedef enum{
  TRUE,
  FALSE
}state;

struct flags{

  state title = FALSE;
  state message = FALSE;

}flags;

//Function Declarations



int main(int argc , char *argv[]){

    if(argc>1){
      for(int i=1;i!=argc;i++){
        if(argv[i][0]=='-'){
          //Parse the flag
        }else{
          //Throw Error
          printf("Invalid Syntax");
          return(1);
        }
      }
    }

}

char parseFlag(char flag){
    if(strcmp(flag,'t')){
      flags.title = TRUE;
    }else if(strcmp(flag,'m')){
      flag.message = TRUE;
    }
}


