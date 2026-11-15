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

  int eoFlag;
  flag order[5];
  char content[][256];

}flags;

//Function Declarations
void parseFlag(char flag , int count);
void writeContent();


int main(int argc , char *argv[]){



    if(argc>1){

      for(int i=1;i!=argv && argv[i][0]=='-'  ;i++){
               //Parse the flag]
           parseFlag(argv[i][1] , i);
           flags.eoFlag = i+1;

      }

      state programRunning = TRUE;

      while(programRunning != FALSE){
        switch(flags.order[flags.eoFlag]){

          case TITLE:
             strcpy(flags.content[TITLE],argv[flags.eoFlag]);
            break;

          case MESSAGE:
              strcpy(flags.content[MESSAGE],argv[flags.eoFlag]) ;
            break;

          default:
            programRunning = FALSE;
        }
        flags.eoFlag++;
      }

      writeContent();

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

void writeContent(){

  char filename = strcat(flags.content,".MD");
  FILE *note = fopen(filename,"w");

  snprintf(note,sizeof(flags.content[MESSAGE]),flags.content[MESSAGE]);

  fclose(note);


}
