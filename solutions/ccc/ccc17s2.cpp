#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v.size()%2 == 0) {
        for (int i = 0; i < v.size()/2; i++) {
            cout << v[v.size()/2-1-i] << " " << v[v.size()/2+i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < v.size()/2; i++) {
            cout << v[v.size()/2-i] << " " << v[v.size()/2+1+i] << " ";
        }
        cout << v[0] << endl;
    }
    return 0;
}
