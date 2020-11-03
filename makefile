.POSIX:
.PHONY: run clean
CC= gcc
CFLAGS= -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
BINARY=shux
OBJECTS= main.o shux.o

run: $(BINARY)
	./$(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS)

main.o: main.c shux.h
	$(CC) -c main.c $(CFLAGS)

shux.o: shux.c shux.h
	$(CC) -c shux.c $(CFLAGS)

clean:
	rm *.o $(BINARY)
