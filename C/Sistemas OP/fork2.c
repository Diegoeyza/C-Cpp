#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void padre(int cid) {
	wait(&cid);	
    printf("Ha terminado el hijo con status '%d'\n", cid);
}

void hijo() {
	int i = 0;
	while (1) {
		sleep(1);
		i++;
		printf("[PID %d; hijo] Segundos transcurridos: '%d'\n", getpid(), i);
	}
}

int main() {

	int cid = fork();

	/* Proceso hijo!*/
	if (cid == 0) {
		printf("Este proceso es hijo, y veo valor de retorno de fork '%d'!\n", cid);
		//hijo();
		execl("./exec", "exec");
	}
	else {
		printf("Este proceso es padre PID '%d', con PID '%d' del hijo!\n", getpid(), cid);
		padre(cid);
	}

	return 0;
}
