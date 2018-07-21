#include <bits/stdc++.h>
using namespace std;

/*
 * Segment tree with array
 *
 * Find sum for certain range in array in Olog(n)
 * NOT COMPLETED
 */

#define MAXN 100000

int N;
int *arr, *input;

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

int find_sum_for_range(int begin_index, int end_index, int query_begin, int query_end, int index) {
	if (query_begin >= begin_index && query_end >= end_index)
		return arr[index];
	if (begin_index < query_begin || query_end > end_index)
		return 0;
	int mid = (begin_index + end_index) /2;
	return find_sum_for_range(begin_index, mid, query_begin, query_end, 2 * index + 1) + find_sum_for_range(mid+1, end_index, query_begin, query_end, 2 * index + 2);
}

pair<int, int> get_child_index(int index) {
	return make_pair(2 * index + 1, 2 * index + 2);
}

int main() {
	N = 8;
	arr = new int[N];
	input = new int[N];
	input[0] = 5;
	input[1] = 8;
	input[2] = 6;
	input[3] = 5;
	input[4] = 2;
	input[5] = 7;
	input[6] = 2;
	input[7] = 6;
	create_tree(0, 0, N);
	for (int i = 0; i < 2 * N - 1; i++) printf("%d\n", arr[i]);
	printf("0 - 2: %d\n", find_sum_for_range(0, N, 0, 2, 0));
	return 0;
}

