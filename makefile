CC = gcc
CFLAGS  = -g
COMPILE = $(CC) $(CFLAGS)

all:  index

index: indexer.o sorted-list.o tokenizer.o arraylist.o
	$(COMPILE) -o index indexer.o sorted-list.o tokenizer.o arraylist.o

indexer.o: indexer.c sorted-list.h indexer.h arraylist.h tokenizer.h
	gcc -c indexer.c

sorted-list.o: sorted-list.c sorted-list.h arraylist.h
	gcc -c sorted-list.c

tokenizer.o: tokenizer.c tokenizer.h arraylist.h
	gcc -c tokenizer.c

arraylist.o: arraylist.c arraylist.h sorted-list.h
	gcc -c arraylist.c

clean:
	rm -rf *.o index
