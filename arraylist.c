//ArrayList structure for list of words and list of occurrences

#include "arraylist.h"
#include "sorted-list.c"

//initialize the list of entries i.e. our recorded words
void initList(EList* list){
  list=malloc(1*sizeof(EList));
  printf("initsize: %d\n", list->size);
  list->entrylist=NULL;
  list->item_count=-1;

}

//set the size of the list of entries
void setListSize(EList* list, int size){
  list->size = size; 
  list->item_count=0;
  list->entrylist = malloc(size*sizeof(Entry));
  //list->entrylist=e;
  printf("set size: %d\n", list->size);
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
int insertListItem(EList* list, char* filename, char* word){
  int len = strlen(word);
  printf("%d  %d\n", list->item_count, list->size); 
  if(list->item_count>=list->size){
    int new_size=(2*list->size)+1;
    printf("Out of bounds, call resize(list, %d)\n", new_size);
    resize(list,new_size);
  }

  (list->entrylist[ list->item_count ]).word=malloc((len+1)*sizeof(char*));

  strcpy((list->entrylist[ list->item_count ].word),word);
  list->item_count++;
  return 1;

}

//look for a word in the list of words
int existsInList(EList list, char* word){
  printf("search for: %s\n",word);
  int i=0;
  for(; i < list.size; i++){
    if(list.entrylist[i].word!=NULL && strcmp(word,(list.entrylist[i]).word)==0){
      printf("Already in list! Adding to SL[%d]\n", i);
      // addToSL(list, i, filename);
      return 1;
    }
  }
  printf("Not in list\n");
 
  return 0;
}

//print the words in the list
void printList(EList list){
  printf("Printing...\n");
  // printf("address in print: %p  %p\n", list, list.entrylist);
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
  printf("Resizing to ... %d\n", new_size);
  Entry* temp = realloc(list->entrylist,new_size*sizeof(Entry));
 
  if (temp==NULL){
    printf("ERROR: CAN'T RESIZE, EATING SHIT\n");
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

 
 
//This works?
/*  EList list;
    setListSize(&list,10);
    printf("%d\n",list.size);
    resize(&list,30);
    printf("%d\n",list.size);
*/

