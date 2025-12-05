all: max.exe sum.exe

helpers.o: helpers.h
	gcc -c helpers.c -o helpers.o

max.exe: max.c helpers.o
	gcc max.c helpers.o -o max.exe

sum.exe: sum.c helpers.o
	gcc sum.c helpers.o -o sum.exe

clean:
	del *.o *.exe