all: main.exe

quadraticroots.o: quadraticroots.c
	gcc -c quadraticroots.c -o quadraticroots.o

main.exe: main.c quadraticroots.o
	gcc main.c quadraticroots.o -lm -o main.exe

clean:
	del main.exe quadraticroots.o