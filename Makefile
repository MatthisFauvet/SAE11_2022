CC=gcc
CFLAGS=-std=c89 -Wall -c -lgraph
LDFLAGS=-std=c89 -Wall -lgraph
EXEC=main

main: main.o menu.o theme.o diff.o start.o jeux.o final.o
	$(CC) -o main menu.o theme.o diff.o main.o start.o jeux.o final.o $(LDFLAGS)
main.o: main.c menu.h main.h
	$(CC) main.c $(CFLAGS)
menu.o: menu.c main.h menu.h theme.h start.h diff.h jeux.h final.h
	$(CC) menu.c $(CFLAGS)
theme.o: theme.c main.h menu.h theme.h 
	$(CC) theme.c $(CFLAGS)
start.o: start.c main.h menu.h start.h 
	$(CC) start.c $(CFLAGS)
diff.o: diff.c main.h menu.h diff.h 
	$(CC) diff.c $(CFLAGS)
jeux.o: jeux.c main.h menu.h jeux.h
	$(CC) jeux.c $(CFLAGS)
final.o: final.c main.h menu.h final.h 
	$(CC) final.c $(CFLAGS)

clean:
	rm -rf .o
cleanall:
	rm -rf main.o
run:
	./main
