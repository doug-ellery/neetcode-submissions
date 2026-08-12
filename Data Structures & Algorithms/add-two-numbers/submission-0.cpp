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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = nullptr, *curr = nullptr;
        ListNode* curr_1 = l1, *curr_2 = l2;
        int carry = 0;
        while(curr_1 != nullptr && curr_2 != nullptr){
            int temp = curr_1->val + curr_2->val + carry;
            if(out == nullptr){
                carry = temp / 10;
                out = new ListNode(temp % 10);
                curr = out;
            }
            else{
                carry = temp / 10;
                curr->next = new ListNode(temp % 10);
                curr = curr->next;
            }
            curr_1 = curr_1->next;
            curr_2 = curr_2->next;
        }
        while(curr_1 != nullptr){
            int temp = curr_1->val + carry;
            carry = temp / 10;
            curr->next = new ListNode(temp % 10);
            curr = curr->next;
            curr_1 = curr_1->next;
        }
        while(curr_2 != nullptr){
            int temp = curr_2->val + carry;
            carry = temp / 10;
            curr->next = new ListNode(temp % 10);
            curr = curr->next;
            curr_2 = curr_2->next;
        }
        if(carry != 0){
            curr->next = new ListNode(carry);
        }
        return out;
    }
};
