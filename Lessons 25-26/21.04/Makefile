all: tests.exe

tests.exe: tests.c DynamicArray.o
	gcc tests.c DynamicArray.o -o tests.exe

DynamicArray.o: DynamicArray.c DynamicArray.h
	gcc -c DynamicArray.c -o DynamicArray.o

clean:
	rm -f *.o *.exe