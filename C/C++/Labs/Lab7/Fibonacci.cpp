#include <iostream>
#include <list>
using namespace std;
int main() {
    cout << "Lista de los primeros 50 números de la sucesión de Fibonacci:"
    << endl;
    list<long long int> fibo;
    fibo.push_back(0);
    fibo.push_back(1);
    long long int nuevo, f1, f2;
    f1 = 0;
    f2 = 1;
    while (fibo.size() < 50) {
        nuevo = 0;
        nuevo = f1 + f2;
        f1 = f2;
        f2 = nuevo;
        fibo.push_back(nuevo);
    }
    int index = 1;
    for (long long int i : fibo) {
        cout << index << ") " << i << endl;
        index++;
    }
    long long int suma = 0;
    for (long long int i : fibo) {
        suma = suma + i;
    }
    cout
    << "\nLa suma de los primeros 50 números de la sucesión de Fibonacci es: "
    << suma << endl;
    long long int promedio = suma / fibo.size();
    float promedioFloat = suma / fibo.size();
    cout << "El promedio de los números de la lista en int es: " << promedio
    << endl;
    cout << "El promedio de los números de la lista en float es: "
    << promedioFloat << endl;
return 0;
}