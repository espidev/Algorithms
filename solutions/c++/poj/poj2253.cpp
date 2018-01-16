#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

/*
 * POJ2253 Froggy
 * Incomplete
 */

void dij(vector<int>& visited, queue<int>& q, vector<double>& vx, vector<pair<pair<int, int>, vector<double> > >& v) {
    if(q.empty()) return;
    int cur = q.front();
    q.pop();
    visited[cur] = true;
    //cout << cur << " " << v[cur].second.size() << endl;
    for(int i = 0; i < v[cur].second.size(); i++) {
        if(i == cur) continue;
        if(!visited[i]) q.push(i);
        double shortest = max(vx[cur], v[i].second[cur]);
        //cout << i << " " << vx[i] << " " << vx[cur] << " " << v[i].second[cur] << " " << shortest << endl;
        if(vx[i] == -1) {
            vx[i] = shortest;
        }
        else if(vx[i] > shortest) {
            vx[i] = shortest;
        }
    }
    dij(visited, q, vx, v);
}

int main() {
    int c = 1;
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        cout << "Scenario #" << c << endl;
        vector<pair<pair<int, int>, vector<double> > > v;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({{x, y}, vector<double>()});
        }
        for(int i = 0; i < n; i++) {
            int x = v[i].first.first, y = v[i].first.second;
            vector<double> dist;
            for(int j = 0; j < v.size(); j++) {
                pair<int, int> coord = v[j].first;
                dist.push_back(sqrt(pow(coord.first - x, 2) + pow(coord.second - y, 2)));
            }
            v[i].second = dist;
        }

        vector<double> vx(n, -1);
        vector<int> visited(n);
        queue<int> q;
        q.push(0);

        dij(visited, q, vx, v);

        std::cout << std::setprecision(3) << std::fixed;
        cout << "Frog Distance = " << vx[1] << endl;
        cout << endl;
        c++;
    }
    return 0;
}
