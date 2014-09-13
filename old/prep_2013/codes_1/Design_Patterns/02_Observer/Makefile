EXE=main
SOURCES=$(EXE).cpp WeatherData.cpp

CC=g++
CFLAGS=-Wall -Werror -g -O0
INC=
LIBS=

OBJECTS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXE) 

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(INC) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(EXE) $(OBJECTS)
