all: robot.out main.out

robot.out: robot.c
	gcc robot.c -o robot.exe

main.out: main.c sum.c
	gcc main.c sum.c -o main.exe

clean:
	rm -f *.exe
