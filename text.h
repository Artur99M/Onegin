#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
struct line {
    char* str;
    size_t size;
};
struct text {
    char* alltext;
    line* line;
    size_t sizetext;
    size_t numlines;
};
#endif
