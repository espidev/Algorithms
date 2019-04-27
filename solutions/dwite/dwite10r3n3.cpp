#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    vector<int> dp(32);
    dp[0] = 1;
    dp[2] = 3;
    for (int i = 2; i <= 30; i += 2) {
        dp[i] = 3*dp[i-2];
        for (int j = i-4; j >= 0; j -= 2) dp[i] += 2*dp[j];
        dp[i] %= 1000000;
    }

    for (int i = 0; i < 5; i++) {
        cin >> N;
        if (N%2 != 0) {
            cout << 0 << endl;
        } else {
            cout << dp[N] << endl;
        }
    }
    return 0;
}
