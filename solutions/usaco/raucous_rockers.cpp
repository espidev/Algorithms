#include <bits/stdc++.h>
using namespace std;

int N, T, M, out = 0;

int v[20];

int main() {
    cin >> N >> T >> M;
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < (1 << N); i++) {
        bool verify = true;
        int songs = 0, disks = 0, cur = 0;
        for (int j = 0; j < N; j++) {
            if (i & (1<<j)) {
                if (v[j] > T) {
                    verify = false;
                    break;
                }
                if(cur + v[j] > T) {
                    cur = v[j];
                    disks++;
                } else {
                    cur += v[j];
                }
                songs++;
            }
        }
        if (cur > 0) disks++;
        if (verify && disks <= M) {
            out = max(out, songs);
        }
    }
    cout << out << endl;
    return 0;
}
