CC=g++
exe=programa
flags=-std=c++11 -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
rutapython=/usr/include/python3.9
libreria=_grafo.so

libreria: $(libreria)

$(exe): main.o grafo.o
	$(CC) -o $@ $^
	
$(libreria): lib_wrap.cxx grafo.o
	$(CC) -fPIC -c lib_wrap.cxx -o lib_wrap.o -I$(rutapython)
	$(CC) -shared lib_wrap.o grafo.o -o $(libreria) -lpython3.9
	
lib_wrap.cxx: lib.i grafo.h
	swig -python -c++ lib.i

grafo.o: grafo.h grafo.cpp
	$(CC) -fPIC -c -o grafo.o grafo.cpp

main.o: main.cpp grafo.h
	$(CC) -c -o main.o main.cpp
	
%.o: %.cpp %.h
	$(CC) -c -o $@ $<
	
clean:
	rm -f *.o $(exe) $(libreria) *.cxx grafo.py *.so
	rm -r -f __pycache__
