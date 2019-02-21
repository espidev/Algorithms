#include <bits/stdc++.h>
using namespace std;

int omatrix[1002][1002], nmatrix[1001][1001];
int R, S;

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        cin >> R >> S;
        for (int i = 0; i < R; i++) {
                for (int j = 0; j < S; j++) {
                        cin >> omatrix[i][j];
                }
        }
        for (int i = 0; i < R-1; i++) {
                for (int j = 0; j < S-1; j++) {
                        if (omatrix[i][j] + omatrix[i+1][j+1] <= omatrix[i+1][j] + omatrix[i][j+1]) {
                                nmatrix[i][j] = 1;
                        }
                }
        }
        int v[S+1], largestArea = 0; // v is histogram
        for (int i = 0; i < S; i++) v[i] = 0;
        for (int i = 0; i < R; i++) {
                for (int k = 0; k < S; k++) {
                        if (nmatrix[i][k]) v[k+1]++;
                        else v[k+1] = 0;
                }
                stack<int> s;
                // histogram area algorithm
                for (int j = 1; j <= S; j++) {
                        while  (!s.empty() && v[s.top()] >= v[j]) {
                                int id = s.top();
                                s.pop();
                                if (s.empty()) {
                                        largestArea = max(largestArea, j*(v[id]+1));
                                } else {
                                        largestArea = max(largestArea, (j-s.top())*(v[id]+1));
                                }
                        }
                        s.push(j);
                }
                while (!s.empty()) {
                        int id = s.top();
                        s.pop();
                        if (s.empty()) largestArea = max(largestArea, S*(v[id]+1));
                        else largestArea = max(largestArea, (S-s.top())*(v[id]+1));
                }
        }
        cout << largestArea << endl;
}