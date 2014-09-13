EXE=
SOURCES=$(EXE).c

CC=gcc
CFLAGS=-Wall -g -O0
INC=
LIBS=

OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(EXE) 

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(INC) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)
