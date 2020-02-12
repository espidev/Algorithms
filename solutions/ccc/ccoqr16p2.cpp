using namespace std;

struct yv {
    int smallest = 1e9, biggest = -1e9;
    set<int> v;
    unordered_map<int, int> m;
    yv() {
        v = set<int>();
    }
    void ins(int n) {
        if (n < smallest) smallest = n;
        if (n > biggest) biggest = n;
        v.insert(n);
    }
    void calc() {
        int i = 0;
        for (int k : v) {
            m[k] = i;
            i++;
        }
    }
};

int N;
long long ans = 0;
unordered_map<int, set<int>> xs;
unordered_map<int, yv> ys;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        xs[x].insert(y);
        ys[y].ins(x);
    }

    for (auto& s : ys) {
        s.second.calc();
    }

    for (pair<int, set<int>> p : xs) {
        int i = -1;
        if (p.second.size() < 3) continue;
        for (int y : p.second) {
            i++;
            if (i == 0 || i == p.second.size()-1) continue;
            if (ys[y].v.size() < 3) continue;
            if (ys[y].biggest == p.first || ys[y].smallest == p.first) continue;
            ans += i*(p.second.size()-1-i)*
                    (ys[y].m[p.first])*
                    (ys[y].v.size()-1-ys[y].m[p.first]);
        }
    }
    cout << (ans*2) << endl;
    return 0;
}
