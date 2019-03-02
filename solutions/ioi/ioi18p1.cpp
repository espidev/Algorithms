#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int N) {
    vector<string> chars;
    string begin, str;
    // first char
    if (press("AB")) {
        if (press("A")) begin = "A";
        else begin = "B";
    } else {
        if (press("X")) begin = "X";
        else begin = "Y";
    }
    str = begin;
    for (string s : {"A", "B", "X", "Y"}) {
        if (s != begin) chars.push_back(s);
    }

    // main
    for (int i = 1; i < N - 1; i++) {
        int d = press(str + chars[0] + str + chars[1] + chars[0] + str + chars[1] + chars[1] + str + chars[1] + chars[2]);
        if (d == i+1) str += chars[0];
        else if (d == i+2) str += chars[1];
        else str += chars[2];
    }

    if (N == 1) return str;

    // final char
    if (begin == "A") {
        if (press(str + "B") == N) str += "B";
        else if (press(str + "X") == N) str += "X";
        else str += "Y";
    } else if (begin == "B") {
        if (press(str + "A") == N) str += "A";
        else if (press(str + "X") == N) str += "X";
        else str += "Y";
    } else {
        if (press(str + "A") == N) str += "A";
        else if (press(str + "B") == N) str += "B";
        else str += (begin == "Y") ? "X" : "Y";
    }

    return str;
}
