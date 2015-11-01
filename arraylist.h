#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//typedef char* word;

//typedef char* String;

typedef struct Occurrence{
  int freq;
  char* filename;
 struct  Occurrence* next;
 }Occurrence;

typedef struct OccList{
  Occurrence* head;
}OccList;

typedef struct Entry{
  OccList* sl;
  char* word;
}Entry;

typedef struct EList{
  int size;
  int item_count;
  Entry* entrylist;
}EList;


void initList(EList* list);

void setListSize(EList* list, int size);

char* getListItem(EList list, int index);

int insertListItem(EList* list, int index, char* word);

void searchList(EList list, char* word);

void printList(EList* list);

void resize(EList* list, int new_size);


#endif
