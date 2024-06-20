// grafo.h
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>


class grafo {
public:
grafo(int n);
void add_arco(int d, int h);
int add_nodo();
bool hay_arco(int d, int h);
bool hay_camino(int a, int b);

public:
int num_nodos;
int num_arcos;
std::vector<std::vector<int>> adj_list;
std::vector<std::vector<bool>> adj_matrix;
bool using_adj_list;

void switch_to_matrix();
void switch_to_list();

//bool check(std::vector<int>& num, std::vector<std::vector<int>>& matriz);

//mi idea es que el vector visitados sea un vector de booleanos que tenga el mismo tamaño que el numero de nodos y voy revisando nodo a nodo si hay camino entre ellos, si hay camino, lo guardo en un vector de booleanos y si no hay camino, lo guardo en false

};

#endif // GRAFO_H
