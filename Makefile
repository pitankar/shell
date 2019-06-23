# Makefile
INCLUDE = inc/
PROJECT = shell

GCCFLAGS = -std=c99 -ggdb
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(OBJECTS)
	gcc $(GCCFLAGS) -I$(INCLUDE) $(OBJECTS) -o $(PROJECT)
	rm -rf $(OBJECTS)

%.o: %.c
	gcc -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf $(PROJECT)