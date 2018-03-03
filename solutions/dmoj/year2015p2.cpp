#include <bits/stdc++.h>

using namespace std;
double C, F, S, N;

int main() {
    cin >> C >> F >> S >> N;
    double X;
    for (int i = 0; i < N; i++) {
        double c, f, s;
        cin >> X >> c >> f >> s;
        string hi, str;
        getline(cin, str);
        if (c / X <= C && f / X <= F && s / X <= S) {
            cout << str << endl;
        }
    }
    return 0;
}
