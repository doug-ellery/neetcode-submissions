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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        int n = 0;
        ListNode* curr = head;
        while(curr != nullptr){
            nodes.push_back(curr);
            n++;
            curr = curr->next;
        }
        curr = nullptr;
        for(int i = 0; i < n / 2; i++){
            int r = n - 1 - i;
            if(i == 0){
                curr = nodes[i];
                curr->next = nodes[r];
                curr = nodes[r];
            }
            else{
                curr->next = nodes[i];
                nodes[i]->next = nodes[r];
                curr = nodes[r];
            }
        }
        if(n % 2 != 0 && n > 1){
            curr->next = nodes[n / 2];
            nodes[n/2]->next = nullptr;
        }
        else if(n % 2 == 0){
            curr->next = nullptr;
        }
    }
};
