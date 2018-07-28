#include <bits/stdc++.h>
using namespace std;

/*
 * Segment tree with array
 *
 * Find sum for certain range in array in Olog(n)
 * 
 */

#define MAXN 100000

int N;
int *arr, *input;

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

// recursively go down binary tree and add together the stored sums

/*
 * bi = begin index (left)
 * ei = end index (right)
 * qb = query begin
 * qe = query end
 * i = arr[] index
 */

int query_u(int bi, int ei, int qb, int qe, int i) {
	if (qb <= bi && ei <= qe) return arr[i]; //if the segment is completely inside the required query, return it
	if (ei < qb || qe < bi) return 0; // if the segment completely outside of the required query, ignore it
	int mid = (bi + ei) / 2; 
	return query_u(bi, mid, qb, qe, 2 * i) + query_u(mid+1, ei, qb, qe, 2 * i + 1); // if part of the segment is in the query, go down the tree
}

// utility to find the sum for the range of indexes

/*
 * b = beginning index to query
 * e = end index to query (including itself)
 */

int query_range(int b, int e) {
	return query_u(0, N-1, b, e, 1);
}

// recursively go down tree checking if the index is

/*
 * diff = difference to subtract by
 * ui = index to update
 * bi = begin index (left)
 * ei = end index (right)
 * i = arr[] index
 */

void update_u(int diff, int ui, int bi, int ei, int i) {
	arr[i] -= diff; // update value with new difference
	if (bi == ei) return; // if the segment does not contain node return
	
	int mid = (bi+ei)/2;
	if (ui > mid) update_u(diff, ui, mid+1, ei, i*2+1);
	else update_u(diff, ui, bi, mid, i*2);
}

// utility to update value at input index with new value

/*
 * index = index of original array to update
 * val = value to update it to
 */

void update_value(int index, int val) {
	int diff = input[index] - val;
	update_u(diff, index-1, 1, N-1, 1);
	input[index] -= diff;
}


int main() {
	// example usage

	N = 8; // size of array
	arr = new int[2 * N]; // ignore
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

	printf("0 - 4: %d\n", query_range(0, 4)); //find the sum of the range of values from 0 - 4

	printf("Update index 0 from 5 to 10.\n");

	update_value(0, 10); // updated index 0 to be 10

	for (int i = 1; i < 2 * N - 1; i++) printf("%d\n", arr[i]);

	return 0;
}

