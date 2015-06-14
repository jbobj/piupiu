


all:
	gcc -std=c99 -c -g puipui.c user.c pui.c survey.c
	gcc -o puipui puipui.o pui.o user.o survey.o

clean:
	rm puipui
	rm *.o
