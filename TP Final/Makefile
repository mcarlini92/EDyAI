.PHONY: all clean
SOURCES=mov entrada salida cruz vertices aristas cruzopo \
	extendercruzopo posicesqui orientesqui main
OBJECTS=$(patsubst %,build/%.o,$(SOURCES))
TARGET=bin/rubik
CFLAGS=-c -Wall 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(OBJECTS) -o $(TARGET)

build/%.o: src/%.c
	gcc $(CFLAGS) $< -o $@
	
clean:
	rm -f build/*
	rm -f $(TARGET)

