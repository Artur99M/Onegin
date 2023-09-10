#include <stdio.h>
#include <stdbool.h>
#include "str.h"

int mystrlen (const char str[]) {
    int i = 0;
    while ( str [i] != '\0' ) {
        i++;
    }
    return i;
}
char* mystrchr(const char* str, const char ch) {
    int i = 0;
    while ( str[i] != '\0' && str[i] != ch) {
        i++;
    }
    if ( str[i] == ch ) {
        return (char*)str + i;
    } else {
        return NULL;
    }
}
void mystrcat ( char str1[], char str2[] ) {
    int len1 = 0;
    while ( str1 [len1] != '\0' ) {
        len1++;
    }
    int len2 = 0;
    while ( str2 [len2] != '\0' ) {
        len2++;
    }
    for ( int i = 0; i < len2; i++ ) {
        str1[len1+i] = str2[i];
    }
}
char* mystrstr ( const char str1[], const char str2[] ) {
    int len1 = 0;
    while ( str1 [len1] != '\0' ) {
        len1++;
    }
    int len2 = 0;
    while ( str2 [len2] != '\0' ) {
        len2++;
    }
    for ( int i = 0; i < len1 - len2; i++ ) {
        int n = 0;
        while ( str2[n] == str1 [i+n] ) {
            n++;
        }
        if ( n == len2 ) {
            return (char*)str1 + i;
        }
    return NULL;
    }
}
bool mystrcmp ( const char str1[], const char str2[] ) {
    if ( mystrlen(str1) != mystrlen(str2) ) {
        return false;
    }
    for ( int i = 0; str1[i]; i++) {
        if ( str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
bool mystrcmp ( const char str1[], const char str2[], const int n ) {
    if ( mystrlen(str1) < n || mystrlen(str2) < n ) {
        return false;
    }
    for ( int i = 0; i < n; i++) {
        if ( str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}
void mystrcpy ( char str1[], const char str2[] ) {
    int len1 = 0;
    while ( str1 [len1] != '\0' ) {
        len1++;
    }
    int len2 = 0;
    while ( str2 [len2] != '\0' ) {
        len2++;
    }
    for ( int i = 0; i < len1; i++) {
        str1[i] = str2 [i];
    }
}
void mystrncpy ( char str1[], const char str2[], int n ) {
    int len1 = 0;
    while ( str1 [len1] != '\0' ) {
        len1++;
    }
    int len2 = 0;
    while ( str2 [len2] != '\0' ) {
        len2++;
    }
    for ( int i = 0; i < n; i++) {
        str1[i] = str2 [i];
    }
}
