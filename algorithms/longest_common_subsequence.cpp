#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, string> m;
string dp[1001][1001];

// brute force removing either one character from a, or one character from b each time

string string_lcs(string& a, string& b, int i, int j) {
    if (!i | !j) return "";
    if (!dp[i][j].empty()) return dp[i][j];
    if (a[i-1] == b[j-1]) return dp[i][j] = string_lcs(a, b, i-1, j-1) + a[i-1];
    string c = string_lcs(a, b, i-1, j), d = string_lcs(a, b, i, j-1);
    return dp[i][j] = (c.length() > d.length()) ? c : d;
}


int main() {
    string a = "abcdef", b = "bdmafkt";
    for (int i = 0; i < 1001; i++) for (int j = 0; j < 1001; j++) dp[i][j] = "";
    cout << string_lcs(a, b, a.length(), b.length()) << endl;
    return 0;
}
