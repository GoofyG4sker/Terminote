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
  char content[2][256];

}flags;

//Function Declarations
void parseFlag(char *flag , int count);
void writeContent();


int main(int argc , char *argv[]){



    if(argc>1){

      for(int i=1;i!=argc && argv[i][0]=='-'  ;i++){
               //Parse the flag]
           parseFlag(&argv[i][1] , i);
           flags.eoFlag = i;

      }

      state programRunning = TRUE;

      int argCount = flags.eoFlag + 1;

      for(int i = 1 ; programRunning != FALSE && i <=flags.eoFlag ; i++){
        switch(flags.order[i]){

          case TITLE:
             strcpy(flags.content[TITLE],argv[argCount]);
             printf(flags.content[TITLE]);
            break;

          case MESSAGE:
              strcpy(flags.content[MESSAGE],argv[argCount]);
              printf(flags.content[TITLE]);

            break;

          default:
            programRunning = FALSE;
        }
        argCount++;
      }

      writeContent();

    }else{
     //Throw Error
     fprintf(stderr,"Invalid Syntax");
     exit(0);
    }

    return 0;
}

void parseFlag(char *flag , int count){
  if(*flag=='t'){
    flags.order[count]=TITLE;
    printf("Flag Title Gotten \n");
    }else if (*flag=='m'){
    flags.order[count] = MESSAGE;
    printf("Flag Message Gotten \n");
    }else{
      fprintf(stderr,"Invalid Flag");
      exit(0);
    }

}

void writeContent(){

  // size_t strMemory= strlen(flags.content[TITLE]) + 4;
  char filename[128];

  snprintf(filename,sizeof(filename),"%s.MD",flags.content[TITLE]);

  FILE *note = fopen(filename,"w");

  // fprintf(note,flags.content[MESSAGE]);
  fputs(flags.content[MESSAGE],note);
  fclose(note);


}
