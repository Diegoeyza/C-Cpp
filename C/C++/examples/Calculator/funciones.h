#include<string>

using namespace std;

typedef int (*func)(int, int);

class operacion {
private:
	func funcion;
public:
	operacion(func, char, string);
	int calcular(int, int);
	char oper;
	string nombre;
};

int suma(int, int);
int resta(int, int);
int mult(int, int);
int potencia(int, int);