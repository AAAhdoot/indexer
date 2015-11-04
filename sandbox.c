#include "arraylist.c"

int main(void){
EList list;
initList(&list);
setListSize(&list,200);

insertListItem(&list,"f6","nine");
 printList(list);
 //printf("initial address: %p  %p\n", list, list.entrylist);
 printf("size: %d\n", list.size);
printf("\n");

insertListItem(&list,"f7","five");

insertListItem(&list,"f8","oneeighty");

addToSL(&list,0,"f0");
addToSL(&list,1,"f1");
addToSL(&list,1,"f2");
addToSL(&list,1,"f5");
addToSL(&list,1,"f3");

addToSL(&list,2,"f180");

printSL(list,0);
printSL(list,2);
 printf("item_count: %d\n", list.item_count);
printf("\n");

printList(list);

return 0;
}
