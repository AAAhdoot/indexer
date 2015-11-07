#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "arraylist.h"
//typedef char* String;

FILE* word(FILE* fp, EList* list, char* filename);
String Lower(char* word, EList* list, char* filename);
void tokenization(char* pathname, EList* list);






#endif
