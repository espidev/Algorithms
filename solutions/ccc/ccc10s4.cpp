#include <bits/stdc++.h>
using namespace std;
int M, c, djs[101];

struct Edge {
    int a, b, w;
    Edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

struct Remem {
    int cost, node;
    Remem(int cost, int node) {
        this->cost = cost;
        this->node = node;
    }
};

int djfind(int node) {
    if (djs[node] != node) djs[node] = djfind(djs[node]);
    return djs[node];
}

void djmerge(int a, int b) {
    djs[djfind(a)] = djfind(b);
}
map<pair<int, int>, Remem> m;

int main() {
    for (int i = 0; i < 101; i++) djs[i] = i;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> M;

    vector<Edge> edges;

    set<pair<int, int>> s;
    for (int i = 0; i < M; i++) {
        cin >> c;
        int nodes[c+1];
        for (int j = 0; j < c; j++) cin >> nodes[j];        
        for (int j = 0; j < c; j++) {
            int cost;
            cin >> cost;
            pair<int, int> p;
            if (j == c-1) {
                p = make_pair(min(nodes[j], nodes[0]), max(nodes[j], nodes[0]));
            } else {
                p = make_pair(min(nodes[j], nodes[j+1]), max(nodes[j], nodes[j+1]));
            }
            auto d = s.find(p);
            if (d == s.end()) {
                m.insert(make_pair(p, Remem(cost, i+1)));
                s.insert(p);
            } else {
                auto l = m.find(p);
                int ecost = l->second.cost, enode = l->second.node;
                edges.push_back(Edge(i+1, enode, ecost));
                edges.push_back(Edge(enode, i+1, ecost));
                s.erase(d);
            }
        }
    }
    /*for (pair<int, int> p : s) {
        auto l = m.find(p);
        int ecost = l->second.cost, enode = l->second.node;
        edges.push_back(Edge(0, enode, ecost));
        edges.push_back(Edge(enode, 0, ecost));
    }*/

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w < b.w;
        });
    
    int ans = 0, ans2 = 0;
    for (Edge edge : edges) {
        if (djfind(edge.a) != djfind(edge.b)) {
            djmerge(edge.a, edge.b);
            ans += edge.w;
        }
    }

    for (pair<int, int> p : s) {
        auto l = m.find(p);
        int ecost = l->second.cost, enode = l->second.node;
        edges.push_back(Edge(0, enode, ecost));
        edges.push_back(Edge(enode, 0, ecost));
    }
    for (int i = 0; i < 101; i++) djs[i] = i;
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;       
    });

    for (Edge edge : edges) {
        if (djfind(edge.a) != djfind(edge.b)) {
            djmerge(edge.a, edge.b);
            ans2 += edge.w;
        }
    }

    printf("%d\n", min(ans, ans2));
}