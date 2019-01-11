#include <bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    if (n1 > n2 && n2 > n3 && n3 > n4) {
        cout << "Fish Diving" << endl;
    } else if (n1 < n2 && n2 < n3 && n3 < n4) {
        cout << "Fish Rising" << endl;
    } else if (n1 == n2 && n2 == n3 && n3 == n4) {
        cout << "Fish At Constant Depth" << endl;
    } else {
        cout << "No Fish" << endl;
    }
    return 0;
}

