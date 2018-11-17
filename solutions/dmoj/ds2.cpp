#include <bits/stdc++.h>
#define MAXN 200001
using namespace std;
int djs[MAXN], djrank[MAXN], N, M;

int findSet(int x) { //get representative
    if (x != djs[x]) {
        djs[x] = findSet(djs[x]);
    }
    return djs[x];
}

void mergeSet(int x, int y) {
    int px = findSet(x);
    int py = findSet(y);
    if (djrank[px] > djrank[py]) {
        djs[py] = px;
    } else {
        djs[px] = py;
    }
    if (djrank[px] == djrank[py]) {
       djrank[py] = djrank[py] + 1;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++) djs[i] = i;
    vector<int> output;
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (findSet(a) != findSet(b)) {
            mergeSet(findSet(a), findSet(b));
            output.push_back(i+1);
        }
    }
    for (int i = 1; i < N; i++) {
        if (findSet(i) != findSet(i+1)) {
            printf("Disconnected Graph\n");
            return 0;
        }
    }
    for (int i = 0; i < output.size(); i++) printf("%d\n", output[i]);
}