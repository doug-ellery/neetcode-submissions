class Solution {
public:
    struct Node{
        int val;
        bool visited;
        unordered_set<int> neighbors;
        Node(int v) : val(v){
            visited = false;
            neighbors = {};
        }
    };
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){return false;}
        unordered_map<int, Node*> all_nodes;
        for(unsigned int i = 0; i < n; i++){
            all_nodes[i] = new Node(i);
        }
        for(vector<int> edge : edges){
            all_nodes[edge[0]]->neighbors.insert(edge[1]);
            all_nodes[edge[1]]->neighbors.insert(edge[0]);
        }
        queue<Node*> bfs_queue;
        bfs_queue.push(all_nodes[0]);
        all_nodes[0]->visited = true;
        while(!bfs_queue.empty()){
            Node* node = bfs_queue.front();
            bfs_queue.pop();
            for(const auto& neighbor : node->neighbors){
                if(!all_nodes[neighbor]->visited){
                    bfs_queue.push(all_nodes[neighbor]);
                    all_nodes[neighbor]->visited = true;
                }
            }
        }
        for(unsigned int i = 0; i < n; i++){
            if(!all_nodes[i]->visited){return false;}
        }
        return true;
    }
};
