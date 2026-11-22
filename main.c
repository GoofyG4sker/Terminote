#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enter how many flags currently exsist in the program over here
#define FLAG_COUNT 2
#define OBSIDIAN_VAULT "Hailo"


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
  flag order[FLAG_COUNT];
  char *content[FLAG_COUNT];

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

  size_t titleMemory= strlen(flags.content[TITLE]) + 4 + 16 ; //4 bytes for .MD \0 and 12 for TerminalNote
  char *filename = malloc(titleMemory);

  snprintf(filename,titleMemory,"%s/%s.MD",OBSIDIAN_VAULT,flags.content[TITLE]);

  FILE *note = fopen(filename,"w");

  // fprintf(note,flags.content[MESSAGE]);
  fputs(flags.content[MESSAGE],note);
  fclose(note);
  free(filename);

}
