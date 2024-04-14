struct Node {
    Node *links[26];
    bool flag = false;
};

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        // We need to traverse over the word and insert them into their respective positions in the node
        for (char ch: word) {
            if (node -> links[ch - 'a'] == NULL) {
                node -> links[ch - 'a'] = new Node();
            }
            node = node -> links[ch - 'a'];
        }
        node -> flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (char ch: word) {
            if (node -> links[ch - 'a'] != NULL) {
                node = node -> links[ch - 'a'];
            } else {
                return false;
            }
        }

        if (node != NULL && node -> flag == true) {
            return true;
        }

        return false;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (char ch: prefix) {
            if (node -> links[ch - 'a'] != NULL) {
                node = node -> links[ch - 'a'];
            } else {
                return false;
            }
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
