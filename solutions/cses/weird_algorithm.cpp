#include <bits/stdc++.h>
using namespace std;
 
long long N;
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N != 1) {
        cout << N << " ";
        N = N%2==0 ? N/2 : N*3+1;
    }
    cout << N << endl;
    return 0;
}
