#include "header/text.h"
#include "header/outtext.h"
#include "header/sort.h"
#include "header/txtdtor.h"
#include "header/readtext.h"

int main() {

    struct text txt;
    readtext(&txt, "txt/hamlet.txt");

    sorttext(&txt);
    outtext(&txt, "txt/outfile1.txt");

    sortreverse(&txt);
    outtext(&txt, "txt/outfile2.txt");

    outSRC(&txt, "txt/outfile3.txt");

    txtDtor(&txt);

}
