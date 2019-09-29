#include <bits/stdc++.h>
using namespace std;

/*
 * Segment tree with array
 *
 * Find sum for certain range in array in O(nlogn)
 * Update value and range of values (using lazy propagation) in O(nlogn)
 */

#define MAXN 100000

int N;
int *arr, *input, *lazy;

// recursively fill tree bottom - up with values from input array

/*
 * i = arr[] index
 * bi = begin index range currently
 * ei = end index range currently
 */

void create_tree(int i, int bi , int ei) { // caveat: the index of the tree starts at 1
	if (ei == bi) { // reached bottom of tree, fill in with input value
		arr[i] = input[bi];
		return;
	}
	int mid = (bi + ei) / 2;
	create_tree(2 * i, bi, mid);
	create_tree(2 * i + 1, mid+1, ei);
	arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void push_down_lazy(int index, int bi, int ei) {
	arr[index] += lazy[index] * (ei-bi);
	if (index < N) {
		lazy[index*2] += lazy[index] * (ei-bi); // adding sums of all values
		lazy[index*2+1] += lazy[index] * (ei-bi);
	}
	lazy[index] = 0;
}

// recursively go down binary tree and add together the stored sums

/*
 * bi = begin index (left)
 * ei = end index (right)
 * qb = query begin
 * qe = query end
 * i = arr[] index
 */

int query_u(int bi, int ei, int qb, int qe, int i) {
	push_down_lazy(i, bi, ei);
	if (qb <= bi && ei <= qe) return arr[i]; //if the segment is completely inside the required query, return it
	if (ei < qb || qe < bi) return 0; // if the segment completely outside of the required query, ignore it
	int mid = (bi + ei) / 2; 
	return query_u(bi, mid, qb, qe, 2 * i) + query_u(mid+1, ei, qb, qe, 2 * i + 1); // if part of the segment is in the query, go down the tree
}

// recursively go down tree checking if the index is

/*
 * change = value to change to
 * ui = index to update
 * bi = begin index (left)
 * ei = end index (right)
 * i = arr[] index
 */

void update_u(int change, int ui, int bi, int ei, int i) {
    if (bi == ei) {
        if (bi == i) arr[i] = change;
        return;
    }
	int mid = (bi+ei)/2;
	if (ui > mid) update_u(diff, ui, mid+1, ei, i*2+1);
	else update_u(diff, ui, bi, mid, i*2);
    arr[i] = arr[i*2] + arr[i*2+1];
}

// range update
// TODO test implementation

void range_update(int change, int bi, int ei, int qb, int qe, int i) {
	if (lazy[i]) change += lazy[i];
	if (ei < qb || bi > qe) return;
	lazy[i] = change;
	if (bi >= qb && ei <= qe) return;
	push_down_lazy(i, bi, ei);
	int mid = (bi + ei) / 2;
	range_update(change, bi, mid, qb, qe, i*2);
	range_update(change, mid+1, ei, qb, qe, i*2+1);
}

int main() {
	// example usage

	N = 8; // size of array
	arr = new int[2 * N]; // init array
    	lazy = new int[2 * N];
	input = new int[N];

	// populate input array with values

	input[0] = 5;
	input[1] = 8;
	input[2] = 6;
	input[3] = 5;
	input[4] = 2;
	input[5] = 7;
	input[6] = 2;
	input[7] = 6;

	create_tree(1, 0, N-1); // fill segment tree with the input

	for (int i = 1; i < 2 * N; i++) printf("%d\n", arr[i]);

	printf("0 - 4: %d\n", query_u(0, N-1, 0, 4, 1)); //find the sum of the range of values from 0 - 4

	printf("Update index 0 from 5 to 10.\n");

	update_u(10, 0-1, 1, N-1, 1); // updated index 0 to be 10

	for (int i = 1; i < 2 * N - 1; i++) printf("%d\n", arr[i]);

	return 0;
}

