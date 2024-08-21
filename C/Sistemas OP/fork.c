#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(void)
{
	pid_t  pid;
	int b = 43859348;

	pid = fork();

	if (pid == -1)
	{
		/* Error:
		 * Cuando fork() retorna -1, ha ocurrido un error
		 */
		fprintf(stderr, "error en fork: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		printf("child 'b:' %d'\n", b);
		/* Proceso hijo:
		 * Cuando fork() retorna 0, estamos
		 * en el proceso hijo.
		 */
		int j;

		for (j = 0; j < 10; j++)
		{
			printf("proceso child: %d\n", j);
			sleep(1);
		}
		_exit(0);
	}
	else
	{
		printf("parent'b:' %d'\n", b);

		/* Cuando fork() retorna un entero positivo,
		 * estamos en el proceso padre.
		 * (el valor de retorno es el PID del proceso hijo.
		 * Funcion cuenta hasta 10.
		 */
		int i;

		
		for (i = 0; i < 10; i++)
		{
			printf("parent: %d\n", i);
			sleep(1);
		}
		wait(&pid);
		exit(0);
	}

	return 0;
}