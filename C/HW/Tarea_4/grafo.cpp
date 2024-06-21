#include "grafo.h"
#include <cmath>
#include <algorithm>
#include <iostream>



grafo:: grafo(int n){
  num_nodos=n;
  num_arcos=0;
  using_adj_list=true;
  adj_list.resize(n, {0});
}


void grafo::add_arco(int d, int h) {
  if (d<1 || d>num_nodos || h<1 || h>num_nodos) {std::cout<<"El arco no ha podido ser creado, revisar que los valores no sean mayores que la cantidad de nodos o menores que 1"<<std::endl;}
  //Agrega arco al grafo según que tipo de representación se usa
  else{
    if (using_adj_list) {
      adj_list[d - 1].push_back(h);
    } else {
      adj_matrix[d-1][h-1] = true;
    }
    num_arcos++;

    //Condiciones de cambio de representaciones internas del grafo
    if (num_arcos >= (num_nodos * std::log2(num_nodos)) && using_adj_list) {
      switch_to_matrix();
    }
    
    else if(num_arcos <=((num_nodos * std::log2(num_nodos)))/2 && !using_adj_list){
      switch_to_list();
    }
  }
}


int grafo::add_nodo(){
  //Agregar nodo al grafo, crea un nodo y lo agrega al final de la lista
  num_nodos++;
  if (using_adj_list){
    adj_list.resize(num_nodos);
  }
  else{
    for (std::vector<int>& row : adj_matrix){
      //Agrega una fila a la matriz llena de ceros
      row.push_back(false);
    }
    //Agrega una columna a la matriz llena de ceros
    adj_matrix.push_back(std::vector<int>(num_nodos, 0));
  }

  //Reviso la condición de la representación del grafo
  if (num_arcos >= (num_nodos * std::log2(num_nodos)) && using_adj_list) {
    switch_to_matrix();
  }
  
  else if(num_arcos <=((num_nodos * std::log2(num_nodos)))/2 && !using_adj_list){
    switch_to_list();
  }
  return num_nodos;
}


bool grafo:: hay_arco(int d, int h){
  //Reviso que no se busque un arco inexistente
  if (d<1 || d>num_nodos || h<1 || h>num_nodos) {std::cout<<"El arco no ha podido ser encontrado, revisar que los valores no sean mayores que la cantidad de nodos o menores que 1"<<std::endl; return false;}
  else{
    if(using_adj_list){
      //Si se usa la lista, verifico si el nodo h está en la lista del nodo d
      for(int valor_de_la_lista : adj_list[d-1]){
        if(valor_de_la_lista == h){
          //Si el valor de la lista es igual al valor del nodo h, retorno true
          return true;
        }
      }
      return false;
    }
    else{
      //Retorna el valor la posición de la matriz para ver la existencia del arco
      return bool(adj_matrix[d-1][h-1]);
    }
  }
}


void grafo::switch_to_matrix(){
  //creo la matriz
  adj_matrix.resize(num_nodos+1, std::vector<int>(num_nodos+1,0));
  adj_matrix.assign(num_nodos, std::vector<int>(num_nodos, 0));
  //recorro la lista
  for(long unsigned int i = 0; i< adj_list.size(); i++){
    for(long unsigned int j = 0; j< adj_list[i].size(); j++){
    //asigno cada arco de la lista a la matriz
    if (adj_list[i][j]!=0)
    adj_matrix[i][adj_list[i][j]-1] = true;
    }
  }
  adj_list.clear();
  using_adj_list = false;
}


void grafo::switch_to_list(){
  adj_list.clear();
  adj_list.resize(num_nodos);
  //Recorro la matriz 
  for(long unsigned int i = 0; i<adj_matrix.size(); i++){
    for(long unsigned int j=0; j<adj_matrix.size();j++)
      //Si el valor de la matriz es 1, se agrega el nodo j+1 a la lista del nodo i
      if(adj_matrix[i][j]){
        int x=i;
        int y=j+1;
        //Se le suma 1 porque el nodo 0 no existe
        adj_list[x].push_back(y);
      }
    }
  adj_matrix.clear();
  using_adj_list=true;
}

bool grafo::hay_camino(int a, int b){
    if (a<1 || a>num_nodos || b<1 || b>num_nodos) {std::cout<<"El camino no ha podido ser verificado, revisar que los valores no sean mayores que la cantidad de nodos o menores que 1"<<std::endl; return false;}
    else{
      //se crean 3 vectores, para optimizar más el código, el primero guarda los caminos ya revisados, y los otros 2 son caminos válidos a revisar
      std::vector<int> used_options={a};
      std::vector<int> new_options={};
      std::vector<int> options={a};
      //verifico si uso matriz o lista
      if (!using_adj_list){
        int row=1;
        int column=1;
        //se verifica que continue hasta que llegue a un camino que ya haya revisado
        while(options.size()!=0){
          row=1;
          for (std::vector<int> i: adj_matrix){
            column=1;
            for (int j:i){
              for (int op:options){
                //retorno true si esque encuentro el objetivo en mi camino actual
                if ((row==op && column==b)&&j==true) return true;
                //verifico si esque el valor que estoy leyendo no es un camino que ya haya tomado y si no lo es lo agrego a las opciones
                else if (row==op && j==true && count(used_options.begin(), used_options.end(), column)==0) new_options.push_back(column);
              }
              column++;
            }
            row++;
          }
          for (int i:options) if(count(used_options.begin(), used_options.end(), i)==0) used_options.push_back(i);
          options=new_options;
          new_options={};
        }
      }
      else {
        while(options.size()!=0){
          for (int op:options){
            for (long unsigned int counter=0; counter<adj_list[op-1].size();counter++){
              if (adj_list[op-1][counter]==b) return true;
              else if (count(used_options.begin(), used_options.end(), adj_list[op-1][counter])==0) new_options.push_back(adj_list[op-1][counter]);
            }
            for (int i:options) if(count(used_options.begin(), used_options.end(), i)==0) used_options.push_back(i);
            options=new_options;
            new_options={};
          }
        }
      }
      //retorno false si luego de hacer todos los caminos posibles no llego al punto deseado
      return false;
    }
}


