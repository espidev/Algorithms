#include <stdio.h>

using namespace std;

int N, Q, a, b, c, d, segtree[10001 * 2 + 1], lazy[10001 * 2 + 1];

void push_down_lazy(int node, int l, int r) {
    if (l == r) {
        segtree[node] += lazy[node] * (r - l);
    } else {
        int mid = (r + l) / 2;
        lazy[node * 2] += lazy[node] * (mid - l);
        lazy[node * 2 + 1] += lazy[node] * (r - (mid+1));
        segtree[node] = lazy[node*2] + segtree[node*2] + segtree[node*2+1] + lazy[node*2+1];
    }
    lazy[node] = 0;
}

void update(int l, int r, int cur, int b, int e, int add) {
    push_down_lazy(cur, l, r);
    if (l > e || r < b) return;
    if (l >= b && r <= e) {
        if (l == r) segtree[cur] += add;
        else lazy[cur] += add;
        return;
    }
    int mid = (l + r) / 2;
    update(l, mid, cur * 2, b, e, add);
    update(mid + 1, r, cur * 2 + 1, b, e, add);
    segtree[cur] = segtree[cur*2] + segtree[cur*2+1];
}

int query(int l, int r, int cur, int b, int e) {
    push_down_lazy(cur, l, r);
    if (l > e || r < b) return 0;
    if (l >= b && r <= e) return segtree[cur];
    if (l == r) return 0;
    int mid = (l + r) / 2;
    return query(l, mid, cur * 2, b, e) + query(mid + 1, r, cur * 2 + 1, b, e);
}

int main() {
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) { // update
            scanf("%d", &d);
            update(1, N, 1, b, c, d);
        } else { // query
            printf("%d\n", query(1, N, 1, b, c));
        }
    }
    return 0;
}
