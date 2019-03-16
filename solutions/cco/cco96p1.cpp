#include <bits/stdc++.h>
using namespace std;
int N, K;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        int arr[K], swaps = 0;
        for (int j = 0; j < K; j++) {
            cin >> arr[j];
        }
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swaps++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }
    return 0;
}
