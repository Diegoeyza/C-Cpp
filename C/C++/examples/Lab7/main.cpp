#include<iostream>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

#include"Animal.h"
#include"Osopolar.h"
#include"Marmota.h"
#include"Tortuga.h"


using namespace std;



string removeTrailingCharacters(std::string &str, const char charToRemove) {
    string str2=str;
    str2.erase (str2.find_last_not_of(charToRemove) + 1, std::string::npos );
    return str2;
}

int main() {
    ifstream part;

    string name;
    string species;
    int speed;
    part.open("participantes.txt");
    vector<Animal> animals = vector<Animal>();
    queue<Animal> final;

    int i;
    for(i=0;i<9;i++) {    //se lee el archivo participantes y se crean los objetos y se guarda en lista
        
        part>>name>>species>>speed;
        if(species=="Osopolar"){
          Osopolar aux(name,speed);
          animals.push_back(aux);
          
        }
        else if(species=="Marmota"){
          Marmota aux(name,speed);
          animals.push_back(aux);
          
        }
        else if(species=="Tortuga"){
          Tortuga aux(name,speed);
          animals.push_back(aux);
          
        }
    }
  while(animals.size()>0){    //algoritmo de sorteo
    double mayor=0;
    int index=0;
    for(int k=0;k<animals.size();k++){
      if(animals[k].VelocidadF()>mayor){
        mayor= animals[k].VelocidadF();
        index=k;
        
      }
    }
    final.push(animals[index]); //se pushea a la cola
    animals.erase(animals.begin() + index); //se borra el elemento de la lista
  }

    
   

  

    int pos=1;
    int space=57;
    cout<<"---------------------------------------------------------"<<endl;
    while(!final.empty()){
    int pp=final.front().nameR().size();
    string ssss=to_string(final.front().VelocidadF());
    string sss=removeTrailingCharacters(ssss,'0');
    int ss=sss.size();
    int spaces;
    if (ss==4){
      spaces=space-5-pp-ss-1;
    }
      else{
        spaces=space-5-pp-ss;
      }
    
    string spacess(spaces,' ');
    
		cout<<"|"<<pos<<"° "<<final.front().nameR()<<" "<<final.front().VelocidadF()<<spacess<<"|"<<endl;    //se itera la lista y se imprime en formato
    pos++;
		final.pop();
	}
      
  cout<<"---------------------------------------------------------"<<endl;
    part.close();


    return 0;
}