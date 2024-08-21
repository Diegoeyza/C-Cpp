#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv) {
	printf("Nuevo ejecutable '%s' cargado por proceso hijo...\n", argv[0]);
	int i = 0;
	while (1) {
		sleep(1);
		printf("[Programa exec] Segundos transcurridos: '%d'\n", i);
		i++;
	}
	return 0;
}

