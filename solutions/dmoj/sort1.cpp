int N;

/*
 * DMOJ Solution
 * https://dmoj.ca/problem/sort1
 */

int main() {
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        for (int k = 0; k < N; k++) {
                cout << arr[k] << ((k == N-1) ? "" : " ");
        }
        cout << endl;
        for (int i = 0; i < N-1; i++) {
                for(int j = 1; j < N; j++) {
                        if(arr[j-1] > arr[j]) {
                                int temp = arr[j-1];
                                arr[j-1] = arr[j];
                                arr[j] = temp;
                                for (int k = 0; k < N; k++) {
                                        cout << arr[k] << ((k == N-1) ? "" : " ");
                                }
                                cout << endl;
                        }
                }
        }
}
