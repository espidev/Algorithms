#include <bits/stdc++.h>
using namespace std;

// maths

struct Point {
	double x, y, z; 
	Point (int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

int dot_product(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

// O is original point
// A is one point, B is other point
// Vectors start from O

int dot_product(Point O, Point A, Point B) {
	return (A.x - O.x) * (B.x - O.x) + (A.y - O.y) * (B.y - O.y);
}

// Return the size

int cross_product(Point A, Point B, Point C) {
	return (B.x-A.x)*(C.y-A.y) - (C.x - A.x) * (B.y-A.y);
}

int ccw(Point A, Point B, Point C) {
	if ((B.x-A.x) * (C.y - A.y) > (C.x - A.x) * (B.y - A.y)) {
		return 1;
	} else {
		return -1;
	}
}

int main() {
	Point A = Point(2, 2), B = Point(3, 3), Point(4, 4.1);
	if (cross_product(A, B, C) == 0) {
		puts("YES\n");
	}
	
	return 0;
}
