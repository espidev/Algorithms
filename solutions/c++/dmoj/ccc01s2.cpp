#include <bits/stdc++.h>
using namespace std;
deque<deque<int>> v;
int x, y, z = 2;

/*
 * CCC 01 S2
 */

int main() {
    cin >> x >> y;
    v.push_back(deque<int>());
    for(; x <= y;) {
        for(int i = 0; i < z-1; i++) {
            if(x <= y) {
                v[i].push_front(x);
                x++;
            }
            else {
                v[i].push_front(-1);
            }
        }
        if(x > y) break;
        v.push_back(deque<int>());
        v[v.size()-1].push_back(x);
        x++;
        if(x > y) break;
        for(int i = 0; i < z-1 && x <= y; i++) {
            v[v.size()-1].push_back(x);
            x++;
        }
        if(x > y) break;
        z++;
        for(int i = 0; i < z-2 && x <= y; i++) {
            v[v.size()-i-2].push_back(x);
            x++;
        }
        if(x > y) break;
        v.push_front(deque<int>());
        v[0].push_back(x);
        x++;
        for(int i = 0; i < z-2; i++) {
            if(x <= y) {
                v[0].push_front(x);
                x++;
            }
            else {
                v[0].push_front(-1);
            }
        }
        z++;
    }

    int max = to_string(y).size();

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == -1){
                for(int k = 0; k < max; k++) {
                    cout << " ";
                }
                cout << " ";
            }
            else {
                cout << v[i][j] << " ";
                for(int k = 0; k < max-(to_string(v[i][j]).size()); k++) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}