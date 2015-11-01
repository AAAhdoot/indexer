//#include "arraylist.c"
#include "tokenizer.c"
int main(int argc, char** argv){
  EList list;
  if(argc<2){
    printf("Not enough arguments\n");
    return 0;
  }
  tokenization(argv[1]);
  return 0;
}
