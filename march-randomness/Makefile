CC = gcc

OPTIONS = -std=c11 -Ofast
WARNINGS = -Wall -Wextra

CFLAGS = $(OPTIONS) $(WARNINGS)

BIN = bin

all:
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/round1 round1.c $(CFLAGS)
	$(CC) -o $(BIN)/round2 round2.c $(CFLAGS)
	$(CC) -o $(BIN)/round3 round3.c $(CFLAGS)

clean:
	rm -rf $(BIN)
