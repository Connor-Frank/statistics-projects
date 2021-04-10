CC = gcc
BIN = bin

GENERAL = -std=c11 -O2
MATHOPTS = -fmerge-all-constants -fno-math-errno
OTHEROPTS = -funroll-loops -flto
# documentation for compiler optimizations:
# https://gcc.gnu.org/onlinedocs/gcc-6.1.0/gcc/Optimize-Options.html
WARNINGS = -Wall -Wextra

CFLAGS = $(GENERAL) $(MATHOPTS) $(OTHEROPTS) $(WARNINGS)

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
	$(CC) -o $(BIN)/round12 round12.c $(CFLAGS)

clean:
	rm -rf $(BIN)
