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
void sorttext1(line* lines, size_t size);
/// @brief helping func for alphabetical sorting from end of line
/// @param lines arrive lines that we will sort
/// @param size number of lines
void sortreverse1(line* lines, size_t size);

/// @brief compare 2 string alphabetically
/// @param str1 first string for compare
/// @param str2 second string for compare
/// @return -1 if less, 0 if equal, 1 if more
int mystrcmp(const char* str1, const char* str2);
/// @brief compare 2 string alphabetically from end of line
/// @param line1 first string for compare
/// @param line2 second string for compare
/// @return -1 if less, 0 if equal, 1 if more
int strcmprev(const line line1, const line line2);

#endif
