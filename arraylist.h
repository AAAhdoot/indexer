#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef char* word;

typedef char* String;

typedef struct Occurrence{
   int freq;
   String filename;
 }Occurrence;

typedef struct OccList{
  Occurrence* head;
}OccList;

typedef struct Entry{
  OccList* list;
  char* word;
}Entry;

typedef struct EList{
  int size;
  int item_count;
  Entry** entrylist;
}EList;

typedef struct arraylist_{
  int size;
  int item_count;
  char** data;
}arraylist;

//typedef struct arraylist_ arraylist;

#endif
