#include <bits/stdc++.h>

/*
 * CCC04S3 Spreadsheet
 */

using namespace std;

vector<pair<int, int>> m[11][10];
int vr[11][10], visited[11][10];

void dfs(int x, int y) {
    visited[x][y] = true;
    int sum = 0;
    for (pair<int, int> p : m[x][y]) {
        if (vr[p.first][p.second] != -2 && vr[p.first][p.second] != -1) {
            sum += vr[p.first][p.second];
        } else if (visited[p.first][p.second] || vr[p.first][p.second] == -1) {
            sum = -1;
            break;
        } else {
            dfs(p.first, p.second);
            if (vr[p.first][p.second] == -1) {
                sum = -1;
                break;
            }
            sum += vr[p.first][p.second];
        }
    }
    vr[x][y] = sum;
}

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            string s;
            cin >> s;
            if (s[0] >= 'A' && s[0] <= 'J') {
                vector<pair<int, int>> v;
                for (int k = 0; k < s.length(); k += 3) {
                    int a = s[k] - 'A' + 1, b = s[k + 1] - '0';
                    v.emplace_back(a, b);
                    if (k + 2 == s.length()) {
                        break;
                    }
                }
                m[i][j] = v;
                vr[i][j] = -2;
            } else {
                m[i][j] = vector<pair<int, int>>();
                vr[i][j] = stoi(s);
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!m[i][j].empty() && vr[i][j] == -2) {
                memset(visited, false, 110);
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) {
            string o = to_string(vr[i][j]);
            if (vr[i][j] == -1) o = "*";
            cout << o << " ";
        }
        cout << endl;
    }
    return 0;
}
