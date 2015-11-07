//There should be a sorted-list.h file here
#include "sorted-list.h"
#include "arraylist.h"
//add first occurrence of word in a file


int SLInsert(OccList* list, String filename, String directory){
  int compare;
  int find;
  Occurrence* curr, *previous, *addition;
  printf("INSERTING?\n");  
  previous = NULL;
  if (!list || !filename){//||!directory){
    printf("P0\n");
    return 0;
  }
  curr = list->head;
  /*empty list addition case*/
  addition = createOccurrence(filename,directory);
  if(!curr){
    printf("P1\n");
    list->head = addition;
    addition->next = NULL;
    return 1;
  }
  compare = OccCompare(addition,curr);
  /*head cases*/
  if(compare == 0){
    printf("P2\n");
    curr->freq++;
    free(addition);
    return 1;
  }
  if(compare > 0){
    printf("P3\n");
    addition->next = list->head;
    list->head = addition;
    return 1;
  }
  find = search(list,addition->filename);
  if(find>1){
    addition->freq=find;
  }
  /*standard case*/
  previous = curr;
  curr = curr->next; 
  while(curr!=NULL){
    compare = OccCompare(addition,curr);
    // if(compare==0){
    // return 0;
    // }
    if(compare>0){
      printf("P4\n");
      addition->next = curr;
      previous->next = addition;
      return 1;
    }
    previous=curr;
    curr=curr->next;
  }
  previous->next = addition;
  SLRemove(list,filename,addition->freq-1);
  //what if it fails on head case?
  printf("FAIL\n");
   return 1;
}

int SLRemove(OccList* list, String filename, int freq){
  Occurrence *curr, *prev;
  int compare;
  if(list == NULL || filename==NULL) return 0;
  if(list->head == NULL) return 0;
  curr = list->head;
  /*head is value to remove; increment the next's ref_count if not fully deleted*/
  compare = strcmp(curr->filename,filename);
  if(compare == 0 && curr->freq == freq){
    list->head = curr->next;
    free(curr);
    return 1;
  }
  prev = list->head;
  curr = list->head->next;
  /*examine other nodes for value to remove; If found, increment the next's ref_count if not fully deleted*/
  while(curr != NULL){
    compare = strcmp(curr->filename,filename);
    if(compare == 0 && curr->freq == freq){
      prev->next = curr->next;
      free(curr);
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }
  /* node not found */
  return 0;
}


Occurrence* createOccurrence(char* filename, String directory){
  Occurrence* new = malloc(sizeof(Occurrence));
  //new->filename = malloc((strlen(directory)+strlen(filename)+2)*sizeof(char));
  new->filename = malloc((strlen(filename)+1)*sizeof(char));
  // new->filename = strcat(directory, strcat("/",filename));
  new->filename=filename;
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
int search(OccList* list, String filename){
  Occurrence* curr;
  curr= list->head;
  while(curr){
    if(strcmp(curr->filename,filename)==0){
      return curr->freq + 1;
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
  printf("SL for [%d] = %s\n",index,list.entrylist[index].word);
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
