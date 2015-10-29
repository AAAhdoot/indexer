//ArrayList structure for list of words and list of occurrences

#include "arraylist.h"

void initList(arraylist* list){
  list->size =0;
  list->data = NULL;
}

void setListSize(arraylist* list, int size){
  list->size = size; 
  list->data=malloc(size*sizeof(char*));
}

char* getListItem(arraylist* list, int index){
  if(index<list->size){
    return list->data[index];
  }
  else{
    printf("Error: Attempting to access array out-of-bounds\n");
    return NULL;
  }
}

void setListItem(arraylist list, int index, char* word){
  int len = strlen(word);
  list.data[index]=malloc((len+1)*sizeof(char*));
  list.data[index]=word;
}

void searchList(arraylist* list, char* word){
  printf("search for: %s\n",word);
  int i=0;
  for(; i < list->size; i++){
    //only run strcmp on non-NULL entries or else segfaults
   if(list->data[i]!=NULL && strcmp(word,list->data[i])==0){
      printf("Already in list!\n");
      return;
    }
  }
  printf("Not in list\n");
  return;
}

void printList(arraylist* list){
  int i= 0;
  while(list->data[i]!=NULL){
    printf("list->data[%d]: %s\n", i,list->data[i]);
    i++;
  }
}

int main(int argc, char** argv){
  arraylist list;
  char* word = "DUDE";
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
  printList(&list);
  return 0;
}
