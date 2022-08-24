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
class Solution {
public:
    int findLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL or head -> next == NULL or k == 0) {
            return head;
        }
        
        int n = findLength(head);
        int shift = n - k % n;
        ListNode *ptr = head, *l = NULL, *r = NULL;
        
        for (int i = 0; i < shift - 1; i++) {
            ptr = ptr -> next;
        }
        
        l = ptr, r = ptr -> next;
        l -> next = NULL;
        ListNode *beg = r;
        
        if (r == NULL) {
            return head;
        }
        
        while (r -> next != NULL) {
            r = r -> next;
        }
        
        r -> next = head;
        head = beg;
        return head;
    }
};

/*
APPROACH:
=> Find the total length of linked list n
=> n - k % n will give you the last node which need to be cut off and its next node will contain the start of linked list
  e.g. [1, 2, 3, 4, 5]
       k = 2
       Now, n - k % n will be 3, so this node will be the starting of new linked list
       [1, 2, 3] [4, 5]
       Now we just need to connect the last node with the head node
       [4, 5] -> [1, 2, 3] 
       This will be our final answer
*/

/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
