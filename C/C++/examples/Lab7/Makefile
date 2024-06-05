CC=g++
flags=
exe=prog
lib=libanimales.so
main=main

# 3. Al compilador le decimos que use la librería "libfiguras"
#    (-lfiguras) que está en esta misma carpeta/directorio (-L.)
# 4. Al linker (-Wl) le decimos que agregue esta misma carpeta/directorio
#    a su lista de lugares para buscar librerías (-rpath=.)

$(exe): $(main).o $(lib)
	$(CC) $(flags) $(main).o -o $(exe) -L. -lanimales -Wl,-rpath=.

# 2. La librería dinámica se compila con -shared y se le da extensión
#    .dll (.so en Linux)



$(main).o: $(main).cpp Animal.h
	$(CC) $(flags) -c $(main).cpp -o $(main).o

run: $(exe)
	./$(exe)

clean:
	rm *.o $(exe) 
