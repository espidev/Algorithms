#include <bits/stdc++.h>

#define ll long long
using namespace std;
int N;
vector<int> arr1, arr2;
unordered_map<ll, int> m1, m2;
vector<int> k1, k2;

// NOT COMPLETE
// 0 not chosen, 1 left, -1 right

void rec(vector<int> &ar, unordered_map<ll, int> &ma, vector<int>& v, int len, int ind, ll sum) {
    //cout << ind << " " << len << endl;
    if (ind == len) {
        if (sum < 0) return;
        auto d = ma.find(sum);
        if (d == ma.end()) {
            ma.insert(make_pair(sum, 1));
            v.push_back(sum);
        }
        else d->second++;
        return;
    }
    rec(ar, ma, v, len, ind + 1, sum + ar[ind]);
    rec(ar, ma, v, len, ind + 1, sum - ar[ind]);
    rec(ar, ma, v, len, ind + 1, sum);
}

int main() {
    scanf("%d", &N);
    int a;
    for (int i = 0; i < N / 2; i++) {
        scanf("%d", &a);
        arr1.push_back(a);
    }
    for (int i = N / 2; i < N; i++) {
        scanf("%d", &a);
        arr2.push_back(a);
    }

    rec(arr1, m1, k1, N / 2, 0, 0);
    rec(arr2, m2, k2, N - (N / 2), 0, 0);
    m1[0]--;
    m2[0]--;
    m1[0] /= 2;
    m2[0] /= 2;

    int ans = 0, i = 0;
    for (int i = 0; i < )

    cout << (ans + m1[0] + m2[0]) << endl;
    return 0;
}
