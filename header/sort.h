#include "text.h"
#ifndef SORT_H
#define SORT_H

/// @brief func for alphabetical sorting
/// @param text struct that we will sorting
void sorttext(struct text *text);
/// @brief func for sort alphabetically from end of line
/// @param text struct that we will sorting
void sortreverse(struct text *text);
/// @brief helping func for alphabetical sorting
/// @param lines arrive lines that we will sort
/// @param size number of lines
/// @param cmp func comparator
void sort(line* lines, size_t size, int(*cmp)(line, line));

/// @brief compare 2 string alphabetically
/// @param line1 first line for compare
/// @param line2 second line for compare
/// @return -1 if less, 0 if equal, 1 if more
int mystrcmp(line line1, line line2);
/// @brief compare 2 string alphabetically from end of line
/// @param line1 first string for compare
/// @param line2 second string for compare
/// @return -1 if less, 0 if equal, 1 if more
int strcmprev(const line line1, const line line2);
/// @brief helping func for alphabetical sorting
/// @param data arrive lines that we will sort
/// @param size number of lines
/// @param cmp func comparator
void Qsort (struct line* data, size_t size, int (*cmp)(line, line));
/// @brief func for swap elems in sort
/// @param a first elem for swap
/// @param b second elem for swap
void swap (line* a, line* b);
#endif
