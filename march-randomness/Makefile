CC = gcc

GENERAL = -std=c11 -O2
MATHOPTS = -fmerge-all-constants -fno-math-errno
OTHEROPTS = -funroll-loops -flto
# documentation for compiler optimizations:
# https://gcc.gnu.org/onlinedocs/gcc-6.1.0/gcc/Optimize-Options.html
WARNINGS = -Wall -Wextra

CFLAGS = $(GENERAL) $(MATHOPTS) $(OTHEROPTS) $(WARNINGS)

BIN = bin
SOURCES := $(wildcard *.c)
BINARIES := $(patsubst %.c, $(BIN)/%, $(SOURCES))

all: dirs $(BINARIES)

$(BIN)/%: %.c
	$(CC) -I -c $< -o $@ $(CFLAGS)

dirs:
	mkdir -p $(BIN)

clean:
	rm -rf $(BIN)
