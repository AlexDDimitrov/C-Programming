target: helpers.object max.exe sum.exe

helpers.object: helpers.h helpers.c
	gcc -c helpers.c -o helpers.o

max.exe: max.c
	gcc max.c -o max.exe

sum.exe:
	gcc sum.c helpers.o  -o sum.exe