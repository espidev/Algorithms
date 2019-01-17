#include <bits/stdc++.h>

using namespace std;
int N, M, sx, sy;
string arr[102], ori[102];
int weight[102][102];
queue<pair<int, pair<int, int>>> pq;

void camera_set(int ax, int ay, int x, int y) {
    while (x >= 0 && x < N && y >= 0 && y < M && ori[x][y] != 'W') {
        if (arr[x][y] == '.' || arr[x][y] == 'S') arr[x][y] = 'W';
        x += ax;
        y += ay;
    }
}

void direction(int x, int y, int w) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if ((arr[x][y] == '.' || arr[x][y] == 'U' || arr[x][y] == 'D' || arr[x][y] == 'L' || arr[x][y] == 'R') && weight[x][y] > w) {
        weight[x][y] = w;
        pq.push(make_pair(w, make_pair(x, y)));
    }
}

int main() {
    scanf("%d %d", &N, &M);
    vector<pair<int, int>> cameras;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        ori[i] = arr[i];
        for (int j = 0; j < M; j++) {
            weight[i][j] = 1e9;
            switch (arr[i][j]) {
                case 'S':
                    sx = i;
                    sy = j;
                    break;
                case 'C':
                    cameras.emplace_back(i, j);
                    break;
            }
        }
    }

    for (pair<int, int> camera : cameras) {
        camera_set(1, 0, camera.first, camera.second);
        camera_set(-1, 0, camera.first, camera.second);
        camera_set(0, 1, camera.first, camera.second);
        camera_set(0, -1, camera.first, camera.second);
    }

    if (arr[sx][sy] == 'S') {
        direction(sx + 1, sy, 1);
        direction(sx - 1, sy, 1);
        direction(sx, sy + 1, 1);
        direction(sx, sy - 1, 1);

        while (!pq.empty()) {
            pair<int, int> coords = pq.front().second;
            switch (arr[coords.first][coords.second]) {
                case 'L':
                    direction(coords.first, coords.second - 1, pq.front().first);
                    break;
                case 'R':
                    direction(coords.first, coords.second + 1, pq.front().first);
                    break;
                case 'U':
                    direction(coords.first - 1, coords.second, pq.front().first);
                    break;
                case 'D':
                    direction(coords.first + 1, coords.second, pq.front().first);
                    break;
                case '.':
                    direction(coords.first + 1, coords.second, pq.front().first + 1);
                    direction(coords.first - 1, coords.second, pq.front().first + 1);
                    direction(coords.first, coords.second + 1, pq.front().first + 1);
                    direction(coords.first, coords.second - 1, pq.front().first + 1);
                    break;
            }
            pq.pop();
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ori[i][j] == '.') cout << ((weight[i][j] == 1e9) ? -1 : weight[i][j]) << endl;
        }
    }
    return 0;
}
