#include <bits/stdc++.h>

#define ll long long
using namespace std;
int N;
vector<int> arr1, arr2;
unordered_map<ll, int> m1, m2;
vector<int> k1, k2;

// NOT COMPLETE
// 0 not chosen, 1 left, -1 right

void rec(vector<int> &ar, unordered_map<ll, int> &ma, vector<int>& v, int len, int ind, ll sum) {
    cout << ind << " " << len << " " << sum << endl;
    if (ind == len) {
        if (sum < 0) return;
        auto d = ma.find(sum);
        if (d == ma.end()) {
            ma.insert(make_pair(sum, 1));
            v.push_back(sum);
        }
        else d->second++;
        return;
    }
    rec(ar, ma, v, len, ind + 1, sum + ar[ind]);
    rec(ar, ma, v, len, ind + 1, sum - ar[ind]);
    rec(ar, ma, v, len, ind + 1, sum);
}

int main() {
    scanf("%d", &N);
    int a;
    for (int i = 0; i < N / 2; i++) {
        scanf("%d", &a);
        arr1.push_back(a);
    }
    for (int i = N / 2; i < N; i++) {
        scanf("%d", &a);
        arr2.push_back(a);
    }

    rec(arr1, m1, k1, N / 2, 0, 0);
    rec(arr2, m2, k2, N - (N / 2), 0, 0);

    m1[0]--;
    m2[0]--;
    m1[0]/=2;
    m2[0]/=2;
    m1[0]++;
    m2[0]++;

    int ans = 0;
    for (int i = 0; i < k1.size(); i++) {
	for (int j = i; j < k2.size(); j++) { 
		for (int k = i+1; k < k1.size(); k++) {
			for (int l = j+1; l < k2.size(); l++) {
				int a1 = m1[k1[i]], a2 = m2[k2[j]], a3 = m1[k1[k]], a4 = m2[k2[l]];
				printf("%d %d %d %d | %d %d %d %d\n", a1, a2, a3, a4, k1[i], k2[j], k1[k], k2[l]);
				if (k1[i] + k2[j] - (k1[k] + k2[l]) == 0) {
					cout << "YES" << endl;
					ans += min(a1, a2) * min(a3, a4);
				}
			}
		}
	}
    }

    cout << (ans + m1[0] + m2[0] - 2) << endl;
    return 0;
}
