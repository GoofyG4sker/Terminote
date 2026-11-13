#include <stdio.h>

typedef enum state{
  TRUE,
  FALSE
}

struct flags{

  state title;
  state message;

}flags;


int main(int argc , char *argv[]){

    if(argc>1){
      for(int i=1;i!=argc;i++){
        if(argv[i][0]=='-'){
          //Parse the flag
        }else{
          //Throw Error
          printf("Invalid Syntax");
          exit();
        }
      }
    }

}
