
// fast hash pair for unordered_map

struct hashing {
    size_t operator()(const pair<int, int>& l) const {
        return hash<long long>()(((long long)l.first )* ((long long)INT_MAX + 1) + l.second);
    }
};

unordered_map<pair<int, int>, ull, hashing> ma;

