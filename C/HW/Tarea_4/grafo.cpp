#include "grafo.h"
#include <cmath>
#include <algorithm>
#include <iostream>



grafo:: grafo(int n): num_nodos(n), num_arcos(0), using_adj_list(true){
  //constructor, inicializo con el numero de nodos y arcos en 0 
  adj_list.resize(n, {0,0});
  adj_matrix.resize(n, std::vector<bool>(n,false));
}


void grafo::add_arco(int d, int h){
  std::cout<<"adding"<<std::endl;
  //Agrego arco de nodo d a nodo h
  if(using_adj_list){
    //Si uso lista de adyacencia agrego el arco
    adj_list[num_arcos]={d,h};
    //for ( auto i: adj_list) {for ( auto j: i){std::cout << j << ' ';}std::cout<<std::endl;}
  } 
  else {
    adj_matrix[d-1][h-1] = true;
    for ( auto i: adj_matrix) {for ( auto j: i){std::cout << j << ' ';}std::cout<<std::endl;}
  }
  num_arcos++;
  if (num_arcos>= (num_nodos * std::log2(num_nodos))){
    std::cout<<"switch"<<std::endl;
    //si el numero de arcos es >= al numero de nodos por el logaritmo de 2 de los nodos, entonces cambio de representacion a lista de adyacencias
    switch_to_matrix();
  }
    /*
  else if(num_arcos <=((num_nodos * std::log2(num_nodos)))/2){
    switch_to_list();
  }*/
}


int grafo::add_nodo(){
  //función agregar nodo, crea un nuevo nodo y lo agrega al final de la lista de nodos
  num_nodos++;
  if (using_adj_list){
    //si uso lista de adyacencia agrego un nuevo nodo
    adj_list.resize(num_nodos);
  }
  else{
    for (std::vector<bool>& row : adj_matrix){
      //agrega una fila a la matriz llena de false en caso de que no use lista de adyacencias
      row.push_back(false);
    }
    adj_matrix.push_back(std::vector<bool>(num_nodos, false));
    //agrega una columna a la matriz llena de false
  }
  return num_nodos;
}


bool grafo:: hay_arco(int d, int h){
  //función que verifica si hay arco entre nodos d y h
  if(using_adj_list){
    //si uso lista de adyacencia verifico si el nodo h esta en la lista de adyaecencia del nodo d
    for(int valor_de_la_lista : adj_list[d]){
      //recorro la lista de adyacencia del nodo d asignando el valor a la variable valor_de_la_lista 
      if(valor_de_la_lista == h){
        //si el valor de la lista interna es igual al nodo h entonces hay arco
        return true;
      }
    }
    return false;
  }
  else{
    return adj_matrix[d][h];
  }
}


void grafo::switch_to_matrix(){
  //función que cambia de representación a matriz
  adj_matrix.assign(num_nodos, std::vector<bool>(num_nodos, false));
  for(long unsigned int i = 0; i< adj_list.size(); i++){
    if (adj_list[i][0]!=0)
    adj_matrix[adj_list[i][0]-1][adj_list[i][1]-1] = true;
  }
  adj_list.clear();
  for ( auto i: adj_matrix) {for ( auto j: i){std::cout << j << ' ';}std::cout<<std::endl;}
  using_adj_list = false;
}


void grafo::switch_to_list(){
  //función que cambia de representación a lista de adyaecencia
  adj_list.clear();
  for(long unsigned int i = 0; i<adj_matrix.size(); i++){
    for(long unsigned int j=0; j<adj_matrix.size();j++)
      if(adj_matrix[i][j]){
        int x=i;
        int y=j;
        adj_list.push_back({x,y});
      }
    }
  adj_matrix.clear();
  using_adj_list=true;
}

bool grafo::hay_camino(int a, int b){
    std::vector<int> options={a};
    bool condition=false;
    if (!using_adj_list){
      int row=1;
      int column=1;
      for (long unsigned int counter=0; counter<adj_matrix[0].size();counter++){
          row=1;
          for (std::vector<bool> i: adj_matrix){
              column=1;
              for (int j:i){
                  for (int op:options){
                      //cout<<"row and op="<<row<<" "<<op<<" j="<<j<<" count= "<<(count(options.begin(), options.end(), row)==0)<<endl;
                      if ((row==op && column==b)&&j==true) return true;
                      else if (row==op && j==true && count(options.begin(), options.end(), column)==0) options.push_back(column);
                  }
                  column++;
              }
              row++;
          }
          //std::cout<<"size:\n->"<<options.size()<<std::endl;
      }
    }
    else {
      int row=1;
      int column=1;
      for (long unsigned int counter=0; counter<adj_matrix[0].size();counter++){
          row=1;
          for (std::vector<bool> i: adj_matrix){
              column=1;
              for (int j:i){
                  for (int op:options){
                      //cout<<"row and op="<<row<<" "<<op<<" j="<<j<<" count= "<<(count(options.begin(), options.end(), row)==0)<<endl;
                      if ((row==op && column==b)&&j==true) return true;
                      else if (row==op && j==true && count(options.begin(), options.end(), column)==0) options.push_back(column);
                  }
                  column++;
              }
              row++;
          }
          //std::cout<<"size:\n->"<<options.size()<<std::endl;
      }
    }
    return condition;
}
