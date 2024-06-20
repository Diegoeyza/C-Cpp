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

bool using_adj_list;

private:
int num_nodos;
int num_arcos;
std::vector<std::vector<int>> adj_list;
std::vector<std::vector<int>> adj_matrix;


void switch_to_matrix();
void switch_to_list();

};

#endif // GRAFO_H
