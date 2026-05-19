all: main.exe

linkedList.o: LinkedLists.h LinkedLists.c
	gcc -c LinkedLists.c -o linkedList.o

main.exe: linkedList.o main.c linkedList.o
	gcc main.c linkedList.o -o main.exe

clean:
	rm -f *.o *.exe