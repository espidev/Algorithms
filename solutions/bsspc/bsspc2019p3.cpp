#include <bits/stdc++.h>
using namespace std;

int N, sc;
string s;
vector<pair<int, string>> v[3], insults;

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            cin >> s >> sc;
            v[i].push_back(make_pair(sc, s));
        }       
        sort(v[i].begin(), v[i].end());
    }   

    for (int i = max((int)v[0].size()-3, 0); i < v[0].size(); i++) 

        for (int j = max((int)v[1].size()-3, 0); j < v[1].size(); j++) 

            for (int k = max((int)v[2].size()-3, 0); k < v[2].size(); k++) 

                insults.push_back(make_pair(v[0][i].first + v[1][j].first + v[2][k].first, v[0][i].second + " " + v[1][j].second + " " + v[2][k].second));

    sort(insults.begin(), insults.end());

    cout << "1. " << insults[insults.size()-1].second << endl << "2. " << insults[insults.size()-2].second << endl << "3. " << insults[insults.size()-3].second << endl;
    return 0;
}
