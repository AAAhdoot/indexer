#include "indexer.h"
#include "arraylist.h"
#include "tokenizer.c"

void enterdir(String pathname, EList* list){
  EntryPtr ptr;
  DIR* pdir;
  FILE * fp;
  char x;
  pdir = opendir(pathname);
  char* currentdir = malloc(51*sizeof(char));
  if(!pdir){
    return;
  }
  while((ptr = readdir(pdir))!=NULL){
    //printf("current directory is %s\n",current );
    if (strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0){
      continue;
    }
    /*   printf("d_name: [%s]\n",ptr->d_name);
    printf("d_ino: %zu\n",ptr->d_ino);
    printf("d_off: %zu\n",ptr->d_off);
    printf("d_type: %u\n",ptr->d_type);
    */

    if(ptr->d_type == 8){
      chdir(pathname);
      fp = fopen(ptr->d_name,"r");
      if(!fp){
	continue;
      }
      x = fgetc(fp);
      if(isprint(x)==0){
	fclose(fp);
	continue;
      }
      fclose(fp);
      getcwd(currentdir,50);
      tokenization(ptr->d_name,list,currentdir);
      chdir("..");
    }
    else if(ptr->d_type == 4){
      chdir(pathname);
      enterdir(ptr->d_name,list);
      chdir("..");
    }
    else{
      continue;
    }
  }
  closedir(pdir);
  return;

}

void filesave(EList list, char* output_file){
  FILE *fp;
  int i;
  int j;
  Occurrence * curr;
  fp = fopen(output_file,"w+");
  //REPLACE "list" with directory name
  fprintf(fp, "{\"list\" : [\n");
  for(i=0;i<list.item_count;i++){
    fprintf(fp, "         {\"%s\" : [ \n", list.entrylist[i].word); //would be the word you are talking about
    curr = (list.entrylist[i]).sl->head;
   
    while(curr&&curr->filename){
       //no more Occurrences, no comma
      if(!(curr->next)){
	fprintf(fp, "                  {\"%s\" : %d}\n",curr->filename, curr->freq); //filepath 1 with frequency 1
      }
      else{
	fprintf(fp, "                  {\"%s\" : %d},\n",curr->filename, curr->freq); //filepath 2 with frequency 2
      }
      curr=curr->next;
    }
    if(i==list.item_count-1){
      fprintf(fp, "         ]}\n");
    }
    else{
      fprintf(fp, "         ]},\n");
    }

  }
  fprintf(fp, "]}\n");
  fclose(fp);
  return;
  // append file path to each filename?
  //   fprintf(fp, "%s %s %s %d", "We", "are", "in", 2012);
}

int compareWords(const void* a, const void* b) {
 
  Entry aa = *(Entry*)a; 
  Entry bb = *(Entry*)b; 
  return strcmp(aa.word,bb.word);
}

int main(int argc, char **argv){
  String givendoc; 
  String futurefile; 
  EntryPtr ptr;
  DIR* pdir;
  FILE * fp;
  FILE *write;
  char x;
  EList list;
  givendoc = argv[2];
  futurefile = argv[1];
  if(argc!=3 || !givendoc || !futurefile){
    errno = EINVAL;
    printf("%s\n", strerror( errno ));
    exit(0);
  }

  initList(&list);
  setListSize(&list,200);
  pdir=opendir(givendoc);
  fp=fopen(givendoc,"r");
  if(!pdir && fp){
    fclose(fp);
    tokenization(givendoc,&list,NULL);
    //closedir(pdir); DO I NEED TO CLOSE THIS AND THE FILE POINTER?
  }
  else if(!pdir && !fp){
    errno = ENOENT;
    printf("%s\n", strerror( errno ));
    exit(0);
  }
  else{
    closedir(pdir);
    enterdir(givendoc,&list);
  }
    

  qsort(list.entrylist,list.item_count,sizeof(Entry),compareWords);
  //printList(list);
  //  printf("item_count: %d\n", list.item_count);


  filesave(list, argv[1]);

  return 0;
}
