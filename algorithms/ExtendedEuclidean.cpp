#include <bits/stdc++.h>
using namespace std;

/*
 * Extended Euclidean Algorithm
 * code is for ax + by = gcd(a, b)
 * the solution is (x, y)
 */

int gcd(int a, int b, int& x, int& y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;
    return d;
}

int main() {
    int x, y;
    gcd(5, 3, x, y);
    cout << x << " " << y;
    return 0;
}
