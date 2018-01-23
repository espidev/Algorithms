#include <bits/stdc++.h>

using namespace std;

int N;
int v[5000];
unordered_map<int, vector<int>> sums;
int dums[5000];

/*
 * CCC17S3
 */

int main() {
    cin >> N;
    for (int i = 0, a; i < N; i++) {
        scanf("%i", &a);
        //cin >> a;
        //a = (rand()%600)+1;
        //cout << a << endl;
        v[a]++;
    }
    for (int i = 1; i < 5000; i++) {
        if (v[i]) {
            for (int j = i; j < 5000; j++) {
                if (i == j) {
                    dums[i + j] += v[i] / 2;
                } else if (v[j]) {
                    dums[i + j] += min(v[i], v[j]);
                }
            }
        }
    }
    int mSum = 0, nmSum = 0;
    for (int i = 0; i < 5000; i++) {
        if (dums[i] == mSum) {
            nmSum++;
        }
        if (dums[i] > mSum) {
            nmSum = 1;
            mSum = dums[i];
        }
    }
    cout << mSum << " " << nmSum << endl;
    return 0;
}

