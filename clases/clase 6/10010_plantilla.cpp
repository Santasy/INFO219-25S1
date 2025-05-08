#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve() {
  cin.ignore();

  int m, n;
  cin >> m >> n;

  char Matriz[m][n + 1];
  for (short j = 0; j < m; ++j) {
    for (short i = 0; i < n; ++i) {
      cin >> Matriz[j][i];
      char c = Matriz[j][i];
      c = tolower(c);
      transform(Matriz[j] + i, Matriz[j] + i + 1, Matriz[j] + i,
                [](char c) { return tolower(c); });
    }
    Matriz[j][n] = 0;
  }

  for (short j = 0; j < m; ++j) {
    cout << Matriz[j] << "\n";
  }
}

int main() {
  long t;
  cin >> t;
  cin.ignore();

  while (t--) {
    solve();
  }

  return 0;
}