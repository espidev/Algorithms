#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

// Example of prefix sum
// Easy and fast way to get the sum of multiple values in an array

int num[MAXN], sums[MAXN];

// generate prefix sum (one time needed)
void gen_prefix_sum(int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += num[i];
        sums[i] = sum;
    }
}

// query sum of range of numbers
int query_prefix_sum(int begin, int end) {
    if (begin == 0) return sums[end];
    return sums[end]-sums[begin-1];
}

int main() {
    // set numbers
    for (int i = 0; i < 10; i++) num[i] = i;
    gen_prefix_sum(10);

    printf("%d\n", query_prefix_sum(2, 4));
}