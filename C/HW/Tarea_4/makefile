CC=g++
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exe=programa

$(exe): main.o grafo.o
	$(CC) $(flags) main.o grafo.o -o $(exe)
	./$(exe)

grafo.o: grafo.cpp grafo.h
	$(CC) $(flags) -c grafo.cpp -o grafo.o

main.o: main.cpp grafo.h
	$(CC) $(flags) -c main.cpp -o main.o

run: $(exe)
	./$(exe)

clean:
	rm -f *.o $(exe)