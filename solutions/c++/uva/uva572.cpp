#include <bits/stdc++.h>

using namespace std;

int main() {
	int X, Y;
	while (cin >> X >> Y) {
		char map[X][Y];
		int org[X][Y] = {{-1}};
		vector<vector<pair<int, int>>>  orgs;
		int ans = 0;
		for(int i = 0; i < X; i++) {
			for(int j = 0; j < Y; j++) {
				cin >> map[i][j];

				bool assigned = false;

				auto calc = [&org, &assigned, &orgs, &i, &j, &ans](int x, int y) -> void {
					if(org[x][y] != -1) {
						if(assigned && org[x][y] != org[i][j]) {
							for(int k = 0; k < orgs[org[i][j]].size(); k++) {
								orgs[org[x][y]].push_back(orgs[org[i][j]][k]);
								org[orgs[org[i][j]][k].first][orgs[org[i][j]][k].second] = org[x][y];
							}

							ans--;
						}
						assigned = true;
						org[i][j] = org[x][y];
						orgs[org[x][y]].push_back(make_pair(i, j));
					}
				};

				if(map[i][j] == '@') {
					if(i != 0) {
						if(j != 0) {
							calc(i-1, j-1);
						}
						if(i != Y - 1) {
							calc(i-1, i+1);
						}
						calc(i-1, j);
					}
					if(j != 0) {
						if(i != X - 1) {
							calc(i+1, j-1);
						}
						calc(i, j-1);
					}
					if(i != X - 1) {
						if(j != Y - 1) {
							calc(i+1, j+1);
						}
						calc(i+1, j);
					}
					if(j != Y - 1) {
						calc(i, j+1);
					}
					if(!assigned) {
						org[i][j] = static_cast<int>(orgs.size());
						vector<pair<int, int>> v;
						v.push_back(make_pair(i, j));
						orgs.push_back(v);
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}
