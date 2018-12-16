#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <stdio.h>

using namespace std;

// POJ 2253: Frogger
// Simple dijkstra

int main() {
    int N, x = 1;
    cin >> N;
    while (N != 0) {
        vector<double> graph[N];
        vector<pair<int, int> > coords;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            coords.push_back(make_pair(a, b));
        }
        for (int i = 0; i < N; i++) {
            graph[i] = vector<double>(N);
            for (int j = 0; j < N; j++) {
                graph[i][j] = sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2));
            }
        }

        double dist[N+1];
        for (int i = 0; i < N; i++) dist[i] = 1000000.0;
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            for (int i = 0; i < N; i++) {
                if (i == q.front()) continue;
                if (dist[i] > max(dist[q.front()], graph[q.front()][i])) {
                    dist[i] = max(dist[q.front()], graph[q.front()][i]);
                    q.push(i);
                }
            }
            q.pop();
        }

        cout << "Scenario #" << x << endl;
        printf("Frog Distance = %.3f", dist[1]);
        cout << endl << endl;
        cin >> N;
        x++;
    }
    return 0;
}
