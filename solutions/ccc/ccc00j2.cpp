#include <bits/stdc++.h>

using namespace std;

bool isReverse(int a) {
    string a1 = to_string(a), a2 = "";
    for (char i : a1) {
        if (i == '0' || i == '1' || i == '8') {
            a2 = i + a2;
        } else if (i == '6' || i == '9') {
            a2 = ((i == '6') ? '9' : '6') + a2;
        } else {
            a2 = "bad";
            break;
        }
    }
    return a1 == a2;
}

int main() {
    int M, N, A = 0;
    cin >> M >> N;
    for (; M < N; M++) {
        if (isReverse(M)) {
            A++;
        }
    }
    cout << A << endl;
    return 0;
}
