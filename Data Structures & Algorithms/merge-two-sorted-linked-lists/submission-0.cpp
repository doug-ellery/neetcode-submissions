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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* curr = head;
        ListNode* node_1 = list1, *node_2 = list2;
        while(node_1 != nullptr && node_2 != nullptr){
            bool use_node_1 = node_1->val < node_2->val;
            if(head == nullptr){
                if(use_node_1){
                    head = node_1;
                    node_1 = node_1->next;
                    curr = head;
                }
                else{
                    head = node_2;
                    node_2 = node_2->next;
                    curr = head;
                }
            }
            else{
                if(use_node_1){
                    curr->next = node_1;
                    node_1 = node_1->next;
                    curr = curr->next;
                }
                else{
                    curr->next = node_2;
                    node_2 = node_2->next;
                    curr = curr->next;
                }
            }
        }
        while(node_1 != nullptr){
            if(curr == nullptr){
                head = node_1;
                node_1 = node_1->next;
                curr = head;
            }
            else{
                curr->next = node_1;
                node_1 = node_1->next;
                curr = curr->next;
            }
        }
        while(node_2 != nullptr){
            if(curr == nullptr){
                head = node_2;
                node_2 = node_2->next;
                curr = head;
            }
            else{
                curr->next = node_2;
                node_2 = node_2->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
