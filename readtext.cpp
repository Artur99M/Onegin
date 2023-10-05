#include "header/readtext.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void READTEXT(text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func readtext\n"); printf(inforeadtext); abort(); }

    FILE* in = fopen(file, "r");
    if (in == nullptr)
        { printf("Cannot open file %s\n", file); printf(inforeadtext); abort(); }

    struct stat buff;
    stat(file, &buff);
    text->sizetext = (size_t) buff.st_size;

    text->alltext = (char*) calloc(text->sizetext+1, 1);
    if (text->alltext == nullptr)
        { printf("text->alltext == nullptr\n"); printf(inforeadtext); abort(); }

    if (fread(text->alltext, text->sizetext, 1, in) == 0)
        { printf("fread didn`t read all text\n"); printf(inforeadtext); fclose(in); abort(); }//free
    fclose(in);

    text->numlines = 1;
    for (size_t i = 0; i < text->sizetext; i++) {
        if (text->alltext[i] == '\n') {
            text->alltext[i] = '\0';
            text->numlines++;
        }
    }

    text->line = (line*) calloc(text->numlines, sizeof(line*));
    if (text->line == nullptr)
        { printf("text->line == nullptr\n"); printf(inforeadtext); abort(); }

    text->line[0].str = text->alltext;

    size_t num = 1, sizestr = 0;
    for (size_t j = 0; j < text->sizetext; j++) {
        if (text->alltext[j] == '\0') {
            text->line[num].str = text->alltext + j + 1;
            text->line[num-1].size = sizestr;
            sizestr = 0;
            num++;
        }
        sizestr++;
    }
    text->line[num-1].size = sizestr;
}
