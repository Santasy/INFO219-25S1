/// This code comes from uva debug!

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
#define _SKIP_LINE_                                                            \
  do {                                                                         \
    scanf("%*[^\n]");                                                          \
    getc(stdin);                                                               \
  } while (0)

const short gsize = 100;
char GRID[gsize + 1][gsize + 2];
short M, N, W;
vector<string> words;
typedef pair<short, short> Pos;

struct Compare {
  bool operator()(const Pos &lhs, const Pos &rhs) const {
    if (lhs.first == rhs.first)
      return lhs.second < rhs.second;
    else
      return lhs.first < rhs.first;
  }
};

typedef set<Pos, Compare> Positions;

map<char, Positions> Hash;

void print() {
  for (short i = 1; i <= M; ++i) {
    for (short j = 1; j <= N; ++j)
      cout << GRID[i][j];
    cout << endl;
  }
  copy(words.begin(), words.end(), ostream_iterator<string>(cout, "\n"));
}

void Search(const string &word) {
  Positions::const_iterator p = Hash[word[0]].begin();
  Positions::const_iterator end = Hash[word[0]].end();
  Positions::const_iterator prev = end;
  short n = word.size();
  const char *w = word.c_str();
  short x = 0;
  short r = 0;
  short c = 0;
  while (p != prev && p != end) {
    const short i = p->first;
    const short j = p->second;
    prev = p;
    switch (1) {
    // right
    case 1:
      if (j + n - 1 <= N && strncmp(GRID[i] + j, w, n) == 0)
        break;
    // left
    case 2:
      if (j - n + 1 >= 1) {
        for (c = j, x = 0; c > 0 && x < n; --c, ++x)
          if (GRID[i][c] != w[x])
            break;
        if (x == n)
          break;
      }
    // down
    case 3:
      if (i + n - 1 <= M) {
        for (r = i, x = 0; r < i + n; ++r, ++x)
          if (GRID[r][j] != w[x])
            break;
        if (x == n)
          break;
      }
    // up
    case 4:
      if (i - n + 1 >= 1) {
        for (r = i, x = 0; r > 0 && x < n; --r, ++x)
          if (GRID[r][j] != w[x])
            break;
        if (x == n)
          break;
      }
    // up right digonal
    case 5:
      if (i - n + 1 >= 1 && j + n - 1 <= N) {
        for (r = i, c = j, x = 0; r > 0 && c < j + n; --r, ++c, ++x)
          if (GRID[r][c] != w[x])
            break;
        if (x == n)
          break;
      }
    // down right digonal
    case 6:
      if (i + n - 1 <= M && j + n - 1 <= N) {
        for (r = i, c = j, x = 0; r < i + n && c < j + n; ++r, ++c, ++x)
          if (GRID[r][c] != w[c - j])
            break;
        if (x == n)
          break;
      }
    // up left digonal
    case 7:
      if (i - n + 1 >= 1 && j - n + 1 >= 1) {
        for (r = i, c = j, x = 0; r > 0 && c > 0 && x < n; --r, --c, ++x)
          if (GRID[r][c] != w[x])
            break;
        if (x == n)
          break;
      }
    // down left digonal
    case 8:
      if (i + n - 1 <= M && j - n + 1 >= 1) {
        for (r = i, c = j, x = 0; r < i + n && c > 0; ++r, --c, ++x)
          if (GRID[r][c] != w[r - i])
            break;
        if (x == n)
          break;
      }
    default:
      ++p;
    }
  }
  if (p == end)
    cout << 0 << " " << 0 << endl;
  else
    cout << p->first << " " << p->second << endl;
}

/* main
 *  * */
int main() {
  short test_cases = 0;
  cin >> test_cases;
  while (test_cases > 0 && cin.eof() != true) {
    cin >> M >> N;
    _SKIP_LINE_;
    Hash.clear();
    // READ and Hash GRID
    for (short r = 1; r <= M; ++r) {
      for (short c = 1; c <= N; ++c) {
        cin >> GRID[r][c];
        GRID[r][c] = ::tolower(GRID[r][c]);
        Hash[GRID[r][c]].insert(make_pair(r, c));
      }
      GRID[r][N + 1] = '\0';
      _SKIP_LINE_;
    }
    // READ WORD
    cin >> W;
    _SKIP_LINE_;
    words.clear();
    words.resize(W);
    for (short c = 0; c < W; ++c) {
      getline(cin, words[c]);
      transform(words[c].begin(), words[c].end(), words[c].begin(), ::tolower);
    }
    for_each(words.begin(), words.end(), Search);
    if (--test_cases > 0)
      cout << endl;
  }
  return 0;
}