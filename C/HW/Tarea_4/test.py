from grafo import *
from sys import getsizeof
def castellano(booleano):
    if not booleano :
        return "no "
    return ""
g=grafo(2) 
g.add_arco(1, 2)
print(g.using_adj_list)
g.add_arco(2, 1) 
g.add_nodo() 
g.add_nodo()
g.add_arco(2, 3)
print(castellano(g.hay_camino(1,3)) + "hay camino entrelos nodos 1 y 3")