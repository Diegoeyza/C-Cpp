CC=g++
EXE=programa
FLAGS=-Werror -Wundef -Wall
MAIN=main
FILE1=funciones
FILE2=

# $@ se reemplaza automáticamente por el nombre de la regla
# $^ se reemplaza automáticamente por todas las dependencias
# Esta regla efectivamente "linkea" todas las dependencias
$(EXE): $(FILE1).o $(MAIN).o
	$(CC) $(FLAGS) $^ -o $@
	./$(EXE)

# si no encuentra una regla con el nombre exacto,
# recurre a la regla comodín: % representa cualquier nombre
# $< se reemplaza automáticamente por la primera dependencia
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)	