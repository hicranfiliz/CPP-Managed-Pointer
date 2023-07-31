CC = g++

CFLAGS = -Wall -Wextra -std=c++11

EXEC = test

SOURCES = main.cpp unique_ptr.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
