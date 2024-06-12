CC=g++
flags=
exe=prog

$(exe): main.o rectangulo.o cuadrado.o elipse.o
	$(CC) $(flags) main.o rectangulo.o cuadrado.o elipse.o -o $(exe)

rectangulo.o: rectangulo.cpp rectangulo.h
	$(CC) $(flags) -c rectangulo.cpp -o rectangulo.o

cuadrado.o: cuadrado.cpp cuadrado.h rectangulo.h
	$(CC) $(flags) -c cuadrado.cpp -o cuadrado.o

elipse.o: elipse.cpp elipse.h rectangulo.h
	$(CC) $(flags) -c elipse.cpp -o elipse.o

main.o: main.cpp rectangulo.h
	$(CC) $(flags) -c main.cpp -o main.o

run: $(exe)
	.\$(exe)

clean:
	rm -f *.o $(exe)
