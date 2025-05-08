#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve() {
  int tiendas;
  cin >> tiendas;

  // Leer arreglo de valores
  int precios[tiendas];
  for (int i = 0; i < tiendas; ++i) {
    cin >> precios[i];
  }

  sort(precios, precios + tiendas);

  // Leer q
  int q;
  cin >> q;

  // Leer m_i, y responder para cada m_i
  while (q--) {
    int presupuesto;
    cin >> presupuesto;

    // ¿Cuántas tiendas se pueden con el presupuesto?

    // Esta buscando el upper bound
    int *it = upper_bound(precios, precios + tiendas, presupuesto);
    int pos = it - precios;
    cout << pos << "\n";
  }
}

int main() {
  solve();
  return 0;
}