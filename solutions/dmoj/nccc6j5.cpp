#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long


// Mock CCC 19 J5

int N, K, a, fish[2002], NL;
vector<int> v;
ull dp[2002][2002][2];

ull rec(int ind, int fishes, bool pickup) {
    if (dp[fishes][ind][pickup]) return dp[fishes][ind][pickup];
    if (fishes == K && pickup) return fish[v[ind]];
    if (NL - ind < K - fishes) return 0;
    if (ind >= NL-1 || fishes >= K) return 0;
    ull sum = 0;
    sum += rec(ind+1, fishes+1, true) % 998244353;
    sum += rec(ind+1, fishes, false) % 998244353;
    if (pickup) sum *= fish[v[ind]] % 998244353;
    dp[fishes][ind][pickup] = sum;
    return sum;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
    cin >> a;
    if (!fish[a]) {
        NL++;
        v.push_back(a);
    }
    fish[a]++;
    }
    cout << ((rec(0, 1, true) + rec(0, 0, false))%998244353) << endl;
}
