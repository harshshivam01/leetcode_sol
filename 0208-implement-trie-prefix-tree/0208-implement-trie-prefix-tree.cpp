struct node {
    node* child[26];
    bool isEnd = false;
    node() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};
class Trie {
    node* root;

public:
    Trie() { root = new node() ;}

    void insert(string word) {
        node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';
            if (curr->child[j] == NULL) {
                curr->child[j] = new node();
            }
            curr = curr->child[j];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            int j = word[i] - 'a';
            if (curr->child[j] == NULL)
                return false;
            curr = curr->child[j];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            int j = prefix[i] - 'a';
            if (curr->child[j] == NULL)
                return false;
            curr = curr->child[j];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */