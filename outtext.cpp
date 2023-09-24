#include <stdio.h>
#include "outtext.h"
#include <stdlib.h>

void OUTTEXT(struct text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func outText\n"); printf(infoouttext); exit(1); }

    FILE* out = fopen(file, "w");
    if (out == nullptr)
        { printf("Cannot open file in func outText()%s\n", file); printf(infoouttext); exit(1); }

    //printf("          text = %p\n text->alltext = %p\n    text->line = %p\ntext->numlines = %p\ntext->sizetext = %p\n",
    //text, &(text->alltext), &(text->line), &(text->numlines), &(text->sizetext));
    //printf("\nchar* = %lu\nstruct line* = %lu\nsize_t = %lu\nsize_t = %lu\n",
    //sizeof(char*), sizeof(line*), sizeof(size_t), sizeof(size_t));

    for ( size_t i = 0; i < text->numlines; i++ )
        fputs(text->line[i].str, out);

    fclose(out);
}

void OUTSRC(struct text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func outSRC\n"); printf(infooutSRC); exit(1); }

    FILE* out = fopen(file, "w");
    if (out == nullptr)
        { printf("Cannot open file in func outSRC()%s\n", file); printf(infooutSRC); exit(1); }

    for ( size_t i = 0; i < text->sizetext; i++)
        if (text->alltext[i] == '\0')
            text->alltext[i] = '\n';

    fputs(text->alltext, out);

    for (size_t i = 0; i < text->sizetext; i++)
        if (text->alltext[i] == '\n')
            text->alltext[i] = '\0';

    fclose(out);
}
