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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curr_ptrs;
        for(ListNode* ptr : lists){
            curr_ptrs.push_back(ptr);
        }
        ListNode* head = nullptr;
        ListNode* last_added = nullptr;
        bool valid = true;
        struct Compare{
            bool operator()(pair<int, int> a, pair<int, int> b){
                return a.first > b.first;
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> min_heap;
        for(int i = 0; i < curr_ptrs.size(); i++){
            if(curr_ptrs[i] != nullptr){
                min_heap.push({curr_ptrs[i]->val, i});
            }
        }
        while(true){
            if(min_heap.empty()){break;}
            int min_idx = min_heap.top().second;
            min_heap.pop();
            if(head == nullptr){
                head = curr_ptrs[min_idx];
                last_added = head;
                curr_ptrs[min_idx] = curr_ptrs[min_idx]->next;
            }
            else{
                last_added->next = curr_ptrs[min_idx];
                curr_ptrs[min_idx] = curr_ptrs[min_idx]->next;
                last_added = last_added->next;
            }
            if(curr_ptrs[min_idx] != nullptr){
                 min_heap.push({curr_ptrs[min_idx]->val, min_idx});   
            }
        }
        return head;
    }
};
