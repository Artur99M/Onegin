#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>

void data3 ( size_t numstr, char* * data, FILE* in );
void data1 ( size_t length, size_t numstr, char  data[][length], FILE* in );
char* data2 ( FILE* in, int numstr );
char** data4 ( FILE* in, size_t numstrs );
char** text5 ( FILE* in );
void strclean ( char * str );

int main() {
    FILE* in = fopen ( "tes1.txt", "r" ); //+
    char** p = data4(in, 8);
    fclose(in);
    puts ( p[0] );
}

void data3 ( size_t numstr, char** data, FILE* in ) {
    assert ( data != nullptr );
    assert ( in != nullptr );

    for ( int i = 0; i < numstr; i++ ) {
        char str [200] = "";
        int lenstr = 0; //+
        while ( (str[lenstr] = getc(in)) != '\n' ) lenstr++;
        data[i] = (char*) calloc ( lenstr+1, sizeof(char) );    //+
        for ( int j = 0; j < lenstr; j++)
            *( data[i] + j ) = str[j];
    }
}
void data1 ( size_t length, size_t numstr, char  data [][length], FILE* in ) {
    assert ( data != nullptr );
    assert ( in != nullptr );
    for ( size_t i = 0; i < numstr; i++ ) {
        char s = '\0';
        for ( size_t j = 0; ( s = getc(in) ) != '\n'; j++ ) data[i][j] = s;
    }
}
char* data2 ( FILE* in, int numstr ) {
    assert ( in != nullptr );
    char str[1000] = "";
    int q = 0;
    for ( int i = 0; q < numstr; i++ ) {
        str[i] = getc(in);
        if ( str[i] == '\n' ) {
            q++;
        }
    }
    char* p = (char*) calloc ( strlen(str), sizeof(char) );   //+
    if (p != nullptr) { //+
        for ( int i = 0; i < strlen(str); i++ ) *( p + i ) = str[i];
        return p;
    } else {
        return nullptr;
    }
}

char** data4 ( FILE* in, size_t numstrs ) {
    assert ( in );
    char str[5000] = "";
    int pstrs[100] = {};
    int len = 0, nn = 1;

    while ( nn < numstrs ) {
        char s = getc(in) ;
        if ( s == '\n' ) {
            pstrs[nn] = len+1;
            nn++;
            s = '\0';
        }
        str[len] = s;
        len++;
    }

    char* pstr = nullptr;
    char** p = nullptr;
    if ( (pstr = (char*) calloc ( len, sizeof(char) )) != nullptr &&
           (p = (char**) calloc (nn, sizeof(char*) )) != nullptr ) {
        for ( int i = 0; i < numstrs; i++ ) {
            strcpy (pstr+pstrs[i], str + pstrs[i]);
            p[i] = pstr + pstrs[i];
        }
    } else {
        return nullptr;
    }
    return p;
}

char** text5 ( FILE* in ) {
    assert ( in );
    struct stat buff;
    stat ( "Onegin.txt", &buff );
    size_t size = buff.st_size;

    char* pstr = (char*) calloc ( size+1, 1 );
    char** p = (char**) calloc ( (size + 1 - (size+1) % 300) / 300, sizeof(char*) );
    char str[300] = "";

    for ( int i = 0; fgets( str, 300, in ); i++ ) {
        p[i] = strcpy ( pstr, str );
        pstr += strlen(str)+1;
        *( pstr - 2) = '\0';
        strclean (str);
    }
    return p;
}

void strclean ( char * str ) {
    for ( int i = 0; str[i] != '\0'; i++ ) str[i] = '\0';
}
