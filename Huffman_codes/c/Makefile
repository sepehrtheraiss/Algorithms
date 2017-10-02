#------------------------------------------------------------------------------
#  Makefile for Huffman codes
#
#  make ListTest            makes ListTest
#  make HeapTest            makes HeapTest
#  make HuffmanTest         makes HuffmanTest
#  make clean               removes binaries
#  make checkHeapTest       tests heap for memory leaks 
#  make checkHufftest           tests Huffman for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = HeapSort.c List.c
BASE_OBJECTS   = HeapSort.o List.o
HEADERS        = HeapSort.h List.h
COMPILE        = gcc -c -g -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f1
MEMCHECK       = valgrind --leak-check=full --track-origins=yes 


ListTest : ListTest.o List.o
	$(LINK) ListTest ListTest.o List.o

HeapTest : HeapTest.o HeapSort.o List.o
	$(LINK) HeapTest HeapTest.o HeapSort.o List.o

HuffmanTest : HuffmanTest.o $(BASE_OBJECTS)
	$(LINK) HuffmanTest HuffmanTest.o $(BASE_OBJECTS)


ListTest.o : ListTest.c List.h 
	$(COMPILE) ListTest.c List.c

HeapTest.o : HeapTest.c HeapSort.h List.h 
	$(COMPILE) HeapTest.c HeapSort.c List.c

HuffmanTest.o : HuffmanTest.c $(HEADERS)
	$(COMPILE) HuffmanTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE)  HuffmanTest HeapTest ListTest *.o

checkHuffTest : HuffmanTest
	$(MEMCHECK) ./HuffmanTest

checkHeapTest : HeapTest
	$(MEMCHECK) ./HeapTest
