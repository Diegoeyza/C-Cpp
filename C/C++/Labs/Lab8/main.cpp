#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include "dinosaurio.h"
#include "Carnivoro.h"
#include "Herviboro.h"
using namespace std;


int main() {
  ifstream archivo;
  archivo.open("dinosaurios.csv");

  if (!archivo) printf( "No se ha podido abrir el archivo\n" );
  else{
    string apodo;
    string altura;
    string esCarnivoro;
    string periodo;
    string infoAdicional;
    string line;
    string tipo;
    string sonido;
    for (int i=0;i<11;i++){
      vector<Dinosaurio> dinosaurios = vector<Dinosaurio>();
      getline(archivo,line);
      //verifico que esté en la 2da linea del archivo a leer y empiezo a cargar los dinosaurios en distintas clases acorde a si son carnivoros o no, para así ir llenando el vector
      if (i>0){
        stringstream ss(line);
        getline(ss, apodo, ',');
        getline(ss, altura, ',');
        getline(ss, esCarnivoro, ',');
        getline(ss, periodo, ',');
        getline(ss, tipo, ',');
        getline(ss, sonido, ',');
        getline(ss, infoAdicional, ',');

        if(esCarnivoro=="True"){
        Carnivoro aux(apodo,altura,esCarnivoro,periodo,infoAdicional);
        aux.hacerSonido();
        aux.mostrarInfo();        //hago que hagan sonido y que muestren su info, para luego guardarlos en un vector
        cout<<endl;
        dinosaurios.push_back(aux);
        
        }
        else if(esCarnivoro=="False"){
        Herviboro aux(apodo,altura,esCarnivoro,periodo,infoAdicional);
        aux.hacerSonido();
        aux.mostrarInfo();
        cout<<endl;
        dinosaurios.push_back(aux);
        }
      }
    }
  }
  archivo.close();
  return 0;
}