#include "txtdtor.h"
#include <assert.h>
/*
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
*/
// text->alltext = (char*) calloc(text->sizetext+1, 1);
// text->line = (line*) calloc(text->numlines, sizeof(line*));
void txtDtor(text* text) {
    assert(text != nullptr);

    free(text->alltext);
    free(text->line);

    text->numlines = 0;
    text->sizetext = 0;
}
