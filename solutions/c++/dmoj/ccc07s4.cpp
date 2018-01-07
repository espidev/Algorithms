#include <bits/stdc++.h>
using namespace std;

static int numPath[100000] = {0};
vector<int> v[10000];

int main() {
    int n;
    cin >> n;
    while (true) {
        int a1, a2;
        cin >> a1 >> a2;
        if(a1 == 0 && a2 == 0) {
            break;
        }
        v[a1].push_back(a2);
    }
    numPath[1] = 1;
    for(int k = 1; k < n+1; k++) {
        for(int d : v[k]) {
            numPath[d] += numPath[k];
        }
    }

    cout << numPath[n];
    return 0;
}