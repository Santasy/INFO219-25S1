#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve() {
  long n;
  cin >> n;

  long long c1 = 0, c2 = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    if (i % 2 == 0) { // Par
      c1 += v;
    } else { // Impar
      c2 += v;
    }
  }
  const long pares = (n + 1) >> 1;
  const long impares = n - pares;

  if (c1 % pares != 0 || c2 % impares != 0 || (c1 / pares != c2 / impares)) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
}

int main() {
  long t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}