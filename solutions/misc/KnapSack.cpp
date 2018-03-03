#include <bits/stdc++.h>
using namespace std;

/*
 * 0-1 Knapsack Problem.
 * Given a bag with w capacity and n items whose value and weight is
 * V1, V2, V3 ... Vn
 * W1, W2, W3 ... Wn
 */

int l, n;

int main(){
    int w; //input number of items, then weight.
    cin >> n >> w;
    int val[n];
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){ //input all of the values, and then the weights.
        cin >> val[i];
        if(val[i] > l) l = val[i];
    }
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        map.insert(make_pair(val[i], w));
        if(w > l) l = w;
    }
    int hash[l][l] = {{0}};
    int i = 0;
    for(; i < n; i++){
        for(int j = 0; j < n; j++) {
            int v;
            if(map.find(i) == map.end()){
                v = 0;
            }
            else{
               v = map.find(i)->second;
            }
            if(j == 0){
                hash[i][j] = v;
            }
            else{
                hash[i][j] = max(hash[i][j-1], v);
            }
        }
    }
    cout << hash[i][w];
    return 0;
}