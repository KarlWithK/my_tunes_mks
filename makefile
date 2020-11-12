.POSIX:
.PHONY: run clean
CC= clang
CFLAGS=
# CFLAGS= -g -Wall -Wextra -Wpedantic -Wuninitialized -Wundef -Wcast-align -Wstrict-overflow=2 -Wwrite-strings -Wno-format-nonliteral
BINARY=shux
OBJECTS= main.o song.o shux.o
LFLAGS= -lasan

$(BINARY): $(OBJECTS)
	$(CC) -o $(BINARY) $(OBJECTS) $(LFLAGS)

main.o: main.c shux.h song.h
	$(CC) $(CFLAGS) -c main.c

shux.o: shux.c shux.h song.h
	$(CC) $(CFLAGS) -c shux.c

song.o: song.c song.h
	$(CC) $(CFLAGS) -c song.c

run: $(BINARY)
	./$(BINARY)

clean:
	rm *.o $(BINARY)
