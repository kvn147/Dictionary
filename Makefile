main: HW3.o list.o hash.o
	gcc -g -o HW3 HW3.o list.o hash.o

HW3.o: HW3.c list.h hash.h
	gcc -g -c HW3.c

list.o: list.c
	gcc -g -c list.c 

hash.o: hash.c
	gcc -g -c hash.c

clean:
	rm HW3 HW3.o list.o hash.o
