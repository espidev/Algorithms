#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;
    map<int, int> m;
    for(int i = 0, a; i < N; i++) {
        cin >> a;
        v.push_back(a);
        auto t = m.find(a);
        if(t == m.end()) {
            m.insert(make_pair(a, 1));
        }
        else {
            t->second++;
        }
    }
    int h1i = 0, h2i = 0;
    vector<int> h1, h2;
    for(auto t = m.begin(); t != m.end(); ++t) {
        if(t->second > h1i) {
            h2 = vector<int>();
            for(int i = 0; i < h1.size(); i++) {
                h2.push_back(h1[i]);
            }
            h1 = vector<int>();
            h1.push_back(t->first);
            h2i = h1i;
            h1i = t->second;
        }
        else if(t->second == h1i) {
            h1.push_back(t->first);
        }
        else if(t->second > h2i) {
            h2 = vector<int>();
            h2.push_back(t->first);
            h2i = t->second;
        }
        else if(t->second == h2i) {
            h2.push_back(t->first);
        }
    }
    if(h1.size() > 1) {
        int maxdiff = 0;
        for(int i = 0; i < h1.size(); i++) {
            for(int j = i+1; j < h1.size(); j++) {
                if(abs(h1[i]-h1[j]) > maxdiff) {
                    maxdiff = abs(h1[i]-h1[j]);
                }
                if(abs(h1[j]-h1[i]) > maxdiff) {
                    maxdiff = abs(h1[j]-h1[i]);
                }
            }
        }
        cout << abs(maxdiff) << endl;
    }
    else {
            int maxdiff = 0;
            for(int i = 0; i < h2.size(); i++) {
                if(abs(h2[i]-h1[0]) > maxdiff) {
                    maxdiff = abs(h2[i]-h1[0]);
                }
                if(abs(h1[0]-h2[i]) > maxdiff) {
                    maxdiff = abs(h1[0]-h2[i]);
                }
            }
            cout << abs(maxdiff) << endl;
    }
    return 0;
}
