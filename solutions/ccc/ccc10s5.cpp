#include <bits/stdc++.h>
using namespace std;

#define TREE_SIZE 500 

int X, nutrients[TREE_SIZE], dp[TREE_SIZE][2501];
int ind = 0;

void inbracket(string s, int cur) {
	int leftright = 0;
	bool getNum = false;
	string sNum = "";	

	while (++ind < s.length() && s[ind] != ')') {
		if (s[ind] == '(') {
			inbracket(s, cur*2+leftright);
			leftright++;
		} else if (s[ind] == ' ') {
			if (getNum) {
				getNum = false;
				nutrients[cur*2+leftright] = stoi(sNum);
				sNum = "";
				leftright++;
			}
		} else {
			getNum = true;
			sNum += string(1, s[ind]);
		}
	}
	if (getNum) {
		nutrients[cur*2+1] = stoi(sNum);
	}
}

void dfs(int node) {
	if (nutrients[node] > 0) { // test leaf growth
		for (int i = 0; i <= X; i++) dp[node][i] = nutrients[node]+i;
		return;
	}

	dfs(node*2);
	dfs(node*2+1);

	int left[2501], right[2501];
	for (int i = 0; i <= X; i++) {
		left[i] = 0;
		right[i] = 0;
	}

	// test branch growth
	for (int i = 0; i <= X; i++) {
		for (int k = 0; k <= i; k++) { 
			left[i] = max(left[i], min((1+k)*(1+k), dp[node*2][i-k]));
			right[i] = max(right[i], min((1+k)*(1+k), dp[node*2+1][i-k]));
		}
	}

	for (int i = 0; i <= X; i++) {
		for (int j = 0; j <= i; j++) { // j - number of nutrients used
			dp[node][i] = max(dp[node][i], left[j] + right[i-j]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	cin >> X;

	// get input
	if (s[0] != '(') {
		nutrients[1] = stoi(s);
		dfs(1);
	} else {
		inbracket(s, 1);
		dfs(1);
	}
	int ans = 0;
	for (int i = 0; i <= X; i++) ans = max(ans, dp[1][i]);
	cout << ans << endl;
	return 0;
}

