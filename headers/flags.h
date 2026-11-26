#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/global.h"
#define FLAG_COUNT 2




struct flags{

  int eoFlag;
  flag order[FLAG_COUNT];
  char *content[FLAG_COUNT];

};

extern struct flags flags;


//Function Declarations
void parseFlag(char *flag , int count);
int logFlags(int argc , char *argv[]);

