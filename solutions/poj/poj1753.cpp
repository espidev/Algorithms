#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// b = true
// w = false

int mask[] = {0b1100100000000000, 0b1110010000000000, 0b0111001000000000, 0b0011000100000000,
            0b1000110010000000, 0b0100111001000000, 0b0010011100100000, 0b0001001100010000,
            0b0000100011001000, 0b0000010011100100, 0b0000001001110010, 0b0000000100110001,
            0b0000000010001100, 0b0000000001001110, 0b0000000000100111, 0b0000000000010011};

bool dp[1<<16+10];

int change(int pos, int num) {
    return num^mask[pos];
}

int main() {
    int num = 0;
    for (int i = 0; i < 16; i++) {
        char ch;
        cin >> ch;
        if (ch == 'b') num |= (1<<i);
    }

    if (num == 0 || num == 0b1111111111111111) {
        cout << 0 << endl;
        return 0;
    }

    int level = 0;

    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        int s = q.size();
        level++;
        for (int j = 0; j < s; j++) {
            for (int i = 0; i < 16; i++) {
                int changed = change(i, q.front());
                if (changed == 0 || changed == 0b1111111111111111) {
                    cout << level << endl;
                    return 0;
                }
                if (!dp[changed]) {
                    dp[changed] = true;
                    q.push(changed);
                }
            }
            q.pop();
        }
    }

    cout << "Impossible" << endl;
    return 0;
}