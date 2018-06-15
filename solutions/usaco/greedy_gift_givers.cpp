#include <bits/stdc++.h>

/*
 * USACO
 * Greedy Gift Givers
 */

using namespace std;

int NP;

vector<pair<string, int>> m;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    fin >> NP;
    for(int i = 0; i < NP; i++) {
        string name;
        fin >> name;
        m.emplace_back(name, 0);
    }
    for(int i = 0; i < NP; i++) {
        string name;
        int give, numPeople;
        fin >> name >> give >> numPeople;
        for (auto &k : m) {
            if(k.first == name) {
                k.second -= give;
                break;
            }
        }
        if(numPeople != 0) {
            for (auto &k : m) {
                if(k.first == name) {
                    k.second += give % numPeople;
                    break;
                }
            }
        }
        for(int j = 0; j < numPeople; j++) {
            fin >> name;
            for (auto &k : m) {
                if(k.first == name) {
                    k.second += give / numPeople;
                    break;
                }
            }
        }
    }
    for(pair<string, int> p : m) {
        fout << p.first + " " + to_string(p.second) << endl;
    }
    return 0;
}
