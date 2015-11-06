#include "tokenizer.h"

String Lower(String word){
  long int i;
  for(i=0;i<strlen(word);i++){
    if(isalpha(word[i])){
      word[i] = tolower(word[i]);
    }
  }
  //  printf("lower?: %s\n", word);
  return word;
}


FILE *word(FILE *fp){
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
  printf("%s\n",Lower(word));
  //end = current;
  //fseek(fp,count,SEEK_CUR);
  //printf("word: %s\n",word);
  free(word);
  return fp;
}



void tokenization( String pathname) {
  int count;
  FILE *fp = fopen(pathname,"r");
  FILE *start;
  FILE *current;
  char x;
  current = fp;
  while((x=fgetc(current))!=EOF){
    if(isalpha(x)!=0){
      //printf("%c is an alpha\n",x);
      fseek(current,-1,SEEK_CUR);
      current = word(current);
      
    }
    // else{
    // current = fp;
    // }
  }
  fclose(fp);
  return;
}
