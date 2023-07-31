CC = g++
CFLAGS = -Wall -Wextra

ptrtest: main.cpp unique_ptr.cpp
	$(CC) $(CFLAGS) -o ptrtest main.cpp unique_ptr.cpp

run:ptrtest
	./ptrtest
	
clean:
	rm -f ptrtest
