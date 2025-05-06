# Makefile

all: prog1 prog2 run

prog1: prog1.c
	gcc -o prog1 prog1.c

prog2: prog2.c
	gcc -o prog2 prog2.c

run: prog1 prog2
	@echo "Running prog1..."
	@./prog1
	@echo "prog1 finished. Now running prog2..."
	@./prog2

clean:
	rm -f prog1 prog2
