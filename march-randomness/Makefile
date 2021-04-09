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
	$(CC) -o $(BIN)/round4 round4.c $(CFLAGS)
	$(CC) -o $(BIN)/round5 round5.c $(CFLAGS)
	$(CC) -o $(BIN)/round6 round6.c $(CFLAGS)
	$(CC) -o $(BIN)/round7 round7.c $(CFLAGS)
	$(CC) -o $(BIN)/round8 round8.c $(CFLAGS)
	$(CC) -o $(BIN)/round9 round9.c $(CFLAGS)
	$(CC) -o $(BIN)/round10 round10.c $(CFLAGS)
	$(CC) -o $(BIN)/round11 round11.c $(CFLAGS)

clean:
	rm -rf $(BIN)
