TARGET = main.out #Nombre del ejecutable producido

CFLAGS = -Wall -Wextra -Wpointer-arith
CC = g++ -std=c++11

SRCS := $(wildcard *.cpp)
HEADERS := $(wildcard *.h)
OBJECTS := $(SRCS:%.cpp=%.o)

all: $(TARGET)

.PHONY: all clean

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

#.PRECIOUS: $(TARGET) $(OBJECTS)

%.out: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf *.o $(TARGET)
