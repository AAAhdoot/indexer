#include "arraylist.c"

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

insertListItem(&list,"f8","two","dir");
insertListItem(&list,"f8","two", "dir");

printSL(list,0);
printSL(list,1);
printSL(list,2);
 printf("item_count: %d\n", list.item_count);
printf("\n");

printList(list);

return 0;
}
