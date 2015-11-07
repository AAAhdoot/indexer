#include "tokenizer.h"
#include "arraylist.c"

String Lower(String word, EList* list, char* filename){
  long int i;
  for(i=0;i<strlen(word);i++){
    if(isalpha(word[i])){
      word[i] = tolower(word[i]);
    }
  }
  //printf("IS THIS PASSING TO INSERT?: %s\n",filename);
  insertListItem(list,filename,word,"d1");
  //  printf("lower?: %s\n", word);
  return word;
}


FILE *word(FILE *fp, EList* list, char* filename){
  int i;
  String word;
  FILE * current;
  FILE * start;
  FILE *end;
  int count;
  char x;
  current = fp;
  start = fp;
  count = 0;

  // printf("IS THIS GETING PASSED?-----%s\n", filename);
  while((x=fgetc(fp))!=EOF){
    //printf("in word, character currently is %c and count is %d\n",x,count);
    if(isalnum(x)!=0){
      count++;
    }
    else{
      break;
    }
  }
  //printf("count currently is %d\n",count);
  fseek(fp,-count-1,SEEK_CUR);
  //count++;
  //fseek(current,-1,SEEK_CURR);
  word  = (String)malloc((count+1)*sizeof(char));
  for(i=0;i<count;i++){
    word[i] = fgetc(fp);
    //printf("we have just stored %c\n",word[i]);
  }
  word[count] = '\0';
  //printf("word[count] is %c\n",word[count]);
  //printf("homedawg, word currently is %s\n",word);
  printf("%s\n",Lower(word,list, filename));
  //end = current;
  //fseek(fp,count,SEEK_CUR);
  //printf("word: %s\n",word);
  free(word);
  return fp;
}



void tokenization( String filename, EList* list) {
  int count;
  FILE *fp = fopen(filename,"r");
  // printf("NAME----------: %s\n",filename);
  FILE *start;
  FILE *current;
  char x;
  current = fp;
  while((x=fgetc(current))!=EOF){
    if(isalpha(x)!=0){
      //printf("%c is an alpha\n",x);
      fseek(current,-1,SEEK_CUR);
      current = word(current,list,filename);
      
    }
    // else{
    // current = fp;
    // }
  }
  fclose(fp);
  return;
}
