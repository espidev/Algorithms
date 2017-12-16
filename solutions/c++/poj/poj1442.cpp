
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int M, N;

/*
 * POJ 1442
 */

int main() {
    cin >> M >> N;
    int incur[M];
    for(int i = 0; i < M; i++) {
        cin >> incur[i];
    }
    priority_queue<int> ass;
    priority_queue<int, vector<int>, greater<int> > ass2;
    int cur = 0, d = 0;
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());

    int first = 0;

    for(int i = 0; i < N; i++) {
        int c = v[i];
        for(; cur < c; cur++) {
            if(i == 0 || incur[cur] >= first) {
                ass2.push(incur[cur]);
            }
            else {
                ass.push(incur[cur]);
                ass2.push(ass.top());
                ass.pop();
            }
        }
        first = ass2.top();

        cout << ass2.top() << endl;
        ass.push(ass2.top());
        ass2.pop();

        d++;
    }
    return 0;
}