#include <stdio.h>
#include "header/outtext.h"
#include <stdlib.h>

void OUTTEXT(struct text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func outText\n"); printf(infoouttext); abort(); }

    FILE* out = fopen(file, "w");
    if (out == nullptr)
        { printf("Cannot open file in func outText()%s\n", file); printf(infoouttext);
        fclose(out); abort(); }

    for ( size_t i = 0; i < text->numlines; i++ )
        fprintf(out, "%s\n", text->line[i].str);

    fclose(out);
}

void OUTSRC(struct text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func outSRC\n"); printf(infooutSRC); abort(); }

    FILE* out = fopen(file, "w");
    if (out == nullptr)
        { printf("Cannot open file in func outSRC()%s\n", file); printf(infooutSRC);
        fclose(out); abort(); }//free

    for ( size_t i = 0; i < text->sizetext; i++)
        if (text->alltext[i] == '\0')
            text->alltext[i] = '\n';

    fputs(text->alltext, out);

    for (size_t i = 0; i < text->sizetext; i++)
        if (text->alltext[i] == '\n')
            text->alltext[i] = '\0';

    fclose(out);
}
