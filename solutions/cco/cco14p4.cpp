#include <bits/stdc++.h>

using namespace std;
#define MAXN 100000

/*
 * CCO 14 P4 (CCO 2014 Day 2 P1)
 */

int N, P, fuel = 0, planets = 1;
int A[MAXN], B[MAXN];
vector<pair<int, int>> bigs, same;

int main() {
    scanf("%d %d", &N, &P); //why do it this way? i dunno it looks cool
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (i == P - 1) {
            fuel = A[i];
        } else if (A[i] > B[i]) {
            bigs.emplace_back(B[i], A[i]);
        } else if (A[i] == B[i]) {
            same.emplace_back(A[i], B[i]);
        }
    }
    sort(bigs.begin(), bigs.end());
    for (pair<int, int> p : bigs) {
        if (p.first > fuel) {
            break;
        } else {
            fuel += p.second - p.first;
            planets++;
        }
    }
    for (pair<int, int> p : same) {
        if (p.second <= fuel) {
            planets++;
        }
    }
    cout << fuel << endl << planets << endl;
    return 0;
}