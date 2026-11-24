#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/flags.h"
#include "../headers/config.h"
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


void writeContent();


