all: smartcar.exe main.exe

smartcar.exe: smartcar.c
	gcc smartcar.c -o smartcar.exe

main.exe: counter.h counter.c
	gcc -c counter.c -o counter.o
	gcc -o main.exe counter.o main.c