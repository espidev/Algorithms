#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, N, C = 1;
    cin >> A >> N;
    cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;
    for(int i = 1; i <= 7; i++) {
        if(i < A) {
            cout << "   ";
        } else {
            cout << "  " << C++;
        }
        if(i != 7) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    while(true) {
        for(int i = 0; i < 7; i++) {
            if(C > N) {
                return 0;
            }
            if(C < 10) {
                cout << "  " << C++;
            } else {
                cout << " " << C++;
            }
            if(i != 6 && C <= N) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}
