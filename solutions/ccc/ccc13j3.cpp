#include <bits/stdc++.h>
using namespace std;

bool is_distinct(int year) {
    string s = to_string(year);
    for (int i = 0; i < s.length(); i++) {
        for (int j = i+1; j < s.length(); j++) {
            if (s[i] == s[j]) return false;
        }
    }
    return true;
}

int main() {
    int year;
    cin >> year;
    year++;
    while (!is_distinct(year)) year++;
    cout << year << endl;
    return 0;
}

