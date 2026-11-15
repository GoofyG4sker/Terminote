#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
  TRUE,
  FALSE
}state;

typedef enum{
  TITLE,
  MESSAGE
}flag;


struct flags{

  char *content[];
  int eoFlag;
  flag order[];
}flags;

//Function Declarations
void parseFlag(char flag , int count);
void saveContent(char *content[]);

int main(int argc , char *argv[]){



    if(argc>1){

      for(int i=1;i!=argc;i++){
        if(argv[i][0]=='-'){
               //Parse the flag]
           parseFlag(argv[i][1] , i);
           flags.eoFlag = i;
        }else{

        }


      }




    }else{
     //Throw Error
     fprintf(stderr,"Invalid Syntax");
     exit(0);
    }

    return 0;
}

void parseFlag(char flag , int count){
  if(flag=='t'){
    flags.order[count]=TITLE;
    }else if (flag=='m'){
      flags.order[count] = MESSAGE;
    }else{
      fprintf(stderr,"Invalid Flag");
      exit(0);
    }

}

void saveContent(char *content[]){






}

