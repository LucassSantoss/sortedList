CC = gcc
CFLAGS = -Wall -Wextra

all: main clean

main: main.o sortedList.o
	$(CC) $(CFLAGS) -o main main.o sortedList.o

main.o: main.c sortedList.h
	$(CC) $(CFLAGS) -c -o main.o main.c

sortedList.o: sortedList.c sortedList.h
	$(CC) $(CFLAGS) -c -o sortedList.o sortedList.c

clean:
	rm -rf *.o
