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
        if(head == nullptr){return nullptr;}
        unordered_map<Node*, Node*> og_to_copy;
        Node* curr = head;
        while(curr != nullptr){
            og_to_copy[curr] = new Node(curr->val);
            curr = curr->next;
        }
        Node* cp_head = og_to_copy[head];
        cp_head->next = og_to_copy[head->next];
        cp_head->random = og_to_copy[head->random];
        curr = head->next;
        Node* cp_curr = cp_head->next;
        while(curr != nullptr){
            cp_curr->next = og_to_copy[curr->next];
            cp_curr->random = og_to_copy[curr->random];
            cp_curr = cp_curr->next;
            curr = curr->next;
        }
        return cp_head;
    }
};
