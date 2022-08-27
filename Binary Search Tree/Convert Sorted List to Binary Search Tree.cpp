/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode *findMid(ListNode *head, ListNode *tail) {
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while (fast != tail and fast -> next != tail) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head, ListNode *tail = NULL) {
        if (head == tail) {
            return NULL;
        }
        
        ListNode *mid = findMid(head, tail);
        ListNode *l = head;
        ListNode *r = mid -> next;
        
        TreeNode *root = new TreeNode(mid -> val);
        root -> left = sortedListToBST(l, mid);
        root -> right = sortedListToBST(r, tail);
        return root;
    }
};

/*
APPROACH:
=> Similar to the sort linked list process
*/
