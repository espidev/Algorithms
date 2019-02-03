#include <bits/stdc++.h>

using namespace std;
int N, matrix[101][101];

// Floyd-Warshall Algorithm
// All-pairs shortest path
// Note: no detection for negative cycle in this implementation

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) { // input
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if (i != j) {
                if (!matrix[i][j]) {
                    matrix[i][j] = LONG_MAX;
                }
            }
        }
    }

    // Floyd-Warshall

    for (int r = 0; r < N; r++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] > matrix[i][r][1] + matrix[r][j] && (matrix[i][r] != LONG_MAX) && (matrix[r][j] != LONG_MAX)) { // OVERFLOW CHECK AAAAAAAA
                    matrix[i][j] = matrix[i][r][1] + matrix[r][j];
                    matrix[i][j] = (matrix[i][j][1] < 0) ? 0 : matrix[i][j];
                }
            }
        }
    }

    // Test Query
    cout << matrix[0][2] << endl; // shortest path from node 0 to node 2

    return 0;
}
