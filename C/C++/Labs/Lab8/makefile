CC=g++
flags=
exe=programa

$(exe): main.o dinosaurio.o Carnivoro.o Herviboro.o
	$(CC) $(flags) main.o dinosaurio.o Carnivoro.o Herviboro.o -o $(exe)

dinosaurio.o: dinosaurio.cpp dinosaurio.h
	$(CC) $(flags) -c dinosaurio.cpp -o dinosaurio.o

Carnivoro.o: Carnivoro.cpp Carnivoro.h dinosaurio.h
	$(CC) $(flags) -c Carnivoro.cpp -o Carnivoro.o

Herviboro.o: Herviboro.cpp Herviboro.h dinosaurio.h
	$(CC) $(flags) -c Herviboro.cpp -o Herviboro.o

main.o: main.cpp dinosaurio.h
	$(CC) $(flags) -c main.cpp -o main.o

run: $(exe)
	./$(exe)

clean:
	rm -f *.o $(exe)