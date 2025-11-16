all: strlenght.exe strconcat.exe strcompare.exe help.exe

help.exe: help.c
	gcc help.c -o help.exe

strlenght.exe: mystrings.o strlenght.c
	gcc strlenght.c mystrings.o -o strlenght.exe

strconcat.exe: mystrings.o strconcat.c
	gcc strconcat.c mystrings.o -o strconcat.exe

strcompare.exe: mystrings.o strcompare.c
	gcc strcompare.c mystrings.o -o strcompare.exe

mystrings.o: myStrings.h mystrings.c
	gcc -c mystrings.c -o mystrings.o

clean:
	del help.exe
	del mystrings.o
	del strlenght.exe
	del strconcat.exe
	del strcompare.exe