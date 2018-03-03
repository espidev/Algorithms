#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        int sum = 0;
        for(int j = 1; j <= num/2; j++) {
            if(num % j == 0) sum += j;
        }
        if(sum < num) {
            cout << num << " is a deficient number." << endl;
        }
        else if (sum == num) {
            cout << num << " is a perfect number." << endl;
        }
        else {
            cout << num << " is an abundant number." << endl;
        }
    }
    return 0;
}
