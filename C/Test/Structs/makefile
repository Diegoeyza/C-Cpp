CC=gcc
flags=-Wall -Wundef -Werror
exe=supercalc
main=T3
funcion=file

$(exe): $(funcion).o $(main).o
	$(CC) $(flags) $(main).o $(funcion).o -o $(exe)
	./$(exe)


funcion.o: $(funcion).c
	$(CC) $(flags) -c $(funcion).c -o $(funcion).o

main.o: main.c
	$(CC) $(flags) -c $(main).c -o $(main).o

again: clean $(exe)

run: $(exe)
	./$(exe)

all: clean run

clean:
	-rm *.o $(objects)
	-rm $(exe)