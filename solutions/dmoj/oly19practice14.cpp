include <bits/stdc++.h>
using namespace std;

int N, arr[1000002];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> N;

    unsigned long long sum = 0;
    stack<pair<int, int>> s; // num, ind

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        int prev = 0;
        while (!s.empty()) {
            if (s.top().first > arr[i]) {
                sum += (i-s.top().second-1) * (arr[i]-prev);
                break;
            } else {
                sum += (i-s.top().second-1) * (s.top().first-prev);
                prev = s.top().first;
                s.pop();
            }
        }
        s.push(make_pair(arr[i], i));
    }
    cout << sum << endl;
    return 0;
}
