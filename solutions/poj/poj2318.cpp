#include <iostream>
#include <vector>

/*
 * POJ 2318
 */

int main() {
    while(true){
        int N, M, x1, y1, x2, y2;
        std::cin >> N;
        std::vector<std::pair<std::pair<int,int>, std::pair<int,int>>> partition;
        if(N == 0){
            break;
        }
        std::cin >> M >> x1 >> y1 >> x2 >> y2;
        for(int i = 0 ; i < N; i++){
            int n1, n2;
            std::cin >> n1 >> n2;
            partition.push_back(std::make_pair(std::make_pair(n1, y1), std::make_pair(n2, y2)));
        }
        int p[5000] = {0}; //WTH PEKING JUDGE WHY U NO DYNAMIC ALLOCATE
        for(int i = 0; i < M; i++){
            int x, y;
            std::cin >> x >> y;
            bool did = false;
            for(int j = 0; j < N; j++){
                bool yup = (((x - partition[j].first.first) * (partition[j].second.second - partition[j].first.second) - (y - partition[j].first.second) * (partition[j].second.first - partition[j].first.first)) > 0 && ((x1 - partition[j].first.first) * (partition[j].second.second - partition[j].first.second) - (y1 - partition[j].first.second) * (partition[j].second.first - partition[j].first.first)) > 0) || (((x - partition[j].first.first) * (partition[j].second.second - partition[j].first.second) - (y - partition[j].first.second) * (partition[j].second.first - partition[j].first.first)) < 0 && ((x1 - partition[j].first.first) * (partition[j].second.second - partition[j].first.second) - (y1 - partition[j].first.second) * (partition[j].second.first - partition[j].first.first)) < 0);
                if(yup){
                    p[j]++;
                    did = true;
                    break;
                }
            }
            if(!did){
                p[N]++;
            }
        }
        for(int i = 0; i <= N; i++){
            std::cout << i << ": " << p[i] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
