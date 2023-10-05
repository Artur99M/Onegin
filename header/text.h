#ifndef TEXT_H
#define TEXT_H
#include <stdio.h>
/// @brief struct for line from text
struct line {
    char* str;
    size_t size;
};
/// @brief struct for text
struct text {
    char* alltext;
    line* line;
    size_t sizetext;
    size_t numlines;
};
#endif
