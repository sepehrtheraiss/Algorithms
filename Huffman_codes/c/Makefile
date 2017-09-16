#------------------------------------------------------------------------------
#  Makefile for Huffman codes
#
#  make ListTest            makes ListTest
#  make HuffmanTest         makes HuffmanTest
#  make clean               removes binaries
#  make checkFind           tests heap for memory leaks 
#  make checkTest           tests HeapTest for memory leaks
#------------------------------------------------------------------------------

BASE_SOURCES   = HeapSort.c List.c
BASE_OBJECTS   = HeapSort.o List.o
HEADERS        = HeapSort.h List.h
COMPILE        = gcc -c -std=c99 -Wall
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full


ListTest : ListTest.o List.o
	$(LINK) ListTest ListTest.o List.o

HuffmanTest : HuffmanTest.o $(BASE_OBJECTS)
	$(LINK) HuffmanTest HuffmanTest.o $(BASE_OBJECTS)


ListTest.o : ListTest.c List.h
	$(COMPILE) ListTest.c List.c

HuffmanTest.o : HuffmanTest.c $(HEADERS)
	$(COMPILE) HuffmanTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE)  test test.o HuffmanTest HeapTest.o HeapClient.o $(BASE_OBJECTS)

checkTest : HuffmanTest
	$(MEMCHECK) ./HuffmanTest
