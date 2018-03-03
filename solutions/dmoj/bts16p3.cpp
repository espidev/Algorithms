#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = n, cur = 0;
    char c = '6';
    for(int i = 0; i < n; i++) {
        string in;
        cin >> in;
        transform(in.begin(), in.end(), in.begin(), ::tolower);
        char ch = in[0];
        if(c == ch){
            cur++;
        }
        else{
            int o = 0;

            for(int i = 1; i <= cur; i++){
                o += i;
            }

            t += o;
            cur = 0;
            c = ch;
        }
    }
    t += cur;
    cout << (t % 1000000007);
    return 0;
}
