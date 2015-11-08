#include "tokenizer.h"
#include "arraylist.h"

String Lower(String word, EList* list, char* filename, char* currentdir){
  long int i;
  for(i=0;i<strlen(word);i++){
    if(isalpha(word[i])){
      word[i] = tolower(word[i]);
    }
  }

  insertListItem(list,filename,word,currentdir);

  return word;
}


FILE *word(FILE *fp, EList* list, char* filename, char* currentdir){
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


  while((x=fgetc(fp))!=EOF){

    if(isalnum(x)!=0){
      count++;
    }
    else{
      break;
    }
  }

  fseek(fp,-count-1,SEEK_CUR);

  //fseek(current,-1,SEEK_CURR);
  word  = (String)malloc((count+1)*sizeof(char));
  for(i=0;i<count;i++){
    word[i] = fgetc(fp);
    //printf("we have just stored %c\n",word[i]);
  }
  word[count] = '\0';
  Lower(word,list, filename,currentdir);
  // printf("%s\n",Lower(word,list, filename,currentdir));
  //fseek(fp,count,SEEK_CUR);
  //printf("word: %s\n",word);
  free(word);
  return fp;
}



void tokenization( String filename, EList* list, char* currentdir) {
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
      current = word(current,list,filename,currentdir);
      
    }
    // else{
    // current = fp;
    // }
  }
  fclose(fp);
  return;
}
