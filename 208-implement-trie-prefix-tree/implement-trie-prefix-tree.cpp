const int ALPHABET_SIZE = 'z' - 'a' + 1;

class TrieNode {
public:
    bool isWord;
    TrieNode* children[ALPHABET_SIZE];

    TrieNode() {
        isWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == nullptr) cur->children[idx] = new TrieNode();

            cur = cur->children[idx];
        } 

        cur->isWord = true;
    }
    
    bool search(string word){
        TrieNode* nd = find(word);
        return nd != nullptr && nd->isWord;
    }
    
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }

    TrieNode* find(string word) {
      TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++) {
            int idx = word[i] - 'a';
            if (cur->children[idx] == nullptr) return nullptr;

            cur = cur->children[idx];
        } 

      return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */