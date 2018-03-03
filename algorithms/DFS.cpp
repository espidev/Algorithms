#include <bits/stdc++.h>
using namespace std;

int dfs(int u, vector<vector<int>>& tree){
    for(int i = 0; i < tree[u].size(); i++){
        //do stuff with node
        dfs(tree[u][i], tree);
    }
    //Can record exit time here
    return 0;
}