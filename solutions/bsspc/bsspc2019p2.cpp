#include <bits/stdc++.h>
using namespace std;

int X, Y, N;
string arr[101][101];

int main() {
    cin >> X >> Y >> N;

    for (int i = 0; i < X; i++) for (int j = 0; j < Y; j++) arr[j][i] = " ";

    // obtain input (draw)
    for (int i = 0; i < N; i++) {
        int x, y;
        string c;
        cin >> x >> y >> c;
        arr[y][x] = c;
    }   

    // print (display canvas)
    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }   
    return 0;
}
