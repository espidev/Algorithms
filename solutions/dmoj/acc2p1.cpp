#include <bits/stdc++.h>

using namespace std;
#define INFINITY LONG_MAX
long long N, Q, a, b, c, matrix[101][101][101];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) { // input
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j][1];
            if (i != j) {
                if (!matrix[i][j][1]) {
                    matrix[i][j][1] = INFINITY;
                }
            }
            for (int k = 2; k <= N; k++) matrix[i][j][k] = INFINITY;
        }
    }

    for (int r = 0; r < N; r++) { // precompute shortest
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j][1] > matrix[i][r][1] + matrix[r][j][1] && (matrix[i][r][1] != INFINITY) && (matrix[r][j][1] != INFINITY)) { // OVERFLOW CHECK AAAAAAAA
                    matrix[i][j][1] = matrix[i][r][1] + matrix[r][j][1];
                    matrix[i][j][1] = (matrix[i][j][1] < 0) ? 0 : matrix[i][j][1];
                }
            }
        }
    }
    for (int d = 2; d <= N; d++) { // dp the days
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                long long m = INFINITY;
                for (int k = 0; k < N; k++) {
                    m = min(m, max(matrix[i][k][d - 1], matrix[k][j][1]));
                }
                matrix[i][j][d] = m;
            }
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        printf("%lli\n", (matrix[a - 1][b - 1][c] == INFINITY) ? 0 : matrix[a - 1][b - 1][c]);
    }
    return 0;
}
