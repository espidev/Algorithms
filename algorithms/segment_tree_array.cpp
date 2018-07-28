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

void create_tree(int index, int begin_index , int end_index) {
	if (end_index - begin_index < 2) { // reached bottom of tree, fill in with input value
		arr[index] = input[begin_index];
		return;
	}
	int mid = (begin_index + end_index) / 2;
	create_tree(2 * index + 1, begin_index, mid);
	create_tree(2 * index + 2, mid, end_index);
	arr[index] = arr[index * 2 + 1] + arr[index * 2 + 2];
}

// recursively go down binary tree and add together the stored sums

int find_sum_for_range_util(int b_index, int e_index, int query_b, int query_e, int index) {
	if (query_b <= b_index && e_index <= query_e) //if the segment is completely inside the required query
		return arr[index];

	if (e_index < query_b || query_e < b_index) // if the segment completely outside of the required query
		return 0;

	int mid = (b_index + e_index) /2;
	return find_sum_for_range_util(b_index, mid, query_b, query_e, 2 * index + 1) + find_sum_for_range_util(mid+1, e_index, query_b, query_e, 2 * index + 2);
}

// utility to find the sum for the range of indexes

int find_sum_for_range(int b, int e) {
	return find_sum_for_range_util(0, N-1, b, e, 0);
}

// recursively go down tree checking if the index is

void update_value_util(int diff, int u_index, int b_index, int e_index, int index) {
	if (u_index < b_index || u_index > e_index) return; // if the segment does not contain node return
	arr[index] -= diff; // update value

	if (b_index != e_index) {
		int mid = (b_index + e_index) / 2;
		update_value_util(diff, u_index, b_index, mid, 2 * index + 1);
		update_value_util(diff, u_index, mid + 1, e_index, 2 * index + 2);
	}
}

// update value at input index with new value

void update_value(int index, int val) {
	int diff = input[index] - val;
	update_value_util(diff, index, 0, N-1, 0);
}

int main() {
	// example usage

	N = 8; // size of array
	arr = new int[2 * N - 1];
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

	create_tree(0, 0, N); // fill segment tree with the input

	for (int i = 0; i < 2 * N - 1; i++) printf("%d\n", arr[i]);

	printf("0 - 4: %d\n", find_sum_for_range(0, 4)); //find the sum of the range of values from 0 - 4

	printf("Update index 0 from 5 to 10.\n");

	update_value(0, 10); // updated index 0 to be 10

	for (int i = 0; i < 2 * N - 1; i++) printf("%d\n", arr[i]);

	return 0;
}

