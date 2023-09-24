#include "text.h"
#include "outtext.h"
#include "sort.h"
#include "txtdtor.h"
#include "readtext.h"

//void readtext( struct text* text, char* file, char* textname, int numline, char* outfile);
int main() {
    struct text* txt;
    readtext(txt, "hamlet.txt");
    sorttext(txt);
    outtext(txt, "outfile1.txt");
    sortreverse(txt);
    outtext(txt, "outfile2.txt");
    outSRC(txt, "outfile3.txt");
    sortSRC(txt);
    outtext(txt, "outfile4.txt");

    /*
    Onegin txt = {};
    int err = txtCtor(&txt);
    if (err) {... return 0;}
    readText(&txt, "input.file");
    sortTextDirect(&txt);
    outText(&txt, "outfile.txt");
    sortReverse(&txt);
    outText(&txt, "outfile2.txt");
    outSrc(&txt, "outfile3.txt");
    txtDtor(&txt);
    */
}
