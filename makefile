
main: main.c hf.o
	gcc main.c hf.o -o main

hf.o: hf.c
	gcc -c hf.c
