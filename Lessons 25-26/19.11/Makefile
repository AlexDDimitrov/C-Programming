all: safeAdd.exe safeSubtract.exe

safeAdd.exe: safeint.o safeAdd.c
	gcc safeint.o safeAdd.c -o safeAdd.exe

safeSubtract.exe: safeint.o safeSubtract.c
	gcc safeint.o safeSubtract.c -o safeSubtract.exe

safeint.o: safeint.h safeint.c
	gcc -c safeint.c -o safeint.o

clean:
	del *.o *.exe

