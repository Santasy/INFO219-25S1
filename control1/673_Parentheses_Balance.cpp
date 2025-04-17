#include <cmath>
#include <cstddef>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve() {
  string s;
  getline(cin, s);
  stack<char> t;
  for (size_t i = 0; i < s.length(); ++i) {
    switch (s[i]) {
    case '(':
      t.push(s[i]);
      break;
    case ')':
      if (t.empty() || t.top() != '(')
        goto nope;
      t.pop();
      break;
    case '[':
      t.push(s[i]);
      break;
    case ']':
      if (t.empty() || t.top() != '[')
        goto nope;
      t.pop();
      break;
    }
  }
  if (t.empty()) {
    cout << "Yes\n";
    return;
  }
nope:
  cout << "No\n";
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