#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define PLACEHOLDER 'p'

int l, w;
char arr[31][31];
bool useless[1000000];

map<char, vector<pair<int, int> > > corner_find;
vector<pair<char, vector<pair<int, int> > > > corners;

bool recurse_side(int x, int y, int mx, int my, int dx, int dy, char c) {
        if (arr[x][y] != c && arr[x][y] != PLACEHOLDER) return false;
        if (x == dx && y == dy) return true;
        return recurse_side(x+mx, y+my, mx, my, dx, dy, c);
}

void flag_placeholder(int x, int y, int mx, int my, int dx, int dy, char c, map<pair<int, int>, char>& restores) {
        restores.insert(make_pair(make_pair(x, y), arr[x][y]));
        arr[x][y] = PLACEHOLDER;
        if (x == dx && y == dy) return;
        flag_placeholder(x+mx, y+my, mx, my, dx, dy, c, restores);
}

void restore_flag_placeholder(int x, int y, int mx, int my, int dx, int dy, char c, map<pair<int, int>, char>& restores) {
        arr[x][y] = restores.find(make_pair(x, y))->second;
        if (x == dx && y == dy) return;
        restore_flag_placeholder(x+mx, y+my, mx, my, dx, dy, c, restores);
}

bool rhelper(pair<int, int> p1, pair<int, int> p2, int mx, int my, char c) {
        return recurse_side(p1.first, p1.second, mx, my, p2.first, p2.second, c);
}
void flag_helper(pair<int, int> p1, pair<int, int> p2, int mx, int my, char c, map<pair<int, int>, char>& restores) {
        flag_placeholder(p1.first, p1.second, mx, my, p2.first, p2.second, c, restores);
}

void restore_flag_helper(pair<int, int> p1, pair<int, int> p2, int mx, int my, char c, map<pair<int, int>, char>& restores) {
        restore_flag_placeholder(p1.first, p1.second, mx, my, p2.first, p2.second, c, restores);
}

vector<string> back_track() {
        vector<string> v;
        for (int i = 0; i < corners.size(); i++) {
                if (useless[i]) continue;
                pair<char, vector<pair<int, int> > > p = corners[i];
                char c = p.first;
                pair<int, int> c1 = p.second[0], c2 = p.second[1], c3 = p.second[2], c4 = p.second[3];
                if (rhelper(c1, c2, 0, 1, c) && rhelper(c3, c4, 0, 1, c) && rhelper(c1, c3, 1, 0, c) && rhelper(c2, c4, 1, 0, c)) {
                        map<pair<int, int>, char> restores;
                        flag_helper(c1, c2, 0, 1, c, restores);
                        flag_helper(c3, c4, 0, 1, c, restores);
                        flag_helper(c1, c3, 1, 0, c, restores);
                        flag_helper(c2, c4, 1, 0, c, restores);

                        useless[i] = true;
                        vector<string> v1 = back_track();
                        useless[i] = false;


                        for (int i = 0; i < v1.size(); i++) {
                            string ls = v1[i];
                            v.push_back(string() + ls + c);
                        }

                        restore_flag_helper(c1, c2, 0, 1, c, restores);
                        restore_flag_helper(c3, c4, 0, 1, c, restores);
                        restore_flag_helper(c1, c3, 1, 0, c, restores);
                        restore_flag_helper(c2, c4, 1, 0, c, restores);
                }
        }
        if (v.empty()) v.push_back("");
        return v;
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);

        cin >> l >> w;
        for (int i = 0; i < l; i++) {
                for (int j = 0; j < w; j++) {
                        cin >> arr[i][j];
                        if (arr[i][j] == '.') continue;
                        map<char, vector<pair<int, int> > >::iterator d = corner_find.find(arr[i][j]);
                        if (d == corner_find.end()) {
                                vector<pair<int, int> > v;
                                v.push_back(make_pair(i, j));
                                corner_find.insert(make_pair(arr[i][j], v));
                        } else {
                                d->second.push_back(make_pair(i, j));
                        }
                }
        }

        for (map<char, vector<pair<int, int> > >::iterator p = corner_find.begin(); p != corner_find.end(); p++) {
                int minX = p->second[0].first, maxX = p->second[0].first, minY = p->second[0].second, maxY = p->second[0].second;
                for (int i = 0; i < p->second.size(); i++) {
                    pair<int, int> xy = p->second[i];
                        minX = min(minX, xy.first);
                        maxX = max(maxX, xy.first);
                        minY = min(minY, xy.second);
                        maxY = max(maxY, xy.second);
                }
                vector<pair<int, int> > v;
                v.push_back(make_pair(minX, minY));
                v.push_back(make_pair(minX, maxY));
                v.push_back(make_pair(maxX, minY));
                v.push_back(make_pair(maxX, maxY));
                corners.push_back(make_pair(p->first, v));

                // cout << "corner: " << p.first << " (" << minX << ", " << minY << ") (" << maxX << ", " << maxY << ")" << endl;
        }

        vector<string> v = back_track();
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            string s = v[i];
                cout << s << endl;
        }
        return 0;
}
