#include <bits/stdc++.h> 

struct Node {
    Node *links[26];
    bool flag = false;
    int cnt = 0;
    int prefixCnt = 0;
};

class Trie{
    private:
    Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for (char ch: word) {
            if (node -> links[ch - 'a'] == NULL) {
                node -> links[ch - 'a'] = new Node();
            }
            node = node -> links[ch - 'a'];
            node -> prefixCnt++;
        }

        node -> flag = true;
        node -> cnt++;
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for (char ch: word) {
            if (node -> links[ch - 'a'] != NULL) {
                node = node -> links[ch - 'a'];
            } else {
                return 0;
            }
        }

        return node -> cnt;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for (char ch : word) {
            if (node -> links[ch - 'a'] != NULL) {
                node = node -> links[ch - 'a'];
            } else {
                return 0;
            }
        }

        return node -> prefixCnt;
    }

    void erase(string &word){
        Node *node = root;
        for (char ch: word) {
            if (node -> links[ch - 'a'] != NULL) {
                node = node -> links[ch - 'a'];
                node -> prefixCnt--;
            } else {
                return;
            }
        }
        node -> cnt--;
    }
};

// https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM
