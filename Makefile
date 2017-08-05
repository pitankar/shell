# Makefile
INCLUDE = inc 
OUTFILE = shell

HEADERS = inc/shell.h 
SOURCE = src/main.c

all: $(HEADERS) $(SOURCE)
	gcc -std=c99 -ggdb -I$(INCLUDE) $(SOURCE) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)