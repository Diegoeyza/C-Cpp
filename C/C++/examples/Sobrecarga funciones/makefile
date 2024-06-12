CC=g++
flags=
exe=fraccion

$(exe): main.o fraccion.o
	$(CC) $(flags) main.o fraccion.o -o $(exe)

main.o: main.cpp
	$(CC) $(flags) -c main.cpp -o main.o

fraccion.o: fraccion.cpp
	$(CC) $(flags) -c fraccion.cpp -o fraccion.o

run: $(exe)
	.\$(exe)

clean:
	rm *.o $(exe).exe