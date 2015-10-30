#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef char* String;

struct TokenizerT_ {
    String input;
    int currentindex;
    //int currenttypeindex;
};
typedef struct TokenizerT_ TokenizerT;


TokenizerT *TKCreate( String ts );
String word(TokenizerT *tk);
void TKDestroy( TokenizerT * tk );
void TKGetNextToken( TokenizerT *tk );
String Lower(String word);







#endif