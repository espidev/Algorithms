#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;

    string name, n1, n2;
    int s1 = 0, s2 = 0;

    for (int i = 0, ram, cpu, disk; i < N; i++) {
        cin >> name >> ram >> cpu >> disk;
        int score = 2*ram + 3*cpu + disk;
        if (s1 < score) {
            n2 = n1;
            s2 = s1;
            n1 = name;
            s1 = score;
        } else if (s1 == score) {
            if (strcmp(name.c_str(), n1.c_str()) < 0) {
                n2 = n1;
                s2 = s1;
                n1 = name;
                s1 = score;
            } else {
                n2 = name;
                s2 = score;
            }
        } else if (s2 < score) {
            n2 = name;
            s2 = score;
        } else if (s2 == score) {
            if (strcmp(name.c_str(), n2.c_str()) < 0) {
                n2 = name;
                s2 = score;
            }
        }
    }

    cout << n1 << endl << n2 << endl;

    return 0;
}
