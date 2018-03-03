#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s.length() <= 10){
            m++;
        }
    }
    cout << m;
    return 0;
}
