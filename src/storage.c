#include "../headers/storage.h"



void writeContent(){

  size_t titleMemory= strlen(flags.content[TITLE]) + 4 + strlen(OBSIDIAN_VAULT) ; //4 bytes for .MD \0 and 128 for TerminalNote
  char *filename = malloc(titleMemory);

  snprintf(filename,titleMemory,"%s/%s.MD",OBSIDIAN_VAULT,flags.content[TITLE]);

  FILE *note = fopen(filename,"w");

  // fprintf(note,flags.content[MESSAGE]);
  fputs(flags.content[MESSAGE],note);
  fclose(note);
  free(filename);

}

