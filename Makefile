CC = g++
CC_FLAGS = -std=c++0x -Wall -ansi
EXEC = calculator
SOURCES = $(wildcard *.cpp)
OBJECTS = calculator.cpp

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CC_FLAGS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)

