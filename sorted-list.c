//There should be a sorted-list.h file here
#include "sorted-list.h"
#include "arraylist.h"
//add first occurrence of word in a file
#include <string.h>

int SLInsert(OccList* list, String filename, String directory){
  int compare;
  int find;
  Occurrence* curr, *previous, *addition, *bruh;

  previous = NULL;
  if (!list || !filename){//||!directory){
    printf("P0\n");
    return 0;
  }
  curr = list->head;
  /*empty list addition case*/
  addition = createOccurrence(filename,directory);
  //  printf("addition->filename is %s\n",addition->filename );
  if(!curr){
    //printf("P1 HEAD IS NULL--CREATE HEAD\n");
    list->head = addition;
    addition->next = NULL;
    /* bruh = list->head;
    printf("printing SL after addition to empty list\n");
    while(bruh){
      printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
      bruh=bruh->next;
    }
    */
    return 1;
  }
  find = search(list,addition->filename);

  if(find>1){
    addition->freq=find;
  }
  compare = OccCompare(addition,curr);
  //printf("addition->freq is %d and curr->freq is %d\n",addition->freq,curr->freq );
  /*head cases*/
  if(compare == 0){
    //printf("%s from addition is the same as %s from curr\n",addition->filename,curr->filename);
    curr->freq++;
    free(addition);
    /*bruh = list->head;
    printf("printing SL after simple incrementation\n");
    while(bruh){
      printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
      bruh=bruh->next;
    }
    */
    return 1;
  }
  if(compare > 0){
    //printf("%s from addition is greater than %s from curr\n",addition->filename,curr->filename);
    addition->next = list->head;
    list->head = addition;
    /*bruh = list->head;
    printf("printing SL after addition in front of list and pre removal \n");
    while(bruh){
      printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
      bruh=bruh->next;
      }*/
    SLRemove(list,addition->filename,addition->freq-1);
    /*bruh = list->head;
    printf("printing SL after addition in front of list with and post removal\n");
    while(bruh){
      printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
      bruh=bruh->next;
      }
    */
    return 1;
  }

  // find = search(list,addition->filename);

  // if(find>1){
  //   addition->freq=find;
  // }
  /*standard case*/
  previous = curr;
  curr = curr->next; 
  while(curr!=NULL){
    compare = OccCompare(addition,curr);
    // if(compare==0){
    // return 0;
    // }
    if(compare>0){
      //  printf("P4\n");
      addition->next = curr;
      previous->next = addition;
      /*printf("addition->freq is currently %d\n",addition->freq);
      bruh = list->head;
      printf("printing SL BEFORE removal\n");
      while(bruh){
        printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
        bruh=bruh->next;
      }
      */
      SLRemove(list,addition->filename,addition->freq-1);
      /*bruh = list->head;
      printf("printing SL after removal\n");
      while(bruh){
        printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
        bruh=bruh->next;
      }
      */


      return 1;
    }
    previous=curr;
    curr=curr->next;
  }
  previous->next = addition;
  /*  bruh = list->head;
  printf("printing SL BEFORE removal\n");
  while(bruh){
    printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
    bruh=bruh->next;
  }
  */
  SLRemove(list,addition->filename,addition->freq-1);
  /*bruh = list->head;
  printf("printing SL after removal\n");
  while(bruh){
    printf("filename is %s and freq is %d\n",bruh->filename,bruh->freq);
    bruh=bruh->next;
  }
  */
  //what if it fails on head case?
  
  return 1;
}
int SLRemove(OccList* list, String filename, int freq){
  Occurrence *curr, *prev;
  int compare;
  if(list == NULL || filename==NULL) return 0;
  if(list->head == NULL) return 0;
  curr = list->head;
  // printf("filename is %s with a freq %d\n",filename,freq);
  /*head is value to remove; increment the next's ref_count if not fully deleted*/
  // printf("head->filename is %s and head->freq is %d\n",curr->filename,curr->freq );
  compare = strcmp(curr->filename,filename);
  if(compare == 0 && curr->freq == freq){
    //printf("REMOVE HEAD\n");
    list->head = curr->next;
    free(curr);
    return 1;
  }
  prev = list->head;
  curr = list->head->next;
  /*examine other nodes for value to remove; If found, increment the next's ref_count if not fully deleted*/
  while(curr != NULL){
    // printf("curr->filename is %s and curr->freq is %d\n",curr->filename,curr->freq );
    compare = strcmp(curr->filename,filename);
    if(compare == 0 && curr->freq == freq){
      prev->next = curr->next;
      free(curr);
      //printf("NOT HEAD, BUT FOUND AND REMOVED\n");
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }
  /* node not found */
  //printf("FAILED TO REMOVE\n");
  return 0;
}


Occurrence* createOccurrence(String filename, String directory){
  //printf("CREATE: %s\n", filename);
  Occurrence* new = malloc(sizeof(Occurrence));
  if(!directory){
    //printf("directory is NULL\n");
    new->filename = malloc((strlen(filename)+1)*sizeof(char));
    new->filename=filename;
  }
  else{
    // printf("directory is %s\n",directory);
    new->filename = malloc((strlen(directory)+strlen(filename)+2)*sizeof(char));
    strcpy(new->filename,directory);
    //if(new->filename == NULL) printf("WTF again\n");
    strcat(new->filename, "/");
    //printf("new->filename is now %s\n",new->filename );
    strcat(new->filename,filename);
    // new->filename = strcat(new->filename,filename);
  }
  //new->filename = malloc((strlen(directory)+strlen(filename)+2)*sizeof(char));
  // new->filename = strcat(directory, strcat("/",filename));
  new->freq = 1;
  new->next=NULL;
  return new;
}

int OccCompare(Occurrence * first, Occurrence * second){
  if(first->freq > second->freq){
    return 1;
  }
  else if(first->freq < second->freq){
    return -1;
  }
  else{
    if(strcmp(first->filename,second->filename)<0){
      return 1;
    }
    else if(strcmp(first->filename,second->filename)>0){
      return -1;
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
    curr=curr->next;
  }
  return 0;
}

void printSL(EList list, int index){
  Occurrence* temp;
  if( (list.entrylist[index]).sl==NULL){
    printf("SL is empty, cannot print\n");
    return;
  }
  // temp = (list.entrylist[index]).sl->head;
  int i =0;
  for(;i<list.item_count;i++){
    temp = (list.entrylist[i]).sl->head;
    printf("SL for [%d] = %s\n",i,list.entrylist[i].word);
    while(temp && temp->filename){
      printf("temp: %s  %d\n",temp->filename,temp->freq);
      temp=temp->next;
    }
      
  }
  /*  printf("SL for [%d] = %s\n",index,list.entrylist[index].word);
  while(temp && temp->filename){
    printf("%s  %d\n",temp->filename,temp->freq);
    temp=temp->next;
  }
  */
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
    //printf("FreeSL\n");
    curr=temp;
  }
  free(list.entrylist[index].sl);
}
