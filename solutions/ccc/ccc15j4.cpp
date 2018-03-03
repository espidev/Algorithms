#include <bits/stdc++.h>

using namespace std;

int main() {
    int M;
    scanf("%i", &M);
    int arr[101] = {0};
    bool rec[101] = {false};
    bool prevW = false;
    for (int i = 0; i < M; i++) {
        string R;
        int S;
        cin >> R >> S;
        if (R == "R") {
            if (!prevW) {
                for (int j = 0; j < 101; j++) {
                    if (rec[j] && j != S) {
                        arr[j]++;
                    }
                }
            }
            prevW = false;
            rec[S] = true;
        } else if (R == "S") {
            if (!prevW) {
                for (int j = 0; j < 101; j++) {
                    if (rec[j]) {
                        arr[j]++;
                    }
                }
            }
            prevW = false;
            rec[S] = false;
        } else {
            prevW = true;
            for (int j = 0; j < 101; j++) {
                if (rec[j]) {
                    arr[j] += S;
                }
            }
        }
    }
    for (int i = 0; i < 101; i++) {
        if (rec[i]) {
            cout << i << " " << -1 << endl;
        } else if (arr[i] != 0) {
            cout << i << " " << arr[i] << endl;
        }
    }
    return 0;
}
