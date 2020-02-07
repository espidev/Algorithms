#include <bits/stdc++.h>
using namespace std;

int on = 0, op = 1, an = 2, ap = 3, bn = 4, bp = 5, abn = 6, abp = 7;
int p_on = 0, p_op = 1, p_an = 2, p_ap = 3, p_bn = 4, p_bp = 5, p_abn = 6, p_abp = 7;
int arr1[8], arr2[8];
int ans = 0;

void source(int patient, vector<int> v) {
    for (int ind : v) {
        if (arr2[patient] == 0) {
            break;
        }
        if (arr1[ind] > arr2[patient]) {
            ans += arr2[patient];
            arr1[ind] -= arr2[patient];
            arr2[patient] = 0;
        } else {
            ans += arr1[ind];
            arr2[patient] -= arr1[ind];
            arr1[ind] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) cin >> arr1[i];
    for (int i = 0; i < 8; i++) cin >> arr2[i];
    source(p_on, {on});
    source(p_an, {an, on});
    source(p_bn, {bn, on});
    source(p_abn, {abn, an, bn, on});
    
    source(p_op, {op, on});
    source(p_ap, {ap, an, op, on});
    source(p_bp, {bp, bn, op, on});
    source(p_abp, {abp, abn, ap, bp, op, ap, bp, on});
    cout << ans << endl;
    return 0;
}
