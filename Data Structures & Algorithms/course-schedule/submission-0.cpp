class Solution {
public:
    struct Node{
        int val;
        int in_degree;
        unordered_set<int> children;
        Node(int v) : val(v){
            in_degree = 0;
            children = {};
        }
    };
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, Node*> graph_nodes;
        for(unsigned int i = 0; i < numCourses; i++){
            graph_nodes[i] = new Node(i);
        }
        for(auto& group : prerequisites){
            graph_nodes[group[0]]->children.insert(group[1]);
            graph_nodes[group[1]]->in_degree++;
        }
        queue<Node*> topo_queue;
        for(const auto& [course, node] : graph_nodes){
            if(node->in_degree == 0){
                topo_queue.push(node);
            }
        }
        while(!topo_queue.empty()){
            Node* node = topo_queue.front();
            topo_queue.pop();
            for(int course : node->children){
                Node* child = graph_nodes[course];
                if(--child->in_degree <= 0){
                    topo_queue.push(child);
                }
            }
        }
        for(const auto& [course, node] : graph_nodes){
            if(node->in_degree > 0){
                return false;
            }
        }
        return true;
    }
};
