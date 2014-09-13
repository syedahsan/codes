EXE=main
SOURCES=$(EXE).cpp

CC=g++
CFLAGS=-Wall -g -O0 #-DUSE_EXPORT_KEYWORD
INC=-I.
LIBS=

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXE) 

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(INC) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)
