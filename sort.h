#include "text.h"
#ifndef SORT_H
#define SORT_H

void sorttext(struct text *text);
void sortreverse(struct text *text);
void sortSRC(struct text *text);
void sorttext1(line* lines, size_t size);
void sortreverse1(line* lines, size_t size);

int mystrcmp(const char* str1, const char* str2);// нужно сделать указатель на функцию,
int strcmprev(const line line1, const line line2);// так как они одинаковые за исключение этого момента

#endif
