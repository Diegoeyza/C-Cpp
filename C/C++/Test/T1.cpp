#include<iostream>
using namespace std;
//estas 2 cosas siempre van

typedef int (*func)(int, int);
//crea el tipo funcion, que te deja declarar funciones como variables, no hace falta tenerlo siempre en el código

class Person {
private:
	int id=10;
    //private implica que sólo puedes llamar el id dentro de la misma clase, no desde fuera (en python al llamar desde fuera uno hacía: Person.id, acá si es private, no se puede)
public:
	void calcular();
    int age;
	string nombre;
};

//defino desde fuera la funcion de la clase, puedo hacerlo desde dentro igual, pero en general es mejor hacerlo desde fuera
void Person::calcular(){
    cout<<nombre<<" HP is:"<<(age*id)<<endl;
    //cout siempre termina con endl
}

int main(){
    Person diego,tomas;
    //creo 2 objetos de tipo Person
    cout<<"Please enter the age of the 1st person: ";
    cin>>diego.age;
    diego.nombre="Diego";
    tomas.age=20;
    tomas.nombre="Tomas";
    diego.calcular();
    //llamo con nombre.atributo para definir sus atributos
    return 0;
}

