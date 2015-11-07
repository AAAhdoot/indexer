#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

//typedef char* String;

FILE* word(FILE* fp);
String Lower(char* word);
void tokenization(char* pathname);






#endif
