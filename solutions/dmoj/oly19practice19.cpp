#include <bits/stdc++.h>
using namespace std;

long long N, K, arr[1000002], ans = 0, sum = 0, n;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    memset(arr, -1, sizeof arr);
    arr[0] = 0;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> n;
        sum += n;
        sum %= K;
        if (arr[sum] >= 0) ans = max(ans, i-arr[sum]);
        else arr[sum] = i;
    }
    printf("%lld\n", ans);
    return 0;
}