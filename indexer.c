#include "indexer.h"
#include "arraylist.h"
#include "tokenizer.c"

void enterdir(String pathname, EList* list){
  EntryPtr ptr;
  DIR* pdir;
  FILE * fp;
  char x;
  pdir = opendir(pathname);
  if(!pdir){
    return;
  }
  while((ptr = readdir(pdir))!=NULL){
    //printf("current directory is %s\n",current );
    if (strcmp(ptr->d_name,".") == 0 || strcmp(ptr->d_name,"..") == 0){
      continue;
    }
    printf("d_name: [%s]\n",ptr->d_name);
    printf("d_ino: %zu\n",ptr->d_ino);
    printf("d_off: %zu\n",ptr->d_off);
    printf("d_type: %u\n",ptr->d_type);
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
   
      tokenization(ptr->d_name,list);
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
//Needs to be functional
//We need to save the file path at each level for printing to file
void filesave(char* output_file){
  FILE *fp;
  fp = fopen(output_file,"w+");
  fprintf(fp, "{\"list\" : [\n");
  fprintf(fp, "         {\"a\" : [ \n");
  fprintf(fp, "                  {\"baa\" : 1},\n");
  fprintf(fp, "                  {\"boo\" : 1}\n");
  fprintf(fp, "         ]},\n");
  fprintf(fp, "]}\n");

}

int compareWords(const void* a, const void* b) {
  /*  char* aa = *(Entry*)a->word;
  char* bb = *(Entry*)b->word;
  */
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
  setListSize(&list,5);
  if(!(pdir=opendir(givendoc)) && (fp=fopen(givendoc,"r"))){
    
    tokenization(givendoc,&list);
    //closedir(pdir); DO I NEED TO CLOSE THIS AND THE FILE POINTER?
  }
  else{
    enterdir(givendoc,&list);
  }
    
  int z=0;
  for(;z<list.item_count;z++){
    printSL(list,z);
  }
  printf("\n");
  printList(list);
  qsort(list.entrylist,list.item_count,sizeof(Entry),compareWords);
  printList(list);
  // filesave(argv[1]);

  return 0;
}
