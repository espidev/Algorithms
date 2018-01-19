#include <bits/stdc++.h>
using namespace std;

int T, G;
vector<int> p(4, 0);
vector<int> m[4];
vector<pair<int, int>> matches;

int getMax(vector<int>& pl) {
    int max = pl[0], index = 0;
    bool tie = false;
    for(int i = 1; i < pl.size(); i++){
        if(pl[i] == max) tie = true;
        if(pl[i] > max){
            index = i;
            max = pl[i];
            tie = false;
        }
    }
    if(tie) return -1;
    return index;
}

int dfs(vector<pair<int, int>> matchesl, vector<int> pl) {
    if(matchesl.empty()){
        /*for (int i : pl) {
            cout << i << " ";
        }
        cout << getMax(pl) << endl;*/
        if(getMax(pl) == T) {
            /*cout << "win ";
            for (int i : pl) {
                cout << i << " ";
            }
            cout << endl;*/
            return 1;
        }
        return 0;
    }
    int a = matchesl[0].first, b = matchesl[0].second, ac = pl[a], bc = pl[b], ret = 0;
    matchesl.erase(matchesl.begin());
    pl[a] += 3;
    ret += dfs(matchesl, pl);
    pl[a] = ac;
    pl[b] += 3;
    ret += dfs(matchesl, pl);
    pl[b] = bc;
    pl[a]++;
    pl[b]++;
    ret += dfs(matchesl, pl);
    return ret;
}

int main() {
    cin >> T >> G;
    T--;
    for(int i = 0; i < 4; i++) {
        m[i] = vector<int>(4);
    }
    for(int i = 0; i < G; i++) {
        int A, B, As, Bs;
        cin >> A >> B >> As >> Bs;
        m[A-1][B-1] = 1;
        m[B-1][A-1] = 1;
        if(As > Bs) {
            p[A-1] += 3;
        }
        else if (As < Bs) {
            p[B-1] += 3;
        }
        else {
            p[A-1] += 1;
            p[B-1] += 1;
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == j) continue;
            if(m[i][j] == 0) {
                matches.emplace_back(i, j);
                m[i][j] = 1;
                m[j][i] = 1;
            }
        }
    }
    cout << dfs(matches, p) << endl;
    return 0;
}
