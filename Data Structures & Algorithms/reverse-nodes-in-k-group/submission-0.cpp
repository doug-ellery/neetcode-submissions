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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int sz = 0;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next){
            sz++;
        }
        ListNode* curr = head;
        ListNode* prev_k = nullptr;
        for(int i = 0; i < sz / k; i++){
            ListNode* prev = nullptr;
            ListNode* start = curr;
            for(int j = 0; j < k; j++){
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            if(i == 0){
                head = prev;
            }
            if(prev_k != nullptr){
                prev_k->next = prev;
            }
            prev_k = start;
        }
        if(curr != nullptr){
            prev_k->next = curr;
        }
        return head;
    }
};
