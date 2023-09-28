#include "sort.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

const int more = 1;
const int equal = 0;
const int less = -1;
const char string[] = "qwertyuiopasdfhjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

int mystrcmp(const char* str1, const char* str2) {
    assert(str1 != nullptr);
    assert(str2 != nullptr);

    for (int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; i++, j++) {

        for (; strchr(string, str1[i]) == nullptr && str1[i]; i++);
        for (; strchr(string, str2[j]) == nullptr && str2[j]; j++);

        if (str1[i] == str2[j] || str1[i] == '\0' || str2[j] == '\0') continue;

        return (str1[i] - str2[j]) / abs (str1[i] - str2[j]);
    }
    return equal;
}

void sorttext(text* text) {

    assert(text != nullptr);
    sorttext1(text->line, text->numlines);
}

void sorttext1(line* lines, size_t size) {
    assert(lines != nullptr);

    int point = 0;
    for (int i = 0; i < size; i++)
        if (mystrcmp(lines[i].str, lines[point].str) == less) {
            point = i;
        }

    line change = lines[0];
    lines[0] = lines[point];
    lines[point] = change;

    if (size > 1) sorttext1(lines+1, size-1);
}

void sortreverse(text* text){

    assert(text != nullptr);
    sortreverse1(text->line, text->numlines);

 }

void sortreverse1(line* lines, size_t size) {
    assert(lines != nullptr);

    int point = 0;
    for (int i = 0; i < size; i++)
        if (strcmprev(lines[i], lines[point]) == less) {
            point = i;
        }
    line change = lines[0];
    lines[0] = lines[point];
    lines[point] = change;

    if (size > 1) sortreverse1(lines+1, size-1);
}

int strcmprev(const line line1, const line line2) {

    for (int i = line1.size - 1, j = line2.size - 1; i > 0 && j > 0; i--, j--) {

        for (; strchr(string, line1.str[i]) == nullptr && i > 0; i--);
        for (; strchr(string, line2.str[j]) == nullptr && j > 0; j--);

        if (line1.str[i] == line2.str[j] || i == 0 || j == 0) continue;

        return (line1.str[i] - line2.str[j]) / abs (line1.str[i] - line2.str[j]);
    }
    return equal;
}

/*
void sortSRC(struct text *text){
    assert(text != nullptr);

    for (size_t i = 0;; i++) {

        size_t count0 = 0;
        char str[MAXLINE] = "";
        for (size_t j = 0, s = 0; j < text->sizetext; j++) {
            if (text->alltext[j] == '\0') count0++;
            if (count0 == i) {
                str[s] = text->alltext[j];
                s++;
            }
            if (count0 > i) break;
        }

        size_t j = 0;
        while (mystrcmp(str, text->line[j].str) != equal) j++;

        line change = text->line[j];
        text->line[j] = text->line[i];
        text->line[i] = change;
    }
}
*/
