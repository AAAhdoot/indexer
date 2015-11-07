#include "arraylist.c"
#include "tokenizer.h"
int main(void){
EList list;
initList(&list);
setListSize(&list,200);

insertListItem(&list,"f6","zero", "dir");
// printList(list);
// printf("size: %d\n", list.size);
//printf("\n");

insertListItem(&list,"f7","one", "dir");
insertListItem(&list,"f7","one", "dir");

insertListItem(&list,"f7","two","dir");
insertListItem(&list,"a8","two", "dir");

 insertListItem(&list,"a8","three", "dir");
 insertListItem(&list,"a8","four", "dir");
 insertListItem(&list,"a8","five", "dir");
 insertListItem(&list,"a8","six", "dir");
 insertListItem(&list,"a8","seven", "dir");
 insertListItem(&list,"a8","eight", "dir");
 insertListItem(&list,"a8","nine", "dir");
 insertListItem(&list,"a8","ten", "dir");
 insertListItem(&list,"a8","eleven", "dir");
 insertListItem(&list,"a8","twelve", "dir");
 insertListItem(&list,"a8","thirteen", "dir");
 insertListItem(&list,"a8","fourteen", "dir");
 insertListItem(&list,"a8","fifteen", "dir");
 insertListItem(&list,"a8","sixteen", "dir");
 int x=0;
 for(;x<list.item_count;x++){
   printSL(list,x);
 }

 printf("item_count: %d %d\n", list.item_count, list.size);
printf("\n");

printList(list);

return 0;
}
