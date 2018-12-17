#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int P[N], M[N + 1], X[N];
    memset(P, 0, sizeof P);
    memset(M, 0, sizeof M);
    memset(X, 0, sizeof X);
    for (int i = 0; i < N; i++) cin >> X[i];
    int L = 0;
    for (int i = 0; i < N; i++) {
        int low = 1, high = L;
        while (low <= high) {
            auto mid = (int) ceil((low + high) / 2);
            if (X[M[mid]] < X[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int newLow = low;
        P[i] = M[newLow - 1];
        M[newLow] = i;
        if (newLow > L) {
            L = newLow;
        }
    }
    int S[L];
    int k = M[L];
    for (int i = L - 1; i > -1; i--) {
        S[i] = X[k];
        k = P[k];
    }
    cout << L << endl;
    return 0;
}
