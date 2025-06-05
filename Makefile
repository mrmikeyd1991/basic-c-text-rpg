# Variables
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

# Targets and dependencies
all: main

main: main.o player.o banner.o
	$(CC) $(CFLAGS) -o main main.o player.o banner.o $(LDFLAGS)

main.o: main.c player.h banner.h
	$(CC) $(CFLAGS) -c main.c

player.o: player.c player.h
	$(CC) $(CFLAGS) -c player.c

banner.o: banner.c banner.h
	$(CC) $(CFLAGS) -c banner.c

# Clean up object files and the executable
clean:
	rm -f *.o main

