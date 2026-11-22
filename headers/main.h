#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enter how many flags currently exsist in the program over here
#define FLAG_COUNT 2
#define OBSIDIAN_VAULT "Notes"


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


