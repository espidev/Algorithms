#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000
int N, x, y, x2, y2;

// sweep line algorithm

struct Point {
	int x, y, e;
	// e = 0: horizontal enter
	// e = 1: leaving
	// e = 2: vertical enter
	Point (int x, int y, int e) {
		this->x = x;
		this->y = y;
		this->e = e;
	}
};

int segtree[MAXN*2+1]; // for y-values
vector<Point> points;
set<int> y_values, x_values; // sorted and no duplicates
vector<int> y_map(MAXN);

unordered_map<int, vector<Point>> yAtX; // <x value, points at x>

void update(int l, int r, int cur, int node, int setTo) {
	if (l > node || r < node) {
		return;		
	}
	if (l == r && node == l) {
		segtree[cur] += setTo;
	}
	int mid = (l + r) / 2
	update(l, mid, cur*2, node, setTo);
	update(mid+1, r, cur*2+1, node, setTo);
	segtree[cur] = segtree[cur*2] + segtree[cur*2+1];
}

int query(int l, int r, int cur, int b, int e) {
	if (l > e || r < l) {
		return 0;
	}
	if (b <= l && e >= r) {
		return segtree[cur];
	}
	int mid = (l + r) / 2;
	return query(l, mid, cur*2, b, e) + query(mid+1, r, cur*2+1, b, e);
}

int insertPoint(Point p) {
	auto d = yAtX.find(p.x);
	if (d == yAtX.end()) {
		vector<Point> v;
		v.push_back(p);
		yAtX.insert(make_pair(p.x, p));
	} else {
		d->second.push_back(p);
	}
}

int main() {
	scanf("%d", &N);
	int maxX = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &x2, &y2);
		y_values.insert(y);
		y_values.insert(y2);
		x_values.insert(x);
		x_values.insert(x2);
		maxX = max(maxX, max(x, x2));
		if (x == x2) {
			points.push_back(Point(x, y, 0));
			points.push_back(Point(x2, y2, 1));
			insertPoint(Point(x, y, 0));
			insertPoint(Point(x2, y2, 1));	
		} else if (y == y2) {
			points.push_back(Point(x, y, 2));
			points.push_back(Point(x2, y2, 1));
			insertPoint(Point(x, y, 2));
			insertPoint(Point(x2, y2, 1));
		}
	}
	int k = 0;
	for (int x : y_values) {
		y_map[x] = k;
		k++;
	}
	
	int intersectionPoints = 0;
	for (int xv : x_values) {
		for (Point p : yAtX[xv]) {
			if (p.e == 2) {
				intersectionPoints
					// TODO QUERY for intersection points
			}
		}
		for (Point p : yAtX[xv]) {
			if (p.e == 1) {
				update(0, y_values.size()-1, 1, p.y, 1); // enter line
			} else if (p.e == 0) {
				update(0, y_values.size()-1, 1, p.y, -1); // leave line
			} else if (p.e == 2) continue;
		}
	}
	printf("There are %d intersection points.\n", intersectionPoints);
}
