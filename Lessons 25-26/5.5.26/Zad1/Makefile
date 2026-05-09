all: tests.exe

linkedList.o: LinkedLists.h LinkedLists.c
	gcc -c LinkedLists.c -o linkedList.o

tests.exe: linkedList.o tests.c linkedList.o
	gcc tests.c linkedList.o -o tests.exe

clean:
	rm -f *.o *.exe