//There should be a sorted-list.h file here
#include "sorted-list.h"

//add first occurrence of word in a file


Occurrence* createOccurrence(char* filename){
  Occurrence* new = malloc(sizeof(Occurrence));
  new->filename = malloc((strlen(filename)+1)*sizeof(char));
  new->freq = 1;
  new->next=NULL;
  return new;
}

int OccCompare(String filename, int freq, Occurrence * occ){
  if(freq> occ->freq){
    return 1;
  }
  else if(freq<occ->freq){
    return -1;
  }
  else{
    if(strcoll(filename,occ->filename)<0){
      return -1;
    }
    else if(strcoll(filename,occ->filename)>0){
      return 1;
    }
    else{
      return 0;
    }
  }
}
int search(Occlist list, String filename){
  Occurrence* curr;
  curr= list->head;
  while(curr){
    if(strcmp(curr->filename,filename)==0){
      return curr->freq + 1
	}
  }
  return 0;
}


void addToSL(EList* list, int index, const char* filename){
  if(list->entrylist[index].word==NULL){
    printf("No word entry, returning\n");
    return;
  }
  if( (list->entrylist[index]).sl==NULL){
    // printf("SL is NULL so going to intialize one\n");
    (list->entrylist[index]).sl = malloc(1*sizeof(OccList));
    (list->entrylist[index]).sl->head=malloc(1*sizeof(Occurrence));
    (list->entrylist[index]).sl->head->freq = 1;
    (list->entrylist[index]).sl->head->filename = malloc((strlen(filename)+1)*sizeof(char));
    strcpy((list->entrylist[index]).sl->head->filename,filename);
  }
  else{
    Occurrence* temp = (list->entrylist[index]).sl->head;
    while(temp){
      if(temp->next==NULL){ 
	temp->next= malloc(1*sizeof(Occurrence));
	temp->next->freq=1;
	temp->next->filename = malloc((strlen(filename)+1)*sizeof(char));
	strcpy(temp->next->filename,filename);
	return;
      }
      temp=temp->next;
    }
  }
}

void printSL(EList list, int index){
  Occurrence* temp;
  if( (list.entrylist[index]).sl==NULL){
    printf("SL is empty, cannot print\n");
    return;
  }
  temp = (list.entrylist[index]).sl->head;
  printf("SL for [%d]\n",index);
  while(temp){
    printf("%s  %d\n",temp->filename,temp->freq);
    temp=temp->next;
  }
}

void freeSL(EList list, int index){
  //int i =0;                                                                                                       
  if(list.entrylist[index].sl==NULL){
    return;
  }
  Occurrence* curr = list.entrylist[index].sl->head;
  Occurrence* temp;
  while(curr){
    temp=curr->next;
    free(curr);
    printf("FreeSL\n");
    curr=temp;
  }
  free(list.entrylist[index].sl);
}
