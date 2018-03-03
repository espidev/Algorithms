#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    int t, h1 = 1, h2 = 2, m1 = 0, m2 = 0, c = 0;
    cin >> t;
    if(t > 1339){
        c = (int)floor(t/1440) * 62;
        t = t - (int)floor(t/1440) * 1440;
    }
    for(int i = 0; i <= t; i++){
        for(int j = -6; j < 6; j++){
            if(h1 != 0){
                if((h2 - h1 == j && m1 - h2 == j && m2 - m1 == j)){
                    //cout << h1 << h2 << ":" << m1 << m2 << endl;
                    c++;
                }
            }
            else{
                if((m1 - h2 == j && m2 - m1 == j)){
                    //cout << h1 << h2 << ":" << m1 << m2 << "l" << endl;
                    c++;
                }
            }
        }
        if(m2 == 9){
            if(m1 == 5){
                if(h2 == 9){
                    m1 = 0;
                    m2 = 0;
                    h2 = 0;
                    h1 = 1;
                }
                else if(h2 == 2){
                    if(h1 == 1){
                        h1 = 0;
                        h2 = 1;
                        m1 = 0;
                        m2 = 0;
                    }
                    else{
                        m1 = 0;
                        m2 = 0;
                        h2++;
                    }
                }
                else{
                    m1 = 0;
                    m2 = 0;
                    h2++;
                }
            }
            else{
                m1++;
                m2 = 0;
            }
        }
        else{
            m2++;
        }
    }
    cout << c;
    return 0;
}
