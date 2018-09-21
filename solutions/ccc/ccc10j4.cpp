#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;
    while (N != 0) {
        vector<int> cycle;
        int num, prev;
        cin >> prev;
        for (int i = 1; i < N; i++) {
            cin >> num;
            cycle.push_back(num - prev);
            prev = num;
        }
        bool printed = false;
        for (int i = 1; i < cycle.size(); i++) {
            int k = 0;
            bool good = true;
            while (k < cycle.size()) {
                for (int j = 0; j < i && k < cycle.size(); j++) {
                    if (cycle[k] != cycle[j]) {
                        good = false;
                        break;
                    }
                    k++;
                }
                if (!good) break;
            }
            if (good) {
                printed = true;
                cout << i << endl;
                break;
            }
        }
        if (!printed) cout << N - 1 << endl;
        cin >> N;
    }
    return 0;
}

