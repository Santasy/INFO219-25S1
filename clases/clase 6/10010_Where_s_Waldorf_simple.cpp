#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// All 8 directions: N, NE, E, SE, S, SW, W, NW
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve() {
  cin.ignore(2);
  short m, n;
  cin >> m >> n; // m lines, n chars per line

  char MZ[m][n + 1];
  for (short j = 0; j < m; ++j) {
    for (short i = 0; i < n; ++i) {
      cin >> MZ[j][i];
      MZ[j][i] = tolower(MZ[j][i]);
    }
  }

  short k;
  cin >> k;
  map<string, pair<short, short>> locations;
  vector<string> words;
  words.reserve(k);
  for (short i = 0; i < k; ++i) {
    string word;
    cin >> word;

    transform(word.begin(), word.end(), word.begin(),
              [](char c) { return tolower(c); });
    locations[word] = {-1, -1};
    words.push_back(word);
  }

  for (short j = 0; j < m; ++j) {
    for (short i = 0; i < n; ++i) {
      char c[2] = {MZ[j][i], 0};
      for (auto it : locations) {
        string w = it.first;
        if (w[0] > c[0])
          break;

        if (w[0] != c[0] || it.second.first != -1)
          continue;

        for (int d = 0; d < 8; ++d) {
          int x = i, y = j;
          bool match = true;

          for (int l = 0; l < w.size(); ++l) {
            int nx = x + dx[d] * l;
            int ny = y + dy[d] * l;

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || MZ[ny][nx] != w[l]) {
              match = false;
              break;
            }
          }

          if (match) {
            // +1 for 1-based index
            locations[w] = {j + 1, i + 1};
            break; // word found, skip other directions
          }
        }
      }
    }
  }

  for (const auto &w : words) {
    auto pos = locations[w];
    cout << pos.first << " " << pos.second << "\n";
  }
}

int main() {
  long t;
  cin >> t;

  while (t--) {
    solve();
    if (t > 0)
      cout << endl;
  }

  return 0;
}