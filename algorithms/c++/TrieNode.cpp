struct TrieNode {
    map<char, TrieNode> m;

    void insert(string str) {
        if(str.length() == 0) return;
        if(m.find(str[0]) == m.end()) {
            m.insert({str[0], TrieNode()});
        }
        m.find(str[0])->second.insert(str.substr(1));
    }

    bool query(string str) {
        if(str.length() == 0) return true;
        if(m.find(str[0]) != m.end()) return m.find(str[0])->second.query(str.substr(1));
        return false;
    }
};
