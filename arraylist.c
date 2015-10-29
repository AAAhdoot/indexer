//ArrayList structure for list of words and list of occurrences

#include "arraylist.h"

void initList(EList* list){
  list->size =0;
  list->entrylist = NULL;
  list->item_count=0;
}

void setListSize(EList* list, int size){
  list->size = size; 
  list->entrylist=malloc(size*sizeof(Entry*));
}

char* getListItem(EList* list, int index){
  if(index<list->size){
    return (list->entrylist[index])->word;
  }
  else{
    printf("Error: Attempting to access array out-of-bounds\n");
    return NULL;
  }
}

void setListItem(EList list, int index, char* word){
  int len = strlen(word);
  list.entrylist[index]=malloc(1*sizeof(Entry));

  (list.entrylist[index])->word=malloc((len+1)*sizeof(char*));

  strcpy((list.entrylist[index]->word),word);
}

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

void printList(EList* list){
  int i= 0;
  while(list->entrylist[i]!=NULL){
    printf("list->entrylist[%d]->word: %s\n", i,(list->entrylist[i])->word);
    i++;
  }
}


int main(int argc, char** argv){
  EList list;
  char* word = "ADELE";
  int entry_count=0;
  initList(&list);
  //  char* word = argv[1];

  setListSize(&list,10);
  printf("list->size:%d\n", list.size);

  while(entry_count<list.size){
    setListItem(list,entry_count,word);
    // printf("list.data[%d]: %s\n", entry_count, list.data[0]);
    entry_count++;
    if(entry_count==list.size){
      printf("MAX CAPACITY\n");
    }
    //searchList(&list, "Word");
  }
  searchList(&list,"Word");
  printList(&list);
  return 0;
}
