#include "text.h"

#ifndef OUTTEXT_H
#define OUTTEXT_H

#define outtext( txt, file ) OUTTEXT( txt, file, #txt, __LINE__, __FILE__ )
#define outSRC( txt, file ) OUTSRC( txt, file, #txt, __LINE__, __FILE__ )
#define infoouttext "func - outText(),\nstruct text - %s,\nfile for write - %s,\nnumber line in out file - %d,\nfile that used the func - %s,\n", textname, file, numline, outfile
#define infooutSRC "func - outSRC(),\nstruct text - %s,\nfile for write - %s,\nnumber line in out file - %d,\nfile that used the func - %s,\n", textname, file, numline, outfile

/// @brief printf text from sruct text to file
/// @param text struct text
/// @param file file where will be text
/// @param textname name struct
/// @param numline line where the func is applied
/// @param outfile file where the func is applied
void OUTTEXT(text* text, char* file, char* textname, int numline, char* outfile);
/// @brief printf original text from sruct text to file
/// @param text struct text
/// @param file file where will be text
/// @param textname name struct
/// @param numline line where the func is applied
/// @param outfile file where the func is applied
void OUTSRC(text* text, char* file, char* textname, int numline, char* outfile);


#endif
