#include "header/txtdtor.h"
#include <assert.h>

void txtDtor(text* text) {
    assert(text != nullptr);

    free(text->alltext);
    free(text->line);

    text->numlines = 0;
    text->sizetext = 0;
    text = nullptr;
}
