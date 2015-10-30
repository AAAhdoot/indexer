//ArrayList structure for list of words and list of occurrences

#include "arraylist.h"

//initialize the list of entries i.e. our recorded words
void initList(EList* list){
  list->size =0;
  list->entrylist = NULL;
  list->item_count=0;
}

//set the size of the list of entries
void setListSize(EList* list, int size){
  list->size = size; 
  list->entrylist=malloc(size*sizeof(Entry*));
}

//get a word/entry at a specific index
char* getListItem(EList* list, int index){
  if(index<list->size){
    return (list->entrylist[index])->word;
  }
  else{
    printf("Error: Attempting to access array out-of-bounds\n");
    return NULL;
  }
}

//insert an item into the list at a specific index
int insertListItem(EList list, int index, char* word){
  if(index<list.size){
    int len = strlen(word);
    list.entrylist[index]=malloc(1*sizeof(Entry));

    (list.entrylist[index])->word=malloc((len+1)*sizeof(char*));

    strcpy((list.entrylist[index]->word),word);
    return 1;
  }
  else{
    printf("Failed insert: Array out of bounds\n");
    return 0;
  }
}

//look for a word in the list of words
void searchList(EList* list, char* word){
  printf("search for: %s\n",word);
  int i=0;
  for(; i < list->size; i++){
    //only run strcmp on non-NULL entries or else segfaults
    if(list->entrylist[i]!=NULL && strcmp(word,(list->entrylist[i])->word)==0){
      printf("Already in list!\n");
      return;
    }
  }
  printf("Not in list\n");
  return;
}

//print the words in the list
void printList(EList* list){
  int i= 0;
  if(list->entrylist==NULL){
    printf("No words in list\n");
    return;
  }
  while(list->entrylist[i]!=NULL){
    printf("list->entrylist[%d]->word: %s\n", i,(list->entrylist[i])->word);
    i++;
  }
}


//Sorted List Functions

void addToSL(EList list, int index, const char* filename, int freq){
  if( (list.entrylist[index])->sl==NULL){
    printf("SL is NULL so going to intialize one\n");
    (list.entrylist[index])->sl = malloc(1*sizeof(OccList));
    (list.entrylist[index])->sl->head=malloc(1*sizeof(Occurrence));
    (list.entrylist[index])->sl->head->freq = freq;
  }
  else{
    Occurrence* temp = (list.entrylist[index])->sl->head;
    while(temp){
      if(temp->next==NULL){
	//printf("Next is NULL, adding to end\n");
	temp->next= malloc(1*sizeof(Occurrence));
	temp->next->freq=freq;
	return;
      }
      temp=temp->next;
    }
  }
}

void printSL(EList* list, int index){
  Occurrence* temp;
  if( (list->entrylist[index])->sl==NULL){
    printf("SL is empty, cannot print\n");
    return;
  }
  temp = (list->entrylist[index])->sl->head;
  printf("SL for [%d]\n",index);
  while(temp){
    printf("freq: %d\n",temp->freq);
    temp=temp->next;
  }
}

void freeSL(EList list, int index){
  //int i =0;
  if(list.entrylist[index]->sl==NULL){
    return;
  }
  Occurrence* curr = list.entrylist[index]->sl->head;
  Occurrence* temp;
  while(curr){
    temp=curr->next;
    free(curr);
    printf("FreeSL\n");
    curr=temp;
  }
  free(list.entrylist[index]->sl);
}
void freeEL(EList list){
  int i = 0;
  for(;i<list.size;i++){
    if(list.entrylist[i]==NULL){
      printf("Done Freeing List\n");
      return;
    }
    printf("FREE [%d]\n",i);
    freeSL(list,i);
    free(list.entrylist[i]);
  }
  
}

int main(int argc, char** argv){
  EList list;
  char* word = "ADELE";
  char* hello= "hello";
  int entry_count=0;
  initList(&list);
  //  char* word = argv[1];

  setListSize(&list,10);
  printf("list->size:%d\n", list.size);
  insertListItem(list,0,hello);

  entry_count=1;
  while(entry_count<list.size){
    insertListItem(list,entry_count,word);
    entry_count++;
    if(entry_count==list.size){
      printf("MAX CAPACITY\n");
    }
  }
  list.item_count = entry_count;
  printf("item_count: %d\n", list.item_count);
  
  insertListItem(list,10,"rain");
  
  searchList(&list,"Word");
  
  printList(&list);
  
  char* c = getListItem(&list,0);
  printf("c: %s\n", c);
  addToSL(list,0,"file1",7);
  addToSL(list,0,"file2",3);
  addToSL(list,0,"file3",5);
  addToSL(list,1,"file4",8);
  printSL(&list,1);
  printSL(&list,0);
  freeEL(list);
  return 0;
}
