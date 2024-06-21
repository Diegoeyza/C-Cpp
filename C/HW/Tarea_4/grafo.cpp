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
  if (using_adj_list) {
    adj_list[d - 1].push_back(h);
  } else {
    adj_matrix[d-1][h-1] = true;
  }
  num_arcos++;
  if (num_arcos >= (num_nodos * std::log2(num_nodos)) && using_adj_list) {
    switch_to_matrix();
  }
  
  else if(num_arcos <=((num_nodos * std::log2(num_nodos)))/2 && !using_adj_list){
    switch_to_list();
  }
}


int grafo::add_nodo(){
  num_nodos++;
  if (using_adj_list){
    adj_list.resize(num_nodos);
  }
  else{
    for (std::vector<int>& row : adj_matrix){
      row.push_back(false);
    }
    adj_matrix.push_back(std::vector<int>(num_nodos, 0));
  }

  if (num_arcos >= (num_nodos * std::log2(num_nodos)) && using_adj_list) {
    switch_to_matrix();
  }
  
  else if(num_arcos <=((num_nodos * std::log2(num_nodos)))/2 && !using_adj_list){
    switch_to_list();
  }
  return num_nodos;
}


bool grafo:: hay_arco(int d, int h){
  if(using_adj_list){
    for(int valor_de_la_lista : adj_list[d-1]){
      if(valor_de_la_lista == h){
        return true;
      }
    }
    return false;
  }
  else{
    return adj_matrix[d-1][h-1];
  }
}


void grafo::switch_to_matrix(){
  adj_matrix.resize(num_nodos+1, std::vector<int>(num_nodos+1,0));
  adj_matrix.assign(num_nodos, std::vector<int>(num_nodos, 0));
  for(long unsigned int i = 0; i< adj_list.size(); i++){
    for(long unsigned int j = 0; j< adj_list[i].size(); j++){
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
  for(long unsigned int i = 0; i<adj_matrix.size(); i++){
    for(long unsigned int j=0; j<adj_matrix.size();j++)
      if(adj_matrix[i][j]){
        int x=i;
        int y=j+1;
        adj_list[x].push_back(y);
      }
    }
  adj_matrix.clear();
  using_adj_list=true;
}

bool grafo::hay_camino(int a, int b){
    std::vector<int> used_options={a};
    std::vector<int> new_options={};
    std::vector<int> options={a};
    if (!using_adj_list){
      int row=1;
      int column=1;
      while(options.size()!=0){
        row=1;
        for (std::vector<int> i: adj_matrix){
            column=1;
            for (int j:i){
                for (int op:options){
                    if ((row==op && column==b)&&j==true) return true;
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
    return false;
}
