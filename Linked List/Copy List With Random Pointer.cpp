/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ptr = head;

        unordered_map<Node*, Node*> mp;
        while (ptr != NULL) {
           Node *copy = new Node(ptr -> val);
           mp[ptr] = copy;
           ptr = ptr -> next;
        }

        ptr = head;
        while (ptr != nullptr) {
            mp[ptr] -> next = mp[ptr -> next];
            mp[ptr] -> random = mp[ptr -> random];
            ptr = ptr -> next;
        }   
        return mp[head];   
    }
};

/*
APPROACH:
We can map the actual node with its copy
a -> b -> c
a' -> b' -> c'

mp[a] should give a'
mp[b] should give b'

now we just need to create the links of the copied nodes

if mp[a] give a' 
mp[a -> next] will give b'

so we can create normal links as mp[a] -> next = mp[a -> next]

similarly we can create random links
*/
