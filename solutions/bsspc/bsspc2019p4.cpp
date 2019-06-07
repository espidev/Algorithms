#include <bits/stdc++.h>
using namespace std;

int N, grid[101][101], visited[101][101];

bool check(int x, int y) {
    if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
        if (!grid[x][y] && !visited[x][y]) {
            return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    if (check(x+1, y)) dfs(x+1, y);
    if (check(x-1, y)) dfs(x-1, y);
    if (check(x, y+1)) dfs(x, y+1);
    if (check(x, y-1)) dfs(x, y-1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        grid[a][b] = true;
    }
    dfs(0, 0);
    cout << (visited[100][100] ? "y" : "n") << endl;
    return 0;
}