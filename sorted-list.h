#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

typedef char* String;

typedef struct Occurrence{
  int freq;
  String filename;
 struct  Occurrence* next;
 }Occurrence;

typedef struct OccList{
  Occurrence* head;
}OccList;

/*void addToSL(EList* list, int index, const char* filename, int freq);

void printSL(EList list, int index);

void freeSL(EList list, int index);
*/

Occurrence* createOccurrence(String filename);

int compareOcc(Occurrence* occ1, Occurrence* occ2);

#endif
