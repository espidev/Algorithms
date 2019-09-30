#include <bits/stdc++.h>
using namespace std;

long long N, Q, seg[2*10000001], arr[100000001];

void build(int i, int l, int r) {
    if (l == r) {
        seg[i] = arr[l];
    } else {
        int mid = (l+r) / 2;
        build(i*2, l, mid);
        build(i*2+1, mid+1, r);
        seg[i] = seg[i*2] ^ seg[i*2+1];
    }
}

long long query(int i, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 1e9;
    if (l >= ql && r <= qr) return seg[i];
    int mid = (l+r) / 2;
    int q1 =  query(i*2, l, mid, ql, qr), q2 = query(i*2+1, mid+1, r, ql, qr);
    if (q1 == 1e9 && q2 != 1e9) return q2;
    if (q1 != 1e9 && q2 == 1e9) return q1;
    if (q1 == 1e9 && q2 == 1e9) return 1e9;
    return query(i*2, l, mid, ql, qr) ^ query(i*2+1, mid+1, r, ql, qr);
}

long long update(int i, int l, int r, int ql, int qr, int u) {
    if (r < ql || l > qr) return 1e9;
    if (l == r) return seg[i] = u;
    int mid = (l + r) / 2;
    update(i*2, l, mid, ql, qr, u);
    update(i*2+1, mid+1, r, ql, qr, u);
    return seg[i] = seg[i*2] ^ seg[i*2+1];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    build(1, 1, N);

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, N, l, r) << endl;
    }
    return 0;
}
