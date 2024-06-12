CC=g++
flags=
exe=prog
lib=libfiguras.so

# 3. Al compilador le decimos que use la librería "libfiguras"
#    (-lfiguras) que está en esta misma carpeta/directorio (-L.)
# 4. Al linker (-Wl) le decimos que agregue esta misma carpeta/directorio
#    a su lista de lugares para buscar librerías (-rpath=.)

$(exe): main.o $(lib)
	$(CC) $(flags) main.o -o $(exe) -L. -lfiguras -Wl,-rpath=.

# 2. La librería dinámica se compila con -shared y se le da extensión
#    .dll (.so en Linux)
$(lib): rectangulo.o cuadrado.o elipse.o
	$(CC) $(flags) -shared rectangulo.o cuadrado.o elipse.o -o $(lib)

# 1. Las clases se compilan con -fPIC para prepararlas para ser parte
#    de una librería dinámica
rectangulo.o: rectangulo.cpp rectangulo.h
	$(CC) $(flags) -fPIC -c rectangulo.cpp -o rectangulo.o

cuadrado.o: cuadrado.cpp cuadrado.h rectangulo.h
	$(CC) $(flags) -fPIC -c cuadrado.cpp -o cuadrado.o

elipse.o: elipse.cpp elipse.h rectangulo.h
	$(CC) $(flags) -fPIC -c elipse.cpp -o elipse.o

main.o: main.cpp rectangulo.h
	$(CC) $(flags) -c main.cpp -o main.o

run: $(exe)
	.\$(exe)

clean:
	rm *.o $(exe) *.so
