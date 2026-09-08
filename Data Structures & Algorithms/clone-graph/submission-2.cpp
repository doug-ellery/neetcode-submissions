/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){return nullptr;}
        unordered_map<Node*, Node*> old_to_new;
        queue<Node*> bfs_queue;
        bfs_queue.push(node);
        old_to_new[node] = new Node(node->val);
        while(!bfs_queue.empty()){
            Node* curr_node = bfs_queue.front();
            bfs_queue.pop();
            for(Node* child : curr_node->neighbors){
                if(!old_to_new.contains(child)){
                    old_to_new[child] = new Node(child->val);
                    bfs_queue.push(child);
                }
            }
        }
        bfs_queue.push(node);
        unordered_set<Node*> visited;
        visited.insert(node);
        while(!bfs_queue.empty()){
            Node* old_node = bfs_queue.front();
            Node* new_node = old_to_new[old_node];
            bfs_queue.pop();
            for(Node* child : old_node->neighbors){
                new_node->neighbors.push_back(old_to_new[child]);
                if(visited.find(child) == visited.end()){
                    bfs_queue.push(child);
                    visited.insert(child);
                }
            }
        }
        return old_to_new[node];
    }
};
