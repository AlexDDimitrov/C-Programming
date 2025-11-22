all: safeAdd.exe safeSubtract.exe safeMultiply.exe safeDivide.exe

safeAdd.exe: safeint.o safeAdd.c
	gcc safeint.o safeAdd.c -o safeAdd.exe

safeSubtract.exe: safeint.o safeSubtract.c
	gcc safeint.o safeSubtract.c -o safeSubtract.exe

safeMultiply.exe: safeint.o safeMultiply.c
	gcc safeint.o safeMultiply.c -o safeMultiply.exe

safeDivide.exe: safeint.o safeDivide.c
	gcc safeint.o safeDivide.c -o safeDivide.exe

safeint.o: safeint.h safeint.c
	gcc -c safeint.c -o safeint.o

clean:
	del *.o *.exe

