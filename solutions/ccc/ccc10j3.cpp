#include <bits/stdc++.h>

using namespace std;

int in;
unordered_map<string, int> m;

int main() {
    m.insert(make_pair("X", 0));
    m.insert(make_pair("Y", 0));
    cin >> in;
    string s1, s2;
    while (in != 7) {
        switch (in) {
            case 1:
                cin >> s1 >> in;
                m[s1] = in;
                break;
            case 2:
                cin >> s1;
                cout << m[s1] << endl;
                break;
            case 3:
                cin >> s1 >> s2;
                m[s1] = m[s1] + m[s2];
                break;
            case 4:
                cin >> s1 >> s2;
                m[s1] = m[s1] * m[s2];
                break;
            case 5:
                cin >> s1 >> s2;
                m[s1] = m[s1] - m[s2];
                break;
            case 6:
                cin >> s1 >> s2;
                m[s1] = m[s1] / m[s2];
                break;
        }
        cin >> in;
    }
    return 0;
}
