#include <bits/stdc++.h>
using namespace std;

/*
 * CCC01S3
 */

unordered_map<char, vector<char>> v;
unordered_map<string, int> m;
unordered_map<string, string> pMap;
int dfs(char ch, string path, unordered_map<char, bool> visited, vector<string> md) {
    visited[ch] = true;
    //cout << path << " " << ch << endl;
    md.push_back(path);
    if(ch == 'B') {
        for(const auto &t : md) {
            m[t]++;
        }
        return 1;
    }
    int ret = 0;
    for(int i = 0; i < v[ch].size(); i++) {
        if(!visited[v[ch][i]]) {
            ret += dfs(v[ch][i], to_string(ch) + to_string(v[ch][i]), visited, md);
        }
    }
    return ret;
}
int main() {
    string input;
    cin >> input;
    while(input != "**") {
        if(v.find(input[0]) == v.end()) {
            v.insert({input[0], vector<char>()});
        }
        if(v.find(input[1]) == v.end()) {
            v.insert({input[1], vector<char>()});
        }
        v[input[0]].push_back(input[1]);
        v[input[1]].push_back(input[0]);
        pMap[to_string(input[0]) + to_string(input[1])] = input;
        pMap[to_string(input[1]) + to_string(input[0])] = input;
        //cout << input[0] << " B " << (input[0] == 'B') << endl;
        cin >> input;
    }
    int s = dfs('A', "AA", unordered_map<char, bool>(), vector<string>());
    int l = 0;
    for(auto t : m) {
        //cout << t.first << " " << t.second << " " << s << endl;
        if(t.second == s && t.first != "AA") {
            l++;
            int a1 = stoi(t.first.substr(0, 2));
            char a2 = a1;
            int b1 = stoi(t.first.substr(2, 4));
            char b2 = b1;
            cout << pMap.find(to_string(a2) + to_string(b2))->second << endl;
            //cout << t.first << endl;
        }
    }
    cout << "There are " << l << " disconnecting roads." << endl;
    return 0;
}
