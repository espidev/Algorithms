#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    int N;
    cin >> N;
    int ar1[N], ar2[N];
    for(int i = 0; i < N; i++){ //SWIFT
        int in;
        cin >> in;
        ar1[i] = in;
    }
    for(int i = 0; i < N; i++){ //SEMAPHORES
        int in;
        cin >> in;
        ar2[i] = in;
    }
    int s1 = 0, s2 = 0, counter = 0;
    for(int i = 0; i < N; i++){
        s1 += ar1[i];
        s2 += ar2[i];
        if(s1 == s2){
            counter = i+1;
        }
    }
    cout << counter;
    return 0;
}