//ArrayList structure for list of words and list of occurrences

#include "arraylist.h"
#include "sorted-list.h"

//initialize the list of entries i.e. our recorded words
void initList(EList* list){
  list=malloc(1*sizeof(EList));
  list->entrylist=NULL;
  list->item_count=-1;

}

//set the size of the list of entries
void setListSize(EList* list, int size){
  list->size = size; 
  list->item_count=0;
  list->entrylist = malloc(size*sizeof(Entry));
  
  int i=0;
  for(;i<list->size;i++){
    list->entrylist[i].word=NULL;
  }

}

//get a word/entry at a specific index
char* getListItem(EList list, int index){
  if(index<list.size){
    return (list.entrylist[index]).word;
  }
  else{
    printf("Error: Attempting to access array out-of-bounds\n");
    return NULL;
  }
}

//insert an item into the list
int insertListItem(EList* list, char* filename, char* word, char* directory){

  if(!filename){
    printf("Invalid Argument\n");
    return 0;
  }
  int len = strlen(word);
  
    int exists = existsInList(list,filename,word,directory);
  //Particular Case: new word that does not exist in the arraylist

  

//IF DOES NOT ALREADY EXIST IN LIST, make a word entry
  if(exists==0){
    /*if(list->item_count>=list->size){
      int new_size=(2*list->size)+1;
      printf("Out of bounds, call resize(list, %d)\n", new_size);
      resize(list,new_size);
      }*/

    (list->entrylist[ list->item_count ]).word=malloc((len+1)*sizeof(char*));

    strcpy((list->entrylist[ list->item_count ].word),word);

    (list->entrylist[ list->item_count]).sl = malloc(1*sizeof(OccList));
   
    (list->entrylist[ list->item_count]).sl->head=NULL; 
  
    SLInsert((list->entrylist[list->item_count]).sl, filename,directory);
          
    list->item_count++;
  }
  if(list->item_count>=list->size){
      int new_size=2*list->size;
      // printf("Out of bounds, call resize(list, %d)\n", new_size);
      resize(list,new_size);
    }
  
  return 1;

}

//look for a word in the list of words
int existsInList(EList* list, char* filename, char* word, char* directory){
  int i=0;
  for(; i < list->size; i++){
    if(list->entrylist[i].word!=NULL && strcmp(word,(list->entrylist[i]).word)==0){
      // printf("%s: Already in list! Adding to SL[%d]---%s\n",list->entrylist[i].word, i,filename);
       SLInsert(list->entrylist[i].sl,filename, directory);

      return 1;
    }
  }

  return 0;
}

//print the words in the list
void printList(EList list){
  int i= 0;
  if(list.entrylist==NULL){
    printf("No words in list\n");
    return;
  }
  while(i<list.size){
    if(list.entrylist[i].word!=NULL){
      printf("list.entrylist[%d].word: %s\n", i,(list.entrylist[i]).word);
    }
    i++;
  }
}

void resize(EList* list, int new_size){
  Entry* temp = realloc(list->entrylist,new_size*sizeof(Entry));
 
  if (temp==NULL){
    printf("ERROR: Out of memory\n");
    return ;
  }
  int j=list->size;

  list->size=new_size;
  list->entrylist=temp; 
}

/*
  void freeEL(EList list){
  int i = 0;
  for(;i<list.size;i++){
  if(list.entrylist[i]==NULL){
  printf("Done Freeing List\n");
  return;
  }
  printf("FREE [%d]\n",i);
  freeSL(list,i);
  free(&list);
  }
  
  }
*/

 

