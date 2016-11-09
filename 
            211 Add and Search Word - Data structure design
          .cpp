class WordDictionary {
public:
    WordDictionary() : root(new TrieNode()) {
        
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        auto now = root;
        for (auto c : word) {
            if (!now->child.count(c)) {
                now->child[c] = shared_ptr<TrieNode>(new TrieNode());
            }
            now = now->child[c];
        }
        now->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        function<bool(shared_ptr<TrieNode>, int)> search = [&] (shared_ptr<TrieNode> now, int index) {
            if (index == word.size()) {
                return now->flag;
            }  
            if (word[index] == '.') {
                for (auto &it : now->child) {
                    if (search(it.second, index + 1)) {
                        return true;
                    }
                }
                return false;
            } else {
                char ch = word[index];
                return now->child.count(ch) && search(now->child[ch], index + 1);
            }
        };
        return search(root, 0);
    }
private:
    struct TrieNode {
        unordered_map<char, shared_ptr<TrieNode>> child;
        bool flag;
    };
    shared_ptr<TrieNode> root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
