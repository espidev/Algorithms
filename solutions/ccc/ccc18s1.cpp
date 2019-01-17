#include <bits/stdc++.h>
using namespace std;
int N;
double smallest = 1e9;

int main() {
    cin >> N;
    vector<double> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i < N-1; i++) if (smallest > ((v[i] - v[i-1])/2 + (v[i+1] - v[i])/2)) smallest = (v[i] - v[i-1])/2 + (v[i+1] - v[i])/2; // one liner???
    printf("%.1f", smallest);
    return 0;
}
