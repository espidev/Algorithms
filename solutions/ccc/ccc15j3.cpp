#include <bits/stdc++.h>
using namespace std;

char get_vowel(char c) {
    char ch;
    int dist = 30;
    if (abs(c - 'u') <= dist) {
        ch = 'u';
        dist = abs(c-'u');
    }
    if (abs(c - 'o') <= dist) {
        ch = 'o';
        dist = abs(c-'o');
    }
    if (abs(c - 'i') <= dist) {
        ch = 'i';
        dist = abs(c-'i');
    }
    if (abs(c - 'e') <= dist) {
        ch = 'e';
        dist = abs(c-'e');
    }
    if (abs(c - 'a') <= dist) {
        ch = 'a';
    }
    return ch;
}

int main() {
    string s, o = "";
    cin >> s;
    for (char ch : s) {
        o += ch;
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
        o += get_vowel(ch);
        if (ch == 'z') {
            o += 'z';
        } else if (ch == 'a'-1 || ch == 'e'-1 || ch == 'i'-1 || ch == 'o'-1 || ch == 'u'-1) {
            o += (ch+2);
        } else {
            o += (ch+1);
        }
    }
    cout << o << endl;
    return 0;
}

