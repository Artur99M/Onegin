#include "readtext.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
/*
struct line {
    char* str;
    size_t size;
};
struct text {
    char* alltext;
    struct line *line;
    size_t sizetext;
    size_t numlines;
};
*/
//readtext ( txt, file, #txt, __LINE__, __FILE__, __func__ )
void READTEXT(text* text, char* file, char* textname, int numline, char* outfile) {

    if (text == nullptr)
        { printf("Not found struct text in func readtext\n"); printf(inforeadtext); exit(1); }
    FILE* in = fopen(file, "r");
    if (in == nullptr)
        { printf("Cannot open file %s\n", file); printf(inforeadtext); exit(1); }

    struct stat buff;
    stat(file, &buff);
    //printf("          text = %p\n text->alltext = %p\n    text->line = %p\ntext->numlines = %p\ntext->sizetext = %p\n",
    //text, &(text->alltext), &(text->line), &(text->numlines), &(text->sizetext));
    //printf("\nchar* = %lu\nstruct line* = %lu\nsize_t = %lu\nsize_t = %lu\n",
    //sizeof(char*), sizeof(line*), sizeof(size_t), sizeof(size_t));
    printf("%lld\n", buff.st_size);
    text->sizetext = (size_t) buff.st_size;
    puts("bark");

    text->alltext = (char*) calloc(text->sizetext+1, 1);
    if (text->alltext == nullptr)
        { printf("text->alltext == nullptr\n"); printf(inforeadtext); exit(1); }

    if (fread(text->alltext, text->sizetext, 1, in) < text->sizetext)
        { printf("fread didn`t read all text\n"); printf(inforeadtext); exit(1); }

    text->numlines = 1;
    size_t i = 0;
    while (i < text->sizetext) {
        if (text->alltext[i] == '\n') {
            text->alltext[i] = '\0';
            text->numlines++;
        }
    }

    text->line = (line*) calloc(text->numlines, sizeof(line*));
    if (text->line == nullptr)
        { printf("text->line == nullptr\n"); printf(inforeadtext); exit(1); }

    text->line[0].str = text->alltext; //first elem
    text->line[0].size = 0;
    for (size_t j = 0; text->line[0].str[j] != '\0'; text->line[0].size++);
    i = text->line[0].size + 1;

    for (size_t j = 1; j < text->sizetext; j++, i++) { //another elems
        text->line[j].str = text->alltext + i;
        text->line[j].size = 0;
        for (size_t q = i; text->line[j].size != '\0'; text->line[j].size++);
    }
    fclose(in);
}
