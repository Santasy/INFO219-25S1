#include <iostream>
#include <map>
#include <vector>

using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> h(n);
  vector<int> x(n);

  for (int i = 0; i < n; ++i)
    cin >> h[i];
  for (int i = 0; i < n; ++i)
    cin >> x[i];

  long long lo = 0, hi = 1e10;

  while (hi - lo > 1) {
    long long number_of_hits = (lo + hi) / 2;
    map<int, int> ev;

    for (int i = 0; i < n; ++i) {
      int expected_power = (h[i] + number_of_hits - 1) / number_of_hits;
      if (expected_power > m)
        continue;

      int start = x[i] - m + expected_power;
      int end = x[i] + m - expected_power + 1;
      ev[start] += 1;
      ev[end] -= 1;
    }

    int defeated = 0;
    bool ok = false;
    for (auto &[pos, delta] : ev) {
      defeated += delta;
      if (defeated >= k) {
        hi = number_of_hits;
        ok = true;
        break;
      }
    }

    if (!ok)
      lo = number_of_hits;
  }

  if (hi == 1e10)
    cout << -1 << endl;
  else
    cout << hi << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
