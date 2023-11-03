#include "header/sort.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

const int MORE = 1;
const int EQUAL = 0;
const int LESS = -1;

int mystrcmp(line line1, line line2) {

    for (int i = 0, j = 0; line1.str[i] != '\0' && line2.str[j] != '\0'; i++, j++) {

        for (; !isalpha(line1.str[i]) && line1.str[i]; i++);
        for (; !isalpha(line2.str[j]) && line2.str[j]; j++);

        if (line1.str[i] == line2.str[j] || line1.str[i] == '\0' || line2.str[j] == '\0') continue;

        return (line1.str[i] - line2.str[j]) / abs (line1.str[i] - line2.str[j]);
    }
    return EQUAL;
}

void sorttext(text* text) {

    assert(text != nullptr);
    Qsort(text->line, text->numlines, mystrcmp);
}

void sort(line* lines, size_t size, int(*cmp)(line, line)) {
    assert(lines != nullptr);

    int point = 0;
    for (int i = 0; i < size; i++)
        if (cmp(lines[i], lines[point]) == LESS) {
            point = i;
        }

    line change = lines[0];
    lines[0] = lines[point];
    lines[point] = change;

    if (size > 1) sort(lines+1, size-1, cmp);
}

void sortreverse(text* text){

    assert(text != nullptr);
    Qsort(text->line, text->numlines, strcmprev);

 }


int strcmprev(const line line1, const line line2) {

    for (int i = line1.size - 1, j = line2.size - 1; i > 0 && j > 0; i--, j--) {

        for (; !isalpha(line1.str[i]) && i > 0; i--);
        for (; !isalpha(line2.str[j]) && j > 0; j--);

        if (line1.str[i] == line2.str[j] || i == 0 || j == 0) continue;

        return (line1.str[i] - line2.str[j]) / abs (line1.str[i] - line2.str[j]);
    }
    return EQUAL;
}
void Qsort (line* data, size_t size, int (*cmp)(line, line))
{
    assert (data != nullptr);
    assert (cmp != nullptr);


    if (size == 2)
    {
        if (cmp(data[0], data[1]) > 0)
            swap (&data[0], &data[1]);
        return;
    }

    if (size == 2)
    {
        if (cmp (data[0], data[1]) > 0)
            swap (&data[0], &data[1]);
        return;
    }

    line pivot = data[time(NULL) % size];
    size_t i = 0, j = size - 1;
    while (i < j)
    {
        if (cmp (data[i], pivot) >= 0 && cmp (data[j], pivot) <= 0)
            swap (&data[i], &data[j]);

        if (cmp (data[i], pivot) <= 0) i++;
        if (cmp (data[j], pivot) >= 0) j--;

    }

    if (i > 1)
        Qsort (data, i, cmp);
    if (size - i > 1)
        Qsort (data + i, size - i, cmp);
}

void swap (line* a, line* b)
{
    assert (a != nullptr);
    assert (b != nullptr);

    line change = *a;
    *a = *b;
    *b = change;
}
