#------------------------------------------------------------------------------
#  Makefile for Huffman codes
#
#  make HeapClient          makes HeapClient
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


HeapClient : HeapClient.o $(BASE_OBJECTS)
	$(LINK) HeapClient HeapClient.o $(BASE_OBJECTS)

HuffmanTest : HuffmanTest.o $(BASE_OBJECTS)
	$(LINK) HuffmanTest HuffmanTest.o $(BASE_OBJECTS)


HeapClient.o : HeapClient.c $(HEADERS)
	$(COMPILE) HeapClient.c

HuffmanTest.o : HuffmanTest.c $(HEADERS)
	$(COMPILE) HuffmanTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE)  HeapClient HuffmanTest HeapTest.o HeapClient.o $(BASE_OBJECTS)

checkTest : HuffmanTest
	$(MEMCHECK) ./HuffmanTest
