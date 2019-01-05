#include <bits/stdc++.h>

using namespace std;
#define MAXN 100001

// DMOJ Disjoint Set Test
// TLE for some reason???

int arr[MAXN];

struct Node {
    int minimum, gcd, numMin; // gcd between is either 0, or the same number
    Node *node1;
    Node *node2;

    Node(Node *node1, Node *node2, int minimum, int gcd, int numMin) {
        this->node1 = node1;
        this->node2 = node2;
        this->minimum = minimum;
        this->gcd = gcd;
        this->numMin = numMin;
    }

    Node(int minimum, int gcd, int numMin) {
        this->minimum = minimum;
        this->gcd = gcd;
        this->numMin = numMin;
    }
};

Node *tree;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

Node *build(int bi, int ei) {
    if (ei == bi) return new Node(arr[bi], arr[bi], 1);
    int mid = (bi + ei) / 2, numMin = 0;
    Node *node1 = build(bi, mid);
    Node *node2 = build(mid + 1, ei);
    int g = gcd(node1->gcd, node2->gcd);
    if (g == node1->gcd) numMin += node1->numMin;
    if (g == node2->gcd) numMin += node2->numMin;
    return new Node(node1, node2, min(node1->minimum, node2->minimum), g, numMin);
}

int query_min(int bi, int ei, int qb, int qe, Node *node) {
    if (bi >= qb && qe >= ei) return node->minimum;
    if (ei < qb || bi > qe) return 1e9 + 10;
    int mid = (bi + ei) / 2;
    return min(query_min(bi, mid, qb, qe, node->node1), query_min(mid + 1, ei, qb, qe, node->node2));
}

int query_gcd(int bi, int ei, int qb, int qe, Node *node) {
    if (bi >= qb && qe >= ei) return node->gcd;
    if (ei < qb || bi > qe) return 0;
    int mid = (bi + ei) / 2;
    int a = query_gcd(bi, mid, qb, qe, node->node1), b = query_gcd(mid + 1, ei, qb, qe, node->node2);

    if (a == 0) return b;
    else if (b == 0) return a;
    else return gcd(a, b);
}

// return gcd numMin and minimum
int query_gcd_equals(int bi, int ei, int qb, int qe, Node *node, int g) {
    if (bi >= qb && qe >= ei) return node->gcd == g ? node->numMin : 0;
    if (ei < qb || bi > qe) return 0;
    int mid = (bi + ei) / 2;
    return query_gcd_equals(bi, mid, qb, qe, node->node1, g) + query_gcd_equals(mid + 1, ei, qb, qe, node->node2, g);
}

void update(int i, int v, int bi, int ei, Node *node) {
    if (bi == ei) {
        if (bi == i) {
            node->minimum = v;
            node->gcd = v;
            node->numMin = 1;
        }
        return;
    }
    if (i > ei || i < bi) return;
    int mid = (bi + ei) / 2;
    if (i > mid) {
        update(i, v, mid + 1, ei, node->node2);
    } else {
        update(i, v, bi, mid, node->node1);
    }
    auto node1 = node->node1;
    auto node2 = node->node2;

    node->minimum = min(node1->minimum, node2->minimum);
    node->gcd = gcd(node1->gcd, node2->gcd);
    node->numMin = 0;
    int g = node->gcd;
    if (g == node1->gcd) node->numMin += node1->numMin;
    if (g == node2->gcd) node->numMin += node2->numMin;
}

int N, M, b, c;
char a;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    tree = build(0, N - 1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (a == 'C') {
            update(b - 1, c, 0, N - 1, tree);
        } else if (a == 'M') {
            cout << query_min(0, N - 1, b - 1, c - 1, tree) << endl;
        } else if (a == 'G') {
            cout << query_gcd(0, N - 1, b - 1, c - 1, tree) << endl;
        } else if (a == 'Q') {
            cout << query_gcd_equals(0, N - 1, b - 1, c - 1, tree, query_gcd(0, N - 1, b - 1, c - 1, tree)) << endl;
        }
    }
    return 0;
}