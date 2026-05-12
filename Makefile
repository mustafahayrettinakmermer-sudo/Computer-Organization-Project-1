CC = gcc
CFLAGS = -g -Wall

project: main.c list.c visualize.c bugs.c
	$(CC) $(CFLAGS) -o project main.c list.c visualize.c bugs.c

clean:
	rm -f project