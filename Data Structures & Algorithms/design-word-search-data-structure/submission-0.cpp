struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};
class WordDictionary {
   public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->children.count(c) == 0) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    bool search(string word) { return dfs(0, root, word); }

    bool dfs(int i, TrieNode* node, string& word) {
        if (i == word.size()) {
            return node->isEnd;
        }
        char c = word[i];
        if (c == '.') {
            for (auto p : node->children) {
                if (dfs(i + 1, p.second, word)) {
                    return true;
                }
            }
            return false;
        }
        if (node->children.count(c) == 0) {
            return false;
        }
        return dfs(i + 1, node->children[c], word);
    }
};