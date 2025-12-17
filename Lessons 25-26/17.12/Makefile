all: taskmanager.exe

taskmanager.exe: processes.o taskmanager.c
	gcc processes.o taskmanager.c -o taskmanager.exe

processes.o: processes.c processes.h
	gcc -c processes.c -o processes.o

clean:
	rm -f *.o taskmanager.exe