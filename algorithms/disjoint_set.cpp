#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;

// also known as Union-Find

int djs[MAXN], djrank[MAXN];

int init() {
    for (int i = 0; i < MAXN; i++) djs[i] = i;
}

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

