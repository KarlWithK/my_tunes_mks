.POSIX:
.PHONY: run clean
CC= gcc
CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
BINARY=shux
OBJECTS= main.o song.o shux.o

run: $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS)

main.o: main.c shux.h song.h
	$(CC) $(CFLAGS) -c main.c

shux.o: shux.c shux.h song.h
	$(CC) $(CFLAGS) -c shux.c

song.o: song.c song.h
	$(CC) $(CFLAGS) -c song.c

clean:
	rm *.o $(BINARY)
