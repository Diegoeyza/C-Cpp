#include "grafo.h"
#include <iostream>

using namespace std;

int main() {
  /*grafo g(5);
  g.add_arco(1, 2);
  g.add_arco(2, 3);
  g.add_arco(3, 4);
  g.add_arco(1, 4);
  cout << "hay arco entre 1 y 2: " << g.hay_arco(1, 2) << endl;
  cout << "hay arco entre 2 y 3: " << g.hay_arco(2, 3) << endl;
  cout << "hay arco entre 3 y 4: " << g.hay_arco(3, 4) << endl;

  cout << "agregando nodo" << endl;
  g.add_nodo();
  g.add_arco(4, 5);
  cout << "hay arco entre 4 y 5: " << g.hay_arco(4, 5) << endl;
  cout << "numero de nodos" << g.num_nodos << endl;*/
  // cout<<"hay camino entre 1 y 2: "<<g.check(1,2) <<endl;
  
  grafo g(2);
  g.add_arco(1, 2);
  cout<<(g.hay_camino(1,2))<<" hay camino entrelos nodos 1 y 2"<<endl;
  g.add_arco(2, 1);
  cout<<g.using_adj_list<<endl;
  g.add_nodo();
  g.add_nodo();
  g.add_arco(2, 3);
  cout<<(g.hay_camino(1,3))<<" hay camino entrelos nodos 1 y 3"<<endl;




  return 0;
}
