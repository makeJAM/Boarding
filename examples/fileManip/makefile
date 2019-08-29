#
#  MAKEFILE FOR SEC 102.6
#

main: main.c
	gcc -c lib_mylib.c -o lib_mylib.o
	ar rcs lib_mylib.a lib_mylib.o
	gcc -c main.c -o main.o
	gcc -o main main.o -L. -l_mylib

clean: 
	rm main.o lib_mylib.o lib_mylib.a
