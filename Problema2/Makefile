TARGET = main.out #Nombre del ejecutable producido

CFLAGS = -Wall -Wextra -Wpointer-arith -g -std=gnu11
CC = gcc

SRCS := $(wildcard *.c)
HEADERS := $(wildcard *.h)
OBJECTS := $(SRCS:%.c=%.o)

all: $(TARGET)

.PHONY: all clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#.PRECIOUS: $(TARGET) $(OBJECTS)

%.out: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o $(TARGET)
