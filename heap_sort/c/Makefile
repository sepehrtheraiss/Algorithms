#------------------------------------------------------------------------------
#  Makefile for Heap Sort
#
#  make HeapClient          makes HeapClient
#  make HeapTest            makes HeapTest
#  make clean               removes binaries
#  make checkFind           tests heap for memory leaks 
#  make checkClient         tests HeapClient for memory leaks
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

HeapTest : HeapTest.o $(BASE_OBJECTS)
	$(LINK) HeapTest HeapTest.o $(BASE_OBJECTS)


HeapClient.o : HeapClient.c $(HEADERS)
	$(COMPILE) HeapClient.c

HeapTest.o : HeapTest.c $(HEADERS)
	$(COMPILE) HeapTest.c

$(BASE_OBJECTS) : $(BASE_SOURCES) $(HEADERS)
	$(COMPILE) $(BASE_SOURCES)

clean :
	$(REMOVE)  HeapClient HeapTest HeapTest.o HeapClient.o $(BASE_OBJECTS)

checkClient : HeapClient
	$(MEMCHECK) HeapClient
