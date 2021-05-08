CC = gcc

GENERAL = -std=gnu11 -O2
MATHOPTS = -fmerge-all-constants -fno-math-errno
OTHEROPTS = -funroll-loops -flto
# documentation for compiler optimizations:
# https://gcc.gnu.org/onlinedocs/gcc-6.1.0/gcc/Optimize-Options.html
WARNINGS = -Wall -Wextra

CFLAGS = $(GENERAL) $(MATHOPTS) $(OTHEROPTS) $(WARNINGS)

OBJ = obj
HEADERS = $(wildcard *.h)
INCLUDES = $(patsubst %.h, %.o, $(HEADERS))

BIN = bin
SOURCES = $(filter-out $(patsubst %.h, %.c, $(HEADERS)), $(wildcard *.c))
BINARIES = $(patsubst %.c, $(BIN)/%, $(SOURCES))

all: dirs $(BINARIES)

$(BIN)/%: %.o $(INCLUDES)
	$(CC) -o $@ $(OBJ)/$< $(patsubst %.o, $(OBJ)/%.o, $(filter-out $<, $^)) $(CFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -o $(OBJ)/$@ -c $< $(CFLAGS)

dirs:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)

clean:
	rm -Rrf $(OBJ)
	rm -Rrf $(BIN)
