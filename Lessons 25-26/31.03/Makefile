all: tests.exe main.exe 

tests.out: tests.c DynamicArray.o
	gcc tests.c DynamicArray.o -o tests.exe

main.exe: main.c DynamicArray.o
	gcc main.c DynamicArray.o -o main.exe

DynamicArray.o: DynamicArray.c DynamicArray.h util.h
	gcc -c DynamicArray.c -o DynamicArray.o

clean:
	rm -f *.o *.exe