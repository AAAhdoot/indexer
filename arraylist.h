#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef char* word;

struct arraylist_{
  int size;
  int item_count;
  char** data;
};

typedef struct arraylist_ arraylist;


#endif
