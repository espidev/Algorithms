#include <bits/stdc++.h>
using namespace std;

int N, K, arr[251][251][251];

int rec(int pies, int people, int pre) {
    if (arr[pies][people][pre] != -1) return arr[pies][people][pre];
    if (people == 0) return (pies == 0) ? 1 : 0;
    int sum = 0;
    for (int i = pre; i <= pies; i++) sum += rec(pies-i, people-1, i);
    arr[pies][people][pre] = sum;
    return sum;
}

int main() {
    memset(arr, -1, sizeof arr);
    cin >> N >> K;
    cout << rec(N, K, 1) << endl;
    return 0;
}

