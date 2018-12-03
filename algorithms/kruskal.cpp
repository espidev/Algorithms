#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;

struct edge {
    int a, b, w;
    edge (int a, int b, int w) {
        this->a = a, this->b = b, this->w = w;
    }
}

// disjoint set

int djs[MAXN], djrank[MAXN], N;

// find the id of an integer in the set (can compare findSet(x) == findSet(y))

int findSet(int x) { // get representative
    if (x != djs[x]) djs[x] = findSet(djs[x]); // compress path after going down
    return djs[x];
}

// merge two sets using a member

void mergeSet(int x, int y) {
    int px = findSet(x), py = findSet(y);
    if (px == py) return; // both sets already merged

    if (djrank[px] > djrank[py]) {
        djs[py] = px;
    } else {
        djs[px] = py;
    }
    if (djrank[px] == djrank[py]) djrank[py] = djrank[py] + 1;
}

vector<int> kruskal(vector<edge>& edges) {
    for (int i = 0; i < MAXN; i++) djs[i] = i; // init
    sort(edges.begin(), edges.end(), [](edge a, edge b) {
        return a.w < b.w;
    }); // sort with custom comparator for edge weights

    vector<int> mst; // minimum spanning tree edge indices
    for (int i = 0; i < edges.size(); i++) {
        if (findSet[edges[i].a] != findSet[edges[i].b]) {
            mergeSet(edges[i].a, edges[i].b);
            mst.push_back(edges[i]);
        }
    }
    return mst;
}

int main() {
    // test
    vector<edge> edges;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges.push_back(edge(a, b, w));
    }
    vector<int> mst = kruskal(edges); // run kruskal
    for (int i = 0; i < mst.size(); i++) printf("%d %d\n", mst.a, mst.b); // print edges
}