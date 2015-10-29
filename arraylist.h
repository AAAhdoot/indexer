#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef char* word;

struct arraylist_{
  int size;
  char** data;
};
typedef struct arraylist_ arraylist;


#endif
