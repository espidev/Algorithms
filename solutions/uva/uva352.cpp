#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> input;
vector<vector<int>> visited;

void eagles(int img, int x, int y){
    visited[x][y] = 1;
    if(x + 1 < input[img].size() && visited[x+1][y] != 1 && input[img][x+1][y] == 1){
        eagles(img, x+1, y);
    }
    if(y + 1 < input[img].size() && visited[x][y+1] != 1 && input[img][x][y+1] == 1){
        eagles(img, x, y+1);
    }
    if(x + 1 < input[img].size() && y + 1 < input[img].size() && visited[x+1][y+1] != 1 && input[img][x+1][y+1] == 1){
        eagles(img, x+1, y+1);
    }
    if(x - 1 >= 0 && visited[x-1][y] != 1 && input[img][x-1][y] == 1){
        eagles(img, x-1, y);
    }
    if(y - 1 >= 0 && visited[x][y-1] != 1 && input[img][x][y-1] == 1){
        eagles(img, x, y-1);
    }
    if(x - 1 >= 0 && y - 1 >= 0 && visited[x-1][y-1] != 1 && input[img][x-1][y-1] == 1){
        eagles(img, x-1, y-1);
    }
    if(x - 1 >= 0 && y + 1 < input[img].size() && visited[x-1][y+1] != 1 && input[img][x-1][y+1] == 1){
        eagles(img, x-1, y+1);
    }
    if(x + 1 < input[img].size() && y - 1 >= 0 && visited[x+1][y-1] != 1 && input[img][x+1][y-1] == 1){
        eagles(img, x+1, y-1);
    }
}

int main() {
    int iter = 0;
    int N;
    while(cin >> N) {
        vector<vector<int>> in(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                in[i][j] = s[j] - '0';
            }
        }
        input.push_back(in);

        visited.clear();
        for(int j = 0; j < N; j++){
            vector<int> donut(N, 0);
            visited.emplace_back(donut);
        }
        int ans = 0;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(visited[j][k] == 0 && input[iter][j][k] == 1){
                    eagles(iter, j, k);
                    ans++;
                }
            }
        }

        cout << "Image number " << (iter+1) << " contains " << ans << " war eagles." << endl;

        iter++;
    }
    return 0;
}
