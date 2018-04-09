#include <bits/stdc++.h>

using namespace std;
int N;

/*
 * Matrix Multiplication
 */

int main() {
    cin >> N;
    int a1[N][N], a2[N][N], result[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a1[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a2[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int sum = 0;
            for(int k = 0; k < N; k++) {
                sum += a1[i][k] * a2[k][j];
            }
            result[i][j] = sum;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << result[i][j] << ((j==N-1) ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}
