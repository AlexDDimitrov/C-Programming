all: robot.exe main.exe

main.exe: sum.o main.c
	gcc main.c sum.o -o main.exe

sum.o: sum.c sum.h
	gcc -c sum.c -o sum.o

robot.exe: robot.c
	gcc robot.c -o robot.exe

clean:
	del *.o main.exe robot.exe