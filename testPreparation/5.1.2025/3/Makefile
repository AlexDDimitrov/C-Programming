all: main.exe smarthouse.exe

main.exe: product.o main.c
	gcc main.c product.o -o main.exe	

product.o: product.c product.h
	gcc -c product.c -o product.o

smarthouse.exe: smarthouse.c
	gcc smarthouse.c -o smarthouse.exe