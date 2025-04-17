#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

int ancestor(int i) { return (i - 1) / 2; }

int left(int i) { return (2 * i + 1); }

int right(int i) { return (2 * i + 2); }

// Se pueden usar dos versiones:
// 1) Con un struct que va a ser ordenado: heap de structs -> O(8*N)
// 2) Con arreglos paralelos: arr contador + heap de indices -> O(4*N) + O(4*N)
struct node {
  int id;
  int wins = 0;

  bool operator<(const node &other) const { return this->wins < other.wins; }
  bool operator>(const node &other) const { return this->wins > other.wins; }
};
// this < other

void minHeapify(int *arr, int n, int i) {
  int iswap = i;
  int l = left(i), r = right(i);

  if (l < n && arr[l] < arr[iswap])
    iswap = l;

  if (r < n && arr[r] < arr[iswap])
    iswap = r;

  if (iswap != i) {
    int temp = arr[i];
    arr[i] = arr[iswap];
    arr[iswap] = temp;
    minHeapify(arr, n, iswap);
  }
}

void minNodesHeapify(node *arr, int n, int i) {
  int iswap = i;
  int l = left(i), r = right(i);

  if (l < n && arr[l] < arr[iswap])
    iswap = l;

  if (r < n && arr[r] < arr[iswap])
    iswap = r;

  if (iswap != i) {
    node temp = arr[i];
    arr[i] = arr[iswap];
    arr[iswap] = temp;
    minNodesHeapify(arr, n, iswap);
  }
}

void constructMinHeap(int *arr, int n) {
  int ix = n - 1; // Empiezo desde el ultimo nodo interno (con hijos)
  int last_ancestor = ancestor(ix);
  for (int i = last_ancestor; i >= 0; --i) {
    minHeapify(arr, n, i);
  }
}

void constructMinNodeHeap(node *arr, int n) {
  int ix = n - 1; // Empiezo desde el ultimo nodo interno (con hijos)
  int last_ancestor = ancestor(ix);
  for (int i = last_ancestor; i >= 0; --i) {
    minNodesHeapify(arr, n, i);
  }
}

void insertInMinNodeHeap(node *arr, int &size, int q, node student) {
  if (size < q) {
    arr[size] = student;
    int anc = ancestor(size);
    ++size;
    minNodesHeapify(arr, size, anc);
    return;
  }

  // Se pregunta si es que el nuevo debe reemplazar al peor competidor
  if (student.wins > arr[0].wins) {
    arr[0] = student; // Esta es la cabeza del heap
    minNodesHeapify(arr, q, 0);
  }
}

void solve() {
  long n, q;
  cin >> n >> q;

  int *arr =
      new int[n]; // Contadores para cada estudiante (cantidad de victorias)
  for (int i = 0; i < n; ++i) {
    int ix;
    cin >> ix;
    --ix;
    arr[ix]++;
  }

  // Minheap
  node *heap = new node[q];
  int size = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 0) // Si no hay victorias, se omite
      continue;
    insertInMinNodeHeap(heap, size, q, node{i + 1, arr[i]});
  }

  // OJO: Aqui falta entregar el resultado en orden descendente:
  // 1) Hacen un sort.
  // 2) Hacen otro maxheap, y van rescatando la raiz (el maximo) de uno en uno.
  sort(heap, heap + q, greater<node>());
  for (int i = 0; i < q; ++i) {
    // printf("[%d, %d]\n", heap[i].id, heap[i].wins);
    cout << heap[i].id << '\n';
  }
}

int main() {
  long t = 1;
  // cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}