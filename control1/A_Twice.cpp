#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> mvector;
typedef map<int, mvector> vmap;

void solve(){
    long n;
    cin >> n;

    int A[n];
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }

    sort(A, A + n);
    int score = 0;
    for(int i = 0; i < n-1; ++i){
        if(A[i] == A[i + 1]){
            ++score;
            ++i;
        }
    }
    cout << score << '\n';
}

int main(){
    long t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}