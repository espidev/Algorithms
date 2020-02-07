#include <bits/stdc++.h>
using namespace std;

int N, nums[401], psa[401], dp[401][401], ans;

int sum(int i, int j) {
    if (i == 0) return psa[j];
    return psa[j] - psa[i-1];
}

bool v(int i, int j) {
    //cout << i << " -> " << j << endl;
    if (dp[i][j] == -1) return false;
    if (dp[i][j]) return dp[i][j];
    if (j-i == 0 || j-i == 1 || j-i == 2) {
        if (nums[i] == nums[j]) {
            dp[i][j] = sum(i, j);
            ans = max(ans, dp[i][j]);
            //cout << i << ", " << j << " a: " << dp[i][j] << endl;
            return true;
        } else if (j-i == 0 || j-i == 1) {
            return false;
        }
    }

    for (int k = i; k < j; k++) {
        if (v(i, k) && v(k+1, j) && sum(i, k) == sum(k+1, j)) {
            dp[i][j] = sum(i, j);
            ans = max(ans, dp[i][j]);
            //cout << i << ", " << j << " b: " << dp[i][j] << endl;
            return true;
        }
        for (int l = k+1; l < j; l++) {
            if (v(i, k) && v(k+1, l) && v(l+1, j)) {
                if (sum(i, k) == sum(l+1, j)) {
                    dp[i][j] = sum(i, j);
                    ans = max(ans, dp[i][j]);
                    //cout << i << ", " << j << " c: " << dp[i][j] << endl;
                    return true;
                }
            }
            if (sum(i, k) > sum(l+1, j)) {
                break;
            }
        }
    }
    dp[i][j] = -1;
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        psa[i] = nums[i] + (i == 0 ? 0 : psa[i-1]);     
    }
    v(0, N-1);
    cout << ans << endl;
}