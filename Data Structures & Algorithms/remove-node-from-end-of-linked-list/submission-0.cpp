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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            sz++;
            curr = curr->next;
        }
        curr = head;
        ListNode* prev = nullptr;
        for(int i = 0; i < sz - n; i++){
            prev = curr;
            curr = curr->next;
        }
        if(prev == nullptr){
            return curr->next;
        }
        prev->next = curr->next;
        return head;
    }
};
