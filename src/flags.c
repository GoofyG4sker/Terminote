#include "../headers/flags.h"


int logFlags(int argc , char *argv[]){



    if(argc>1){

      for(int i=1;i!=argc && argv[i][0]=='-'  ;i++){
               //Parse the flag]
           parseFlag(&argv[i][1] , i);
           flags.eoFlag = i;

      }

      state programRunning = TRUE;



      for(int i = 1,argCount = flags.eoFlag + 1 ; programRunning != FALSE && i <=flags.eoFlag ; i++,argCount++){
        switch(flags.order[i]){

          case TITLE:
            //  strcpy(flags.content[TITLE],argv[argCount]);

            flags.content[TITLE] = argv[argCount];
            printf(flags.content[TITLE]);

            break;

          case MESSAGE:
              // strcpy(flags.content[MESSAGE],argv[argCount]);
              flags.content[MESSAGE] = argv[argCount];
              printf(flags.content[MESSAGE]);

            break;

          default:
            programRunning = FALSE;
        }
      }


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


