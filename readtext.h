#include "text.h"

#ifndef READTEXT_H
#define READTEXT_H

#define readtext( txt, file ) READTEXT( txt, file, #txt, __LINE__, __FILE__ )
#define inforeadtext "func - readtext(),\nstruct text - %s,\nfile for read - %s,\nnumber line in out file - %d,\nfile that used the func - %s,\n", textname, file, numline, outfile

void READTEXT(text* text, char* file, char* textname, int numline, char* outfile);

#endif
