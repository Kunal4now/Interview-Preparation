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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_list = new ListNode(0);
        ListNode *ptr = head, *list_ptr = new_list;
        
        map<int, int> mp;
        while (ptr) {
            mp[ptr -> val]++;
            ptr = ptr -> next;
        }
        
        ptr = head;
        while (ptr) {
            if (mp[ptr -> val] == 1) {
                list_ptr -> next = new ListNode(ptr -> val);
                list_ptr = list_ptr -> next;
            }
            ptr = ptr -> next;
        }
        return new_list -> next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode *new_list = new ListNode(0);
        ListNode *ptr = head, *newPtr = new_list;
        int duplicate = 0;
        while (ptr && ptr -> next) {
            here:
            if (ptr -> val == ptr -> next -> val) {
                duplicate = ptr -> val;
                while (ptr && ptr -> val == duplicate) {
                    ptr = ptr -> next;
                }
            }
            if (ptr && ptr -> next) {
                if (ptr -> val == ptr -> next -> val) {
                    goto here;
                }
            }
            newPtr -> next = ptr;
            newPtr = newPtr -> next;
            if (ptr) {
                ptr = ptr -> next;
            }
        }
        return new_list -> next;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
