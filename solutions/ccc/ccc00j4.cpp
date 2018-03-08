#include <bits/stdc++.h>

using namespace std;

/*
 * CCC00J4 not completed
 * Partial marks
 */

int N;
vector<pair<int, double>> streams;

int main() {
    cin >> N;
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        streams.emplace_back(i, a);
    }
    int in;
    while (true) {
        cin >> in;
        int stream;
        if (in == 77) break;
        else if (in == 99) { //split
            int leftFlow;
            cin >> stream >> leftFlow;
            streams.emplace_back(stream, streams[stream - 1].second * ((double) (100 - leftFlow) / 100));
            sort(streams.begin(), streams.end());
            streams[stream - 1].second *= (double) (leftFlow) / 100;
            for (int i = stream + 1; i < streams.size(); i++) {
                streams[i].first++;
            }
        } else if (in == 88) { //join
            cin >> stream;
            sort(streams.begin(), streams.end());
            streams[stream - 1].second += streams[stream].second;
            streams.erase(streams.begin() + stream);
            for (int i = stream; i < streams.size(); i++) {
                if (streams[i].first > stream) streams[i].first--;
            }
        }
    }
    sort(streams.begin(), streams.end());
    for (auto &stream : streams) {
        cout << round(stream.second) << " ";
    }
    return 0;
}
