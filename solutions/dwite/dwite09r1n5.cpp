#include <bits/stdc++.h>
using namespace std;

/*
 * DMOJ 695271
 */

int main() {
    for(int i = 0; i < 5; i++) {
        int l;
        cin >> l;
        map<int, vector<int>> graph;
        for(int j = 0; j < l; j++) {
            int n1, n2;
            cin >> n1 >> n2;
            auto d = graph.find(n1);
            if(d == graph.end()) {
                vector<int> v;
                v.push_back(n2);
                graph.insert({n1, v});
            }
            else {
                d->second.push_back(n2);
            }
        }
        //infinitely loop
        while(true) {
            bool f = false;
            for(int j = 0; j <= 100; j++) { //loop to find node
                if(graph.find(j) == graph.end()) continue;
                vector<int>& d = graph[j];
                if(d.empty()) { //if the node goes nowhere, delete it
                    f = true;
                    graph.erase(j);
                }
                else {
                    for(int k = 0; k < d.size(); k++) { //check each node to delete arrows if the 
node doesn't exist anymore
                        if(graph.find(d[k]) == graph.end()) {
                            d.erase(d.begin() + k);
                            if(d.empty()) {
                                graph.erase(j);
                            }
                            f = true;
                        }
                    }
                    bool found = false;
                    for(int k = 0; k <= 100; k++) { //check if any nodes point to this node
                        if(graph.find(k) == graph.end()) continue;
                        vector<int>& p = graph[k];
                        for(int c : p) {
                            if(c == j) {
                                found = true;
                                break;
                            }
                        }
                        if(found) break;
                    }
                    if(!found) { //not found, remove
                        graph.erase(j);
                        f = true;
                    }
                }
            }
            if(!f) { //the loop is found
                break;
            }
        }
        cout << graph.size() << "" << endl;
    }
    return 0;
}
