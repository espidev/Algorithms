#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            for(int k = 0; k <= j; k++) {
                cout << "*";
            }
            cout << endl;
        }
        for(int j = a-2; j > -1; j--) {
            for(int k = 0; k <= j; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}
