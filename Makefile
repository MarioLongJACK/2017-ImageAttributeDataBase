CC = gcc
CFLAGS = -Wall -Werror -std=gnu99
SOURCE = *.c
HEADERS = tree.h utils.h
OBJ = tree.o utils.o image_database.o
EXEC = image_database

all: $(EXEC)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

image_database: tree.o utils.o image_database.o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: count
count:
	wc $(SOURCE) $(HEADERS)
