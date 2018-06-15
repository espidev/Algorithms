#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<vector<int>>& graph){
    for(int i = 0; i < graph[u].size(); i++){
        //do stuff with node
        dfs(graph[u][i], graph);
    }
    //Can record exit time here
    return 0;
}
