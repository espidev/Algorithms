// NOT PASSING YET!!! WA

#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int H, K;

int djs[MAXN], djrank[MAXN];

int findSet(int x) {
    if (x != djs[x]) {
        djs[x] = findSet(djs[x]);
    }
    return djs[x];
}

void mergeSet(int x, int y) {
    int px = findSet(x), py = findSet(y);
    if (djrank[px] > djrank[py]) {
        djs[py] = px;
    } else {
        djs[px] = py;
    }
    if (djrank[px] == djrank[py]) {
        djrank[py] = djrank[py] + 1;
    }
}

struct compare {
    bool operator() (const pair<int, pair<int, int>>& l, const pair<int, pair<int, int>>& r) {
        return l.first > r.first;
    }
};

vector<int> c(2001);
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare > edges;

int main() {
    for (int i = 0; i < 1000000; i++) {
        djs[i] = i;
    }

    cin >> H;
    for (int i = 0; i < H; i++) {
        cin >> c[i];
        c[i+H] = c[i];
    }
    cin >> K;
    if (K >= H) {
        cout << 0 << endl;
        return 0;
    }

    sort(c.begin(), c.begin() + H);

    edges.push(make_pair(1000000 + c[0] - c[H - 1], make_pair(c[H-1], c[0])));
    for (int i = 1; i < H; i++) {
        edges.push(make_pair(c[i] - c[i - 1], make_pair(c[i], c[i - 1])));
        //cout << "AA " << c[i] << " " << c[i-1] << endl;
        //printf("E: %d %d %d\n", edges.top().first, edges.top().second.first, edges.top().second.second);
    }

    int ck = H;

    while (ck > K) {
        //printf("Merge %d %d %d %d\n", edges.top().second.first, edges.top().second.second, findSet(edges.top().second.first), findSet(edges.top().second.second));
        mergeSet(edges.top().second.first, edges.top().second.second);
        ck--;
        edges.pop();
    }

    int bg = c[0], ed = 0, previd = findSet(c[0]), maxi = 1000001;

    for (int j = 0; j < H*2; j++) {
        int i = c[j];
        if (previd != findSet(i)) {
            //printf("%d %d\n", bg, ed);
            if (ed - bg != 0) maxi = min(min(maxi, (int)round((double)abs(1000000-ed+bg)/2)), min((int)round((double)abs(ed-bg)/2), (int)round((double)abs(bg-ed)/2)));
            bg = i;
            previd = findSet(i);
        } else {
            ed = i;
        }
    }
    //printf("%d %d\n", bg, ed);
    if (ed - bg != 0) maxi = min(min(maxi, (int)round((double)abs(1000000-ed+bg)/2)), min((int)round((double)abs(ed - bg)/2), (int)round((double)abs(bg-ed)/2)));
    if (maxi == 1000001) maxi = 0;

    cout << maxi << endl;

    return 0;
}
