#include "tokenizer.h"
#include "arraylist.c"
TokenizerT *TKCreate( String ts ) {
    TokenizerT *tk;
    tk =(TokenizerT*)malloc(sizeof(TokenizerT));
    tk->currentindex = 0;
    //tk->currenttypeindex= -1;
    tk->input= (String)malloc((strlen(ts)+1)*sizeof(char));
    strncpy(tk->input,ts,strlen(ts));
    return tk;
}

String Lower(String word){
	long int i;
	for(i=0;i<strlen(word);i++){
		if(isalpha(word[i])){
			word[i] = tolower(word[i]);
		}
	}
	return word;
}

String word(TokenizerT *tk){
    String word = (String)malloc(strlen(tk->input)*sizeof(char));
    long int i;
    long int j;
    //printf("hello 4\n");
    for(i=tk->currentindex,j=0;i<strlen(tk->input) && j<strlen(tk->input);i++,j++){
        if(isalnum(tk->input[i])){
            //printf("current character is %c and it's an alnum\n",tk->input[i]);
            word[j] = tk->input[i];
        }
        else{
            break;
        }
    }
    tk->currentindex = i;
    //printf("word currently is %s\n",word);
    return Lower(word);
}

void TKDestroy( TokenizerT * tk) {
    free(tk->input);
    free(tk);
    return;
}

void TKGetNextToken( TokenizerT *tk ) {
    long int i;
    //printf("hello 3\n");
    for (i=tk->currentindex;i<strlen(tk->input);){
        //printf("current character is %c\n",tk->input[i]);
        if(isalpha(tk->input[i])){
            //printf("it's a letter\n");
        	printf("%s\n",word(tk));
            i=tk->currentindex;
        }
        else{
            //printf("not a letter\n");
        	tk->currentindex+=1;
            i++;
        	continue;
        }
    }
    return;
}


void tokenization(String pathname){
    int i;
    String ts;
    FILE *fp;
    EList list;
    int entry_count;
    initList(&list);
    setListSize(&list, 50);

    //printf("hello 2\n");
    //some array list should be initialized here
 
   //Loop: if entry_count == list.size
    //then at MAX, call resize

    ts= (String)malloc(230*sizeof(char));
    fp = fopen(pathname,"r");
    //if(!fp) printf("NULLLLLLL FPPPP\n");
    while((ts = fgets(ts,230,fp))!=NULL){
        TokenizerT *tk = TKCreate(ts);
	//String return?
	//insertListItem(&list,entry_count,TKGetNextToken(tk));
        TKGetNextToken(tk);
        TKDestroy(tk);
    }
    //printList(&list);
    fclose(fp);
    return;
}

/*int main(int argc, char** argv){

    tokenization(argv[1]);

    return 0;
}*/





