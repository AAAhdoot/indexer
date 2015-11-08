#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

#include "arraylist.h"
//typedef char* String;

FILE* word(FILE* fp, EList* list, char* filename, char* currentdir);
String Lower(char* word, EList* list, char* filename, char* currentdir);
void tokenization(char* pathname, EList* list, char* currentdir);






#endif
