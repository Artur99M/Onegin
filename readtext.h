#include "text.h"

#ifndef READTEXT_H
#define READTEXT_H

#define readtext( txt, file ) READTEXT( txt, file, #txt, __LINE__, __FILE__ )
#define inforeadtext "func - readtext(),\nstruct text - %s,\nfile for read - %s,\nnumber line in out file - %d,\nfile that used the func - %s,\n", textname, file, numline, outfile
/// @brief read text from file and wtite to struct text
/// @param text struct into which the memory will be written
/// @param file file from where text will be read
/// @param textname name struct
/// @param numline line where the func is applied
/// @param outfile file where the func is applied
void READTEXT(text* text, char* file, char* textname, int numline, char* outfile);

#endif
