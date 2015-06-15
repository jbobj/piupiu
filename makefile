


all:
	gcc -std=c99 -c -g piupiu.c user.c piu.c survey.c util.c
	gcc -o piupiu piupiu.o piu.o user.o survey.o util.o

clean:
	rm piupiu
	rm *.o
