#include <bits/stdc++.h>
using namespace std;

// Longest increasing subsequence

int main() {
    int N;
    cin >> N;
    int M[N + 1], X[N];
    memset(M, 0, sizeof M); // among all subsequence with length i, m(i) is the min value ending at the sequence
    memset(X, 0, sizeof X);
    for (int i = 0; i < N; i++) cin >> X[i];

    int L = 0;
    for (int i = 0; i < N; i++) { // loop through each character 
        int low = 1, high = L;
        while (low <= high) { // binary search 
            auto mid = (int) ceil((low + high) / 2);
            if (X[M[mid]] < X[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        M[low] = i;
        if (low > L) L = low;
    }
    cout << L << endl;
    return 0;
}
