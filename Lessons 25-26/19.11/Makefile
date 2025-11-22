all: safeAdd.exe safeSubtract.exe safeMultiply.exe safeDivide.exe

safeAdd.exe: safeint.o utill.o safeAdd.c
	gcc safeint.o utill.o safeAdd.c -o safeAdd.exe

safeSubtract.exe: safeint.o utill.o safeSubtract.c
	gcc safeint.o utill.o safeSubtract.c -o safeSubtract.exe

safeMultiply.exe: safeint.o utill.o safeMultiply.c
	gcc safeint.o utill.o safeMultiply.c -o safeMultiply.exe

safeDivide.exe: safeint.o utill.o safeDivide.c
	gcc safeint.o utill.o safeDivide.c -o safeDivide.exe

safeint.o: safeint.h safeint.c
	gcc -c safeint.c -o safeint.o

utill.o: utill.h utill.c
	gcc -c utill.c -o utill.o

clean:
	del *.o *.exe