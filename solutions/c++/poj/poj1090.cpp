#include <vector>
#include <map>
#include <iostream>

/*
 * POJ 1090 - Chain
 */

std::map<int, int> mp;
std::vector<int> l;

void initMap(int upTo){
    for(int i = 0; i < upTo; i++){
        if(i == 0){
            mp.insert(std::make_pair(0, 1));
            continue;
        }
        else{
            mp.insert(std::make_pair(i, 2 * mp.find(i-1)->second + 1));
        }
    }
}

int firstFlip(int it){
    int ret = 0;
    bool found = false;
    for(int i = 0; i < it; i++){
        if(found){
            l[i-1] = 0;
            ret++;
            if(l[i+1] != 1) {
                l[i + 1] = 1;
                ret++;
            }
        }
        else if(l[it] == 1){
            found = true;
            l[i+1] = 1;
            ret++;
        }
    }
    l[it] = 0;
    //ret++;
    //std::cout << mp.find(it-1)-> second << " " << ret << std::endl;
    int a = 0;
    for(int i = it-1; i > -1; i--){
        a += mp.find(i)->second;
    }
    return ret + a;
}

int main() {
    int N, latestOn = -1, numOfOnes = 0;
    std::cin >> N;
    for(int i = 0; i < N; i++){
        int n;
        std::cin >> n;
        l.push_back(n);
        if(l[i] == 1){
            latestOn = i;
            numOfOnes++;
        }
    }
    if(latestOn == -1){
        std::cout << 0;
        return 0;
    }
    int ans = 0;
    initMap(N);
    ans = firstFlip(latestOn);
    std::cout << ans;
    return 0;
}
