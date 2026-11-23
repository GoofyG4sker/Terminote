#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct flags{

  int eoFlag;
  flag order[FLAG_COUNT];
  char *content[FLAG_COUNT];

}flags;

//Function Declarations
void parseFlag(char *flag , int count);
int logFlags(int argc , char *argv[]);

