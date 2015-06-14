


all:
	gcc -std=c99 -c -g puipui.c puipuidata.c
	gcc -o puipui puipui.o puipuidata.o

clean:
	rm puipui
	rm *.o
