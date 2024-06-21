from grafo import *
from sys import getsizeof
def castellano(booleano):
    if not booleano :
        return "no "
    return ""
g=grafo(2) 
g.add_arco(1, 2)
g.add_arco(2, 1)
print(g.using_adj_list) 
print(g.hay_arco(2,1))
g.add_nodo() 
g.add_nodo()
g.add_arco(2, 3)
g.add_nodo()
print(g.add_nodo())
g.add_arco(4,6)
g.add_arco(3,4)
g.add_arco(6,5)
g.add_arco(6,3)
print(g.using_adj_list) 
print(g.hay_camino(1,7))
print(castellano(g.hay_camino(1,3)) + "hay camino entre los nodos 1 y 3")