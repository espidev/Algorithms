#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

// find a eulerian circuit in connected graph

vector<int> hierholzer() {
    vector<int> circuit;
    stack<int> path;
    path.push(0); // could be any node
    int node = path.top();
    while (!path.empty()) {
        if (!graph[node].empty()) {
            path.push(node);
            int next = graph[node].back();
            graph[node].pop_back();
            node = next;
        } else {
            circuit.push_back(path.top());
            node = path.top();
            path.pop();
        }
    }

    return circuit; // circuit is in reverse order
}

int main() {
    // fill graph
    return 0;
}