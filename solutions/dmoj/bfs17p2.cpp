#include <bits/stdc++.h>
using namespace std;

bool pairCompare(const pair<string, int>& firstElem, const pair<string, int>& secondElem) {
    return firstElem.second < secondElem.second;
}

int rec(vector<pair<string, int>>& sorted, int l, string prev){
    if(sorted.empty())
        return l;
    for(int i = sorted.size()-1; i > -1; i--){
        //cout << sorted[i].first << l << endl;
        if(sorted[i].first == prev){
            //cout << "skip" << endl;
            continue;
        }
        else{
            prev = sorted[i].first;
            if(sorted[i].second == 1){
                sorted.erase(sorted.begin() + i);
            }
            else{
                sorted[i].second = sorted[i].second - 1;
            }
            sort(sorted.begin(), sorted.end(), pairCompare);
            return rec(sorted, l+1, prev);
        }
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, int> v;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(v.find(s) != v.end()){
            v.find(s)->second = v.find(s)->second + 1;
        }
        else{
            v.insert(make_pair(s, 1));
        }
    }
    vector<pair<string, int>> a;
    for(auto i : v){
        a.push_back(i);
    }
    sort(a.begin(), a.end(), pairCompare);
    cout << rec(a, 0, "");
    return 0;
}
