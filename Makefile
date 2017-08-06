# Makefile
INCLUDE = inc 
OUTFILE = shell

HEADERS = inc
SOURCE = src/main.c src/cmd.c

all: $(HEADERS) $(SOURCE)
	gcc -std=c99 -ggdb -I$(INCLUDE) $(SOURCE) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)