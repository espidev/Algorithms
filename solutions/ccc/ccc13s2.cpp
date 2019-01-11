#include <bits/stdc++.h>
using namespace std;
int W, N, sum = 0, in;

int main() {
    scanf("%d %d", &W, &N);
    queue<int> q;
    for (int i = 0; i < N; i++) {
        scanf("%d", &in);
        q.push(in);
        sum += in;
        if (q.size() > 4) {
            sum -= q.front();
            q.pop();
        }
        if (sum > W) {
            cout << i << endl;
            return 0;
        }
    }
    cout << N << endl;
    return 0;
}

